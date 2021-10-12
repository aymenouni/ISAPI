#ifndef CCONNECTCAMERA_H_
#define CCONNECTCAMERA_H_

using namespace std;

class CConnectCamera {
private:




public:


CConnectCamera();
~CConnectCamera();

void GetJsonData(char* pcJsonFileName ,char* pcRetUrl,char* pcRetHttpData,char* pcRetParam ,char* pcIdISAPI);
void TestJsonData (char * pcIpCamera, char * pcUrl, int32_t iUrlLen, char * pcHttp_data, int32_t iHttp_data_len, char * pcAnswer,char *pcRepStatus, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, char* pcRetError,int32_t iTimeOutms,char* pcMethode);
void Write_Result (char * pcJsonFileName, char* pcUrl,char* pcAnswer, char* pcRepStatus,char* pcError);
};

#endif /* CCONNECTCAMERA_H_ */
