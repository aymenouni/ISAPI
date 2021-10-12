#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<string.h>
#include "CLibCurl.h"

char * G_pcHttpsReceivedData;
int32_t G_iHttpsReceivedDataLen;
int32_t * piRetAnswerLen;
using namespace std;


CLibCurl::CLibCurl()
{
	 G_pcHttpsReceivedData =NULL;
	 G_iHttpsReceivedDataLen=-1;
}


CLibCurl::~CLibCurl()
{
	
	if (G_iHttpsReceivedDataLen >= 0 && G_pcHttpsReceivedData)
		free(G_pcHttpsReceivedData);

}


void CLibCurl::ClearReceivedData()
{ 
	if (G_iHttpsReceivedDataLen > 0 && G_pcHttpsReceivedData)
	{
		G_iHttpsReceivedDataLen = -1;
		free(G_pcHttpsReceivedData);
		G_pcHttpsReceivedData = NULL;
	}
	else if (G_iHttpsReceivedDataLen >= 0 || G_pcHttpsReceivedData)
	{
		G_iHttpsReceivedDataLen = -1;
		G_pcHttpsReceivedData = NULL;
	}
}



size_t CLibCurl::writedata(void *ptr, size_t size, size_t nmemb)
{

	size_t realsize = size * nmemb;
	if (realsize>0)
	{
		ClearReceivedData();
		G_iHttpsReceivedDataLen=realsize;
		G_pcHttpsReceivedData = (char*)realloc(G_pcHttpsReceivedData,(G_iHttpsReceivedDataLen + 1) * sizeof(char));
		if (! G_pcHttpsReceivedData)
		{
			G_iHttpsReceivedDataLen = 0;
			printf("Could not allocate memory for HttpsReceivedData");
		}
		else
		{
			memcpy(G_pcHttpsReceivedData, ptr, G_iHttpsReceivedDataLen);
			G_pcHttpsReceivedData[G_iHttpsReceivedDataLen]=0;
			printf("-------------------result----------------------------GET = %s\n\n\n",G_pcHttpsReceivedData);
		}
	}
	return size * nmemb;
}
//the function return the content of G_pcHttpsReceivedData for use in curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write_Data);
size_t Write_Data(void *ptr, size_t size, size_t nmemb, CLibCurl * CLibCurl)
{
	if (CLibCurl)
		return CLibCurl->writedata(ptr, size, nmemb);

	return 0;
}


bool CLibCurl::GET_Data(char * pcIpCamera ,char * pcUrl,  int32_t iUrlLen,  char * pcAnswer,  char* pcRepStatus, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen,char* pcRetError, int32_t iTimeOutms)
{

CURL *curl;
CURLcode res;
char url_https[URL_MAX_LENGTH];
G_pcHttpsReceivedData = (char*)realloc(G_pcHttpsReceivedData,(G_iHttpsReceivedDataLen + 1) * sizeof(char));

snprintf(url_https,sizeof(url_https),"%s%s",pcIpCamera,pcUrl);
 /* get a curl handle */
curl = curl_easy_init();
if(curl) {
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
  curl_easy_setopt(curl, CURLOPT_URL,url_https);
 curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write_Data);
 curl_easy_setopt(curl, CURLOPT_TIMEOUT,iTimeOutms/1000);
  curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
   struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Authorization: Basic YWRtaW46QUNhM3Q1bHNw");
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  const char *data = "";
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
  res = curl_easy_perform(curl);
/* Check for errors */
if(CURLE_OK != res)
	{
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(res));
		strcpy(pcRetError,strerror(res));
		strcpy(pcRepStatus,"KO");
		strcpy(pcAnswer,"NO RESULT");
		
		return false;
		
		
	}
	else
	{
		printf("%s :  %s : %d ==>curl    succes \n", __FILE__,__FUNCTION__,__LINE__ );
		strcpy(pcRetError,"No Error");
		strcpy(pcRepStatus,"Ok");
		
		
	}

}
curl_easy_cleanup(curl);




if (!iAnswerMaxLen && ! pcAnswer )	//Perhaps we don't need the answer
	{
		
		if (piRetAnswerLen)
			*piRetAnswerLen = G_iHttpsReceivedDataLen;
	}
	else if  (iAnswerMaxLen && iAnswerMaxLen < G_iHttpsReceivedDataLen)
	{
		if (piRetAnswerLen)
			*piRetAnswerLen = 0;
		
		if(pcAnswer != NULL && iAnswerMaxLen > 0)
		{
			memset(pcAnswer,0,iAnswerMaxLen);
		}

	}


if (pcAnswer != NULL && iAnswerMaxLen > 0 && G_iHttpsReceivedDataLen > 0 )
	{
		memset(pcAnswer, 0, iAnswerMaxLen);
		memcpy(pcAnswer, G_pcHttpsReceivedData, 900);
		pcAnswer[G_iHttpsReceivedDataLen] = 0;
		
		*piRetAnswerLen = G_iHttpsReceivedDataLen;
		strcpy(pcAnswer,G_pcHttpsReceivedData);
		strcpy(pcRepStatus,"Ok");
	}
	else
	{
		strcpy(pcAnswer,"NO RESULT");
		strcpy(pcRepStatus,"KO");
	}
return true;
}


bool CLibCurl::POST_Data(char * pcIpCamera , char * pcUrl, int32_t iUrlLen, char * pchttp_data, int32_t ihttp_data_len, char * pcAnswer, char* pcRepStatus, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen,char* pcRetError ,int32_t iTimeOutms){


CURL *curl;
CURLcode res;
if (ihttp_data_len>0)
{
char url_https[URL_MAX_LENGTH];

snprintf(url_https,sizeof(url_https),"%s%s",pcIpCamera,pcUrl);
curl = curl_easy_init();
if(curl) {
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
  curl_easy_setopt(curl, CURLOPT_URL, url_https);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write_Data);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
 curl_easy_setopt(curl, CURLOPT_TIMEOUT,iTimeOutms/1000);

   struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Authorization: Basic YWRtaW46QUNhM3Q1bHNw");
  headers = curl_slist_append(headers, "Content-Type: application/xml");
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  const char *data = pchttp_data;
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
  res = curl_easy_perform(curl);

if(CURLE_OK != res)
	{
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(res));
		strcpy(pcRetError,strerror(res));
		strcpy(pcRepStatus,"KO");
		
		return false;
		
		
	}
	else
	{
		printf("%s :  %s : %d ==>curl    succes \n", __FILE__,__FUNCTION__,__LINE__ );
		strcpy(pcRetError,"No Error");
		
	}
}
curl_easy_cleanup(curl);
}
else
	printf("not data found");



if(!iAnswerMaxLen && ! pcAnswer )	//Perhaps we don't need the answer
	{
		
		if (piRetAnswerLen)
			*piRetAnswerLen = G_iHttpsReceivedDataLen;
	}
	else if(iAnswerMaxLen && iAnswerMaxLen < G_iHttpsReceivedDataLen)
	{
		if(piRetAnswerLen)
			*piRetAnswerLen = 0;
		
		if(pcAnswer != NULL && iAnswerMaxLen > 0)
		{
			memset(pcAnswer,0,iAnswerMaxLen);
		}

	}


if (pcAnswer != NULL && iAnswerMaxLen > 0 && G_iHttpsReceivedDataLen > 0 )
	{
		memset(pcAnswer, 0, iAnswerMaxLen);
		memcpy(pcAnswer,  G_pcHttpsReceivedData,900);
		pcAnswer[G_iHttpsReceivedDataLen] = 0;
		
		*piRetAnswerLen = G_iHttpsReceivedDataLen;
		strcpy(pcAnswer,G_pcHttpsReceivedData);
		strcpy(pcRepStatus,"OK");

	}
else 
	{
		strcpy(pcRepStatus,"KO");
	}
	return true;
}
bool CLibCurl::PUT_Data( char * pcIpCamera ,char * pcUrl, int32_t iUrlLen, char * pchttp_data, int32_t ihttp_data_len, char * pcAnswer,char* pcRepStatus, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen,char* pcRetError, int32_t iTimeOutms){


CURL *curl;
CURLcode res;
char url_https[URL_MAX_LENGTH];

//G_pcHttpsReceivedData = (char*)realloc(G_pcHttpsReceivedData,(G_iHttpsReceivedDataLen + 1) * sizeof(char));

snprintf(url_https,sizeof(url_https)-1,"%s%s",pcIpCamera,pcUrl);
printf("%s\n",url_https);
if (ihttp_data_len>0)
{
curl = curl_easy_init();
if(curl) {
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
  curl_easy_setopt(curl, CURLOPT_URL, url_https);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write_Data);

  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
 curl_easy_setopt(curl, CURLOPT_TIMEOUT,iTimeOutms/1000);
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Authorization: Basic YWRtaW46QUNhM3Q1bHNw");
  headers = curl_slist_append(headers, "Content-Type: application/xml");
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  const char *data = pchttp_data;
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
  res = curl_easy_perform(curl);

if(CURLE_OK != res)
	{
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(res));
		strcpy(pcRepStatus,"KO");
		strcpy(pcRetError,strerror(res));
		
		return false;
		
		
	}
	else
	{
		printf("%s :  %s : %d ==>curl    succes \n", __FILE__,__FUNCTION__,__LINE__ );
		strcpy(pcRetError,"No Error");
		
	}
}
curl_easy_cleanup(curl);

}
else{
	printf("%s :  %s : %d ==>not data found \n", __FILE__,__FUNCTION__,__LINE__);
	return false;}



if(!iAnswerMaxLen && ! pcAnswer )	//Perhaps we don't need the answer
	{
		
		if (piRetAnswerLen)
			*piRetAnswerLen = G_iHttpsReceivedDataLen;
	}
	else if(iAnswerMaxLen && iAnswerMaxLen < G_iHttpsReceivedDataLen)
	{
		if(piRetAnswerLen)
			*piRetAnswerLen = 0;
		
		if(pcAnswer != NULL && iAnswerMaxLen > 0)
		{
			memset(pcAnswer,0,iAnswerMaxLen);
		}

	}


if (pcAnswer != NULL && iAnswerMaxLen > 0 && G_iHttpsReceivedDataLen > 0 )
	{
		memset(pcAnswer, 0, iAnswerMaxLen);
		memcpy(pcAnswer,  G_pcHttpsReceivedData,900);
		pcAnswer[G_iHttpsReceivedDataLen] = 0;
		
		*piRetAnswerLen = G_iHttpsReceivedDataLen;
		strcpy(pcAnswer,G_pcHttpsReceivedData);
		strcpy(pcRepStatus,"OK");

	}
else 
	{
		strcpy(pcRepStatus,"KO");
	}
	return true;
}





