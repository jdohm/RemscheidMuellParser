/*
    RemscheidMuellParser.cpp - Library to parse the Trash website of the German city Remscheid.
    This will be used to evaluate if tomorrow the trash will be emptied. 
    So that we can signal to put out the trash.
    Created by Jannis Dohm, 2020-04-20.
    Released under MIT License.
*/

#include "Arduino.h"
#include "RemscheidMuellParser.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

RemscheidMuellParser::RemscheidMuellParser(char *DatabaseURL){//the URL needs to be checked on the official website "https://abfallkalenderremscheid.insert-infotech.de/index.php"
    _DatabaseURL =  DatabaseURL;
}


bool RemscheidMuellParser::CheckDate(char* SearchFor, int day, int month, int year){
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();
    HTTPClient https;

  if (https.begin(*client, String(_DatabaseURL) + "&Year=" + String(year) + "&KW=NULL&Monat=" + String(month))) {  // HTTPS
    Serial.println("[HTTPS] GET...");
    int httpCode = https.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
      // file found at server?
    if (httpCode == HTTP_CODE_OK) {
        int payload = https.getSize();
        Serial.println(String("[HTTPS] Received payload: ") + payload);
        Stream *httpsS = https.getStreamPtr();
        while(httpsS -> available()){
        String _day = ">" + _ToTwoString(day) +"</div>";
        char _dayC[9];
        _day.toCharArray(_dayC,9);
        //if(httpsS -> find(String(">") + _ToTwoString(day) +"</div>")){
        if(httpsS -> find(_dayC)){
            Serial.print("found date: ");
            Serial.print(day);
            Serial.print(".");
            Serial.print(month);
            Serial.print(".");
            Serial.println(year);
             //skip next 4 line
            for(int i=0; i<4;i++){
            httpsS -> readStringUntil('\n');
            }
        }
        String line = httpsS -> readStringUntil('\n');
        Serial.print("looking for ");
        Serial.print(SearchFor);
        Serial.println(" in the following line:");
        Serial.println(line);
        if(1 <= line.indexOf(SearchFor)) return true;
        }
        return false;
    }
    } else {
    Serial.printf("[HTTPS] GET... failed, error: %s\n\r", https.errorToString(httpCode).c_str());
    }

    https.end();
  } else {
    Serial.printf("[HTTPS] Unable to connect\n\r");
  }
  return false;
}

String RemscheidMuellParser::_ToTwoString(int Num){
    if(Num<0) return "00";
    if(Num<10) return "0" + String(Num);
    return String(Num);
}