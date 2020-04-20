# RemscheidMuellParser
a Arduino library to search for Trash days in the city of Remscheid (Germany)

## usage
- Verbinde dich zu deinem WLAN, nutze hierzu die ESP8266WiFi library 
- Im Setup wird RemscheidMuellParser aufgerufen und damit die URL zu deiner Adresse übergeben.
    Die URL bekommst du auf der Website der Müllbetriebe:  https://abfallkalenderremscheid.insert-infotech.de/index.php
    Hier musst du deine Straße und Hausnummer wählen und auf "weiter zum Kalender" klicken.
    Jetzt kannst du die URL aus der Adresszeile in dein Programm kopieren. Die URL sollte in etwa so aussehen:
    https://abfallkalenderremscheid.insert-infotech.de/kalender.php?BaseString=YTozOntzOjM6IlNUUiI7czoxMToiQmFobmhvZnN0ci4iO3M6NDoiWUVBUiI7czo0OiIyMDIwIjtzOjM6IkhOUiI7czoxOiI1Ijt9
    Wenn am Ende noch ein &... Auftaucht, lösche einfach alles was noch kommt (inklusive des & Zeichens).
- Anschließend kannst du jederzeit mittels CheckDate(Suchbegriff, Tag, Monat, Jahr) checken ob an einem gegebenen Tag der Müllabgeholt wird. 
    Aktuell funktioniert dies nur für "Restabfall", "Bioabfall" und "Papierabfall". Nicht aber für die Gelbetonne (da die von einem anderen Unternehmen abgeholt wird, hier arbeite ich noch drann).
    Das Datum kannst du über ntp erhalten. Wenn du nicht eh hierher kommst, findest du alle Infos im [ZP_Muelleimer Projekt auf Github](https://github.com/jdohm/ZP_Muelleimer). 

## credits
Unsafe https connection based on [burger.dread.cz](https://buger.dread.cz/simple-esp8266-https-client-without-verification-of-certificate-fingerprint.html)
