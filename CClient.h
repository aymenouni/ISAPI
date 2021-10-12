#ifndef CClient_H_
#define CClient_H_
using namespace std;
class CClient {

public:
CClient();
~CClient();

bool GetData(char * pcUrl,  int32_t iUrlLen,  char * pcAnswer,  int32_t iAnswerMaxLen,  int32_t * iRetAnswerLen, int32_t iTimeOutms);
bool  PostData(char * pcUrl, int32_t iUrlLen, char * pcHttp_data, int32_t iHttp_data_len, char * pcAnswer, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, int32_t iTimeOutms);
bool PutData(char * pcUrl, int32_t iUrlLen, char * pcHttp_data, int32_t iHttp_data_len, char * pcAnswer, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, int32_t iTimeOutms);






};

#endif /* CClient_H_ */
