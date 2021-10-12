#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include "CClient.h"
#include "LibCurl/CLibCurl.cpp"
using namespace std;



CLibCurl* ClibCurl= new CLibCurl();
// constructeur par default 
CClient::CClient(){


}
// destructeur par default 
CClient::~CClient()
{


}
/**
 *  la fonction GET_Data affiche le corps XML appartenant à ISAPI passé en paramètre .
 *  char * pcUrl  pointeur sur ISAPI
 * 	int32_t iUrlLen lengeur de ISAPI
 * 	char * pcAnswer pointeur sur le body XML retourner par PAR IZAPI 
 * 	int32_t iAnswerMaxLen le taille maximale de bidy XML 
 * 	int32_t * piRetAnswerLen le taille de la repense 
 * 	int32_t iTimeOutms temps d'attente en ms 
 */

bool CClient::GetData(char * pcUrl,  int32_t iUrlLen,  char * pcAnswer,  int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, int32_t iTimeOutms)
{
	bool bRet = ClibCurl->GET_Data(pcUrl, iUrlLen,   pcAnswer, iAnswerMaxLen,   piRetAnswerLen,iTimeOutms);
if ( !bRet )
	{
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__, __FUNCTION__,__LINE__, strerror(bRet));
		return false ;
		
		
	}
	else
	{
		printf("curl  succes \n" );
		
	}
return true ;
}
/**
 *  la fonction PostData envoie des données par la méthode post et affiche le résultat de retour   .
 *  char * pcUrl  pointeur sur ISAPI
 * 	int32_t iUrlLen lengeur de ISAPI
 * 	char * pcHttp_data pointeur sur le code XML 
 * 	int32_t iHttp_data_len taille du code XML envoyer 
 * 	char * pcAnswer pointeur sur le body XML retourner par PAR IZAPI 
 * 	int32_t iAnswerMaxLen le taille maximale de bidy XML 
 * 	int32_t * piRetAnswerLen le taille de la repense 
 * 	int32_t iTimeOutms temps d'attente en ms 
 */
bool CClient::PostData(char * pcUrl, int32_t iUrlLen, char * pcHttp_data, int32_t iHttp_data_len, char * pcAnswer, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, int32_t iTimeOutms){
int bRet = ClibCurl->POST_Data(  pcUrl,  iUrlLen, pcHttp_data,  iHttp_data_len, pcAnswer, iAnswerMaxLen,  piRetAnswerLen, iTimeOutms);
if (!bRet)
	{
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(bRet));
		return false;
		
		
	}
	else
	{
		printf("curl  succes \n" );
		
	}
return true;
}
/**
 *  la fonction PutData envoie des données par la méthode post et affiche le résultat de retour   .
 *  char * pcUrl  pointeur sur ISAPI
 * 	int32_t iUrlLen lengeur de ISAPI
 * 	char * pcHttp_data pointeur sur le code XML 
 * 	int32_t iHttp_data_len taille du code XML envoyer 
 * 	char * pcAnswer pointeur sur le body XML retourner par PAR IZAPI 
 * 	int32_t iAnswerMaxLen le taille maximale de bidy XML 
 * 	int32_t * piRetAnswerLen le taille de la repense 
 * 	int32_t iTimeOutms temps d'attente en ms 
 */
bool CClient::PutData( char * pcUrl, int32_t iUrlLen, char * pcHttp_data, int32_t iHttp_data_len, char * pcAnswer, int32_t iAnswerMaxLen,  int32_t * piRetAnswerLen, int32_t iTimeOutms){

int bRet = ClibCurl->PUT_Data( pcUrl,  iUrlLen, pcHttp_data,  iHttp_data_len, pcAnswer, iAnswerMaxLen,  piRetAnswerLen, iTimeOutms);
if (!bRet)
	{
		printf("%s :  %s : %d ==> Error: %s\n", __FILE__,__FUNCTION__,__LINE__, strerror(bRet));
		return false ;
		
		
	}
	else
	{
		printf("curl  succes \n" );
		
	}
return true;
}




