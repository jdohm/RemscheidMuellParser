/*
  RemscheidMuellParser.h - Library to parse ICS Calendar files.
  The aim of this library is, to enable you to easily search for words in the event description on given days.
  This will be used to evaluate if tomorrow the trash will be emtied. 
  So that an output can signal to put out the trash.
  Created by Jannis Dohm, 2020-02-12.
  Released under MIT License.
*/
#ifndef RemscheidMuellParser_
#define RemscheidMuellParser_

#include "Arduino.h"

class RemscheidMuellParser
{
    public:
        RemscheidMuellParser(char *DatabaseURL);
        bool CheckDate(char* SearchFor, int day, int month, int year);

    private:
        char *_DatabaseURL;
        String _ToTwoString(int Number);
};


#endif //RemscheidMuellParser