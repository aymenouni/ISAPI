#ifndef CJSONFILE_H_
#define CJSONFILE_H_

using namespace std;

class CJsonFile {
private:


public:




CJsonFile();
~CJsonFile();

bool read_Json(char* pcJsonFileName ,char* pcRetUrl,char* pcRetHttpData,char* pcRetParam, char* pcIdISAPI);
bool write_Json( char * pcJsonFileName ,char* pcUrl ,char* pcHttp_Data ,char *pcRepStatus,char* pcError );


};

#endif /* CJSONFILE_H_ */
