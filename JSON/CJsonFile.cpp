#include <iostream>
#include <sstream>
#include <stdlib.h>
#include"CJsonFile.h"
#include <jsoncpp/json/value.h> 
#include <jsoncpp/json/json.h> 
#include <fstream>
#include <string.h>
#include <unistd.h>



using namespace std ;

CJsonFile:: CJsonFile(){


}
CJsonFile::~CJsonFile(){

}


/**
 * @brief la function write_Json permet de lire appartir d'un fichier JSON.elle prend en parametre : 
 * @param pcJsonFileName  est le fichier json "input.json"
 * @param pcRetUrl pointeur sur ISAPI 
 * @param pcRetHttpData pointeur sur le corp XML de l'ISAPI
 * @param pcRetParams pointeur sur le parametre retourner par le fichier json 
 * @param pcIdISAPI pointeur sur l'adresse ip de camera 
 * @return true  en cas de succes 
 * @return false en cas de echec 
 */

bool CJsonFile::read_Json(char* pcJsonFileName  ,char* pcRetUrl,char* pcRetHttpData,char* pcRetParams, char* pcIdISAPI) 
{   

  
  bool bTestCMD =true;
  bool bTestParam=false;
  ifstream file (pcJsonFileName);
  Json::Reader jPtrReader;
  Json::Value jEventRead;
  if(!jPtrReader.parse (file,jEventRead)) 
  {
    cout << jPtrReader.getFormattedErrorMessages();    return false;
  } 
  else 
  {
     for( Json::Value::iterator outer = jEventRead.begin() ; outer != jEventRead.end() ; outer++ )
    {
      //cout << outer.key() << ": " << *outer << endl;
      for( Json::Value::iterator inner1 = (*outer).begin() ; inner1 != (*outer).end() ; inner1++ )
        {//cout<<"bTestParam"<<bTestParam;
          if (*inner1== pcIdISAPI )

          { //cout<<"bTestParam*"<<bTestParam;
            inner1--;
            inner1--;
            inner1--;
            
            
            //cout<<"azaaaaa"<<*inner1;
            bTestCMD =false;
            bTestParam=true;
            //cout<<"bTestParam*"<<bTestParam;
            //pcRetUrl=inner1->asString().c_str(); 
            strcpy(pcRetUrl,inner1->asString().c_str());
            inner1++;
            
            
            strcpy(pcRetHttpData,inner1->asString().c_str());
            inner1++;
            inner1++;
          }
          else if (!bTestCMD) 
          {
            bTestCMD =true;
            bTestParam=true;
            //cout<<"bTestParam**"<<bTestParam;
          }
          
          
            for( Json::Value::iterator inner2 = (*inner1).begin() ; inner2 != (*inner1).end() ; inner2++ )
            {//cout<<"bTestParam*****"<<bTestParam<< endl;
              if(bTestParam )
              {
                
                strcpy(pcRetParams,inner2->asString().c_str());
                 bTestParam=false;
              }  
            }
        }
    }
   
    return true;
  }
return true;  
}

/**
 * @brief la function write_Json permet de ecrire dans un fichier JSON.Elle prend en parametre :
 * 
 * @param pcJsonFileName 
 * @param pcUrl pointeur sur ISAPI 
 * @param pcHttp_Data pointeur sur le corps XML de la resultat de ISAPI
 * @param pcRepStatus elle prend OK en cas de succes ou KO en cas d'echec
 * @param pcError prend l' erreur retouner par la function strerror()
 * @return true en cas de succes 
 * @return false en cas de echec 
 */
bool CJsonFile:: write_Json (char * pcJsonFileName ,char* pcUrl ,char* pcHttp_Data,char *pcRepStatus,char* pcError)
{   
  
  
 
  ifstream file (pcJsonFileName);
  Json::Reader jPtrReader;
  Json::Value jEventWrite;
  Json::Value jActualJson;
  Json::Value m_jVectJson(Json::arrayValue);

  if(!jPtrReader.parse (file,jActualJson)) 
  {
    std::cout << jPtrReader.getFormattedErrorMessages();
    exit(1);
    
  } 
  else 
  { 
    for (int i=0 ;i< jActualJson.size();i++)
      m_jVectJson.append(jActualJson[i]);
      
  
  }
  

  jEventWrite["ISAPICmd"] = pcUrl;
  jEventWrite["REP_STATUS"] = pcRepStatus;
  jEventWrite["ISAPI_RESULT"] = pcHttp_Data;
  jEventWrite["ERROR"] = pcError;
  

  m_jVectJson.append (jEventWrite);
 ofstream file_id;
  file_id.open(pcJsonFileName);
  Json::StyledWriter styledWriter;
  file_id << styledWriter.write(m_jVectJson);
  file_id.close();
   
  

return true;  
 
}




   