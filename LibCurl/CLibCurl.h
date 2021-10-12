#ifndef CLIBCURL_H_
#define CLIBCURL_H_
using namespace std;

#define URL_MAX_LENGTH 50 
class CLibCurl {
private:
	




public:





void ClearReceivedData();  
CLibCurl();
~CLibCurl();

size_t writedata(void *ptr, size_t size, size_t nmemb);
bool GET_Data(char * pcIpCamera ,char * pcUrl, int32_t iUrlLen,  char * pcAnswer,char* pcRepStatus, int32_t iAnswerMaxLen,  int32_t * iretAnswerLen,char* pcRetError, int32_t iTimeOutms);
bool POST_Data(char * pcIpCamera ,char * pcUrl, int32_t iUrlLen, char * pchttp_data, int32_t ihttp_data_len,  char * pcAnswer, char* pcRepStatus, int32_t iAnswerMaxLen, int32_t * piRetAnswerLen, char* pcRetError,int32_t iTimeOutms);
bool PUT_Data( char * pcIpCamera ,char * pcUrl,  int32_t iUrlLen, char * pchttp_data, int32_t ihttp_data_len,  char * pcAnswer,char* pcRepStatus,  int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, char* pcRetError,int32_t iTimeOutms);










};

#endif /* CLIBCURL_H_ */
