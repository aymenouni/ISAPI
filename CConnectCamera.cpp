#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include "JSON/CJsonFile.cpp"
#include "LibCurl/CLibCurl.cpp"
#include "CConnectCamera.h"
#include <unistd.h>
using namespace std ;




CConnectCamera::CConnectCamera(){

}
CConnectCamera::~CConnectCamera(){

}
/**
 *  la fonction fait appele a la fonction CJsonFile::read_Json pour recupere les donne du fichier json
 */
void CConnectCamera::GetJsonData(char* pcJsonFileName ,char* pcRetUrl,char* pcRetHttpData,char* pcRetParam,char* pcIdISAPI){
    CJsonFile* CJson = new CJsonFile();  
    bool bRet = CJson->read_Json(pcJsonFileName ,pcRetUrl,pcRetHttpData ,pcRetParam , pcIdISAPI);
    if(!bRet)
    {
        printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(bRet));
    }
    else
    {
        printf ("get json data  succes \n");
      
    }
   
}

/**
* cette function fait appele au function de la classe CLibCurl selon le parametre pcMethode qui prend les valeur "GET","POST","PUT".
*/
void CConnectCamera::TestJsonData (char * pcIpCamera , char * pcUrl, int32_t iUrlLen, char * pcHttp_data, int32_t iHttp_data_len, char * pcAnswer, char* pcRepStatus, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen,char* pcRetError ,int32_t iTimeOutms,char* pcMethode){
    CLibCurl* ClibCurl= new CLibCurl();
    
   
    if (pcMethode == "GET") {
       
        bool bRet = ClibCurl->GET_Data( pcIpCamera,pcUrl, iUrlLen,   pcAnswer,pcRepStatus, iAnswerMaxLen,   piRetAnswerLen,pcRetError,iTimeOutms);
        
        if ( !bRet ){
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__, __FUNCTION__,__LINE__, strerror(bRet));
        }
	    else{
		printf("curl  succes \n" );
	    }
    }
    if (pcMethode == "PUT") {
        bool bRet = ClibCurl->PUT_Data(pcIpCamera, pcUrl,  iUrlLen, pcHttp_data,  iHttp_data_len, pcAnswer,pcRepStatus, iAnswerMaxLen,  piRetAnswerLen, pcRetError,iTimeOutms);
        if ( !bRet ){
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__, __FUNCTION__,__LINE__, strerror(bRet));
        }
	    else{
		printf("curl  succes \n" );
	    }
    }
    if (pcMethode == "POST") {
        bool bRet = ClibCurl->POST_Data(pcIpCamera, pcUrl,  iUrlLen, pcHttp_data,  iHttp_data_len, pcAnswer,pcRepStatus, iAnswerMaxLen,  piRetAnswerLen, pcRetError, iTimeOutms);
        if ( !bRet ){
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__, __FUNCTION__,__LINE__, strerror(bRet));
        }
	    else{
		printf("curl  succes \n" );
	    }
    }
    
}

void CConnectCamera::Write_Result (char * pcJsonFileName, char* pcUrl,char* pcAnswer, char* pcRepStatus,char* pcError){

   CJsonFile* CJson = new CJsonFile();  
    bool bRet = CJson->write_Json(pcJsonFileName , pcUrl , pcAnswer, pcRepStatus, pcError);
    if(!bRet)
    {
        printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(bRet));
    }
    else
    {
        printf ("get json data  succes \n");
      
    }
}

int main()
{
    CConnectCamera object;
  
char pcRetUrl[100];
char pcRetHttpData[900];
char pcRetParam[100] ;
char pcAnswer[900];
char pcSendData[1000];
char pcRepStatus[3];
char pcRetError[100];
char pcParam[100]="";

int32_t* piRetAnswerLen;
 int iIdISAPI = 1 ;
 char pcIdISAPI[100];
while(1)
{
sprintf(pcIdISAPI, "%d", iIdISAPI);
object.GetJsonData ((char*)"JSON/input.json" ,(char*)pcRetUrl,(char*)pcRetHttpData,(char*)pcRetParam,(char*)pcIdISAPI);




//cout<<"Url="<<pcRetUrl<<endl;
//cout<<"HttpData ="<<pcRetHttpData<<endl;
snprintf(pcSendData,sizeof(pcRetHttpData)-1,pcRetHttpData,pcRetParam);
object.TestJsonData ((char*)"192.168.1.149",(char*)pcRetUrl ,100,(char*)pcSendData,900,pcAnswer,pcRepStatus,900,piRetAnswerLen,pcRetError,15000 ,(char*) "PUT");
iIdISAPI++;
sleep(3);
object.Write_Result ((char *)"JSON/Result.json", (char*)"/ISAPI/Streaming/channels/1" , pcAnswer,pcRepStatus,pcRetError);


if(!strcmp(pcParam,pcRetParam) )
{
    //cout<<"**\n";

    exit(1);
    
}
/*else{
    
cout<<"Param="<<pcRetParam<<endl;

cout<<"Params="<<pcParam<<endl;    
}*/
strcpy(pcParam,pcRetParam); 
}


}
