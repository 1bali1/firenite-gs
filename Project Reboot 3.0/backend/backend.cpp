#include "backend.h"
#include <thread>
#include <iostream>
//#include <Windowsh.h> // nem fog menni a pcmen tho
#include <string>
#include <thread>
#include <curl/curl.h>
#include <json.hpp>
using namespace std;
using json = json;
/* 
! ez majd kölleni fog 
class APlayerState : public AActor
{
public:
	FString& GetSavedNetworkAddress();
	FString GetPlayerName();
	int& GetPlayerID(); // for future me to deal with (this is a short on some versions).
	bool IsBot();
	void SetIsBot(bool NewValue);
	void OnRep_PlayerName();
};

*/
namespace Backend {
    void SendKill(string playerId, string killerId){
        // TODO: asyncet talán threadek helyett, tesztelni kéne majd gamebe
        thread([=](){
            CURL* curl = curl_easy_init();

            if (curl){
                struct curl_slist* headers = NULL;
                headers = curl_slist_append(headers, "Content-Type: application/json");
                // TODO: ha kitaláltam h milyen auth legyen akk egy header kellhet még xd
                
                json jsonData;
                jsonData["player"] = playerId;
                jsonData["killer"] = killerId;
            }
        });
    } 
}