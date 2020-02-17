/*
  RemscheidMuellParser.cpp - Library to parse the Trash website of the German city Remscheid.
  This will be used to evaluate if tomorrow the trash will be emtied. 
  So that an output can signal to put out the trash.
  Created by Jannis Dohm, 2020-02-17.
  Released under MIT License.
*/

#include "Arduino.h"
#include "FS.h" //filesystem for ESP8266: http://arduino.esp8266.com/Arduino/versions/2.0.0/doc/filesystem.html under LGPL V2.1
#include "RemscheidMuellParser.h"

RemscheidMuellParser::RemscheidMuellParser(string DatabaseURL){//the URL needs to be checked on the official website "https://abfallkalenderremscheid.insert-infotech.de/index.php"
    SPIFFS.begin();
    _DatabaseURL =  DatabaseURL;
    _file = SPIFFS.open("/" + _DatabaseURL, "r");
    if (!_file) {
    Serial.println("file open failed");
    }
}


uint_8 RemscheidMuellParser::CheckDate(string SearchFor, int day, int month, int year){
    /*
    if(SearchFor != Gelb) read url("_DatabaseURL" + "&Year=" + year + "&KW=NULL&Monat=" + month)
            search for "<div class="kw_td_tag kw_td kw_td_inner">10</div>"
                check if "<img class="fraction_img" src="images/fraktionen/tonne_braun_15px.jpg" alt=" +SearchFor ">" is found before "::after"
                    if yes return true else return false
    else search on other website (yet to be described)
            */
}

