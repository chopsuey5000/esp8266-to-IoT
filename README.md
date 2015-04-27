# esp8266-to-IoT
ARDUINO -> ESP8266 WIFI Module -> IoT platform

###ESP8266 pinout

![esp8266 pinout](https://www.robotics.org.za/image/data/Breakout/Wifi/ESP8266_003.jpg)

###How to use

For use this example just insert your **ssid** and **password** into the define's, on the top of the sketch.
Then create an account into thingspeak.com, copy your api key and put into the sketch GET variable.

###AT commands used in this example

#### Wifi connection 

| FUNCTION      | AT command      | Response      |
|:------------- |:---------------:| -------------:|
| WiFi Mode     | &nbsp;          | &nbsp;        | 
| &nbsp;        | AT+CWMODE=1     | STA           |  
| &nbsp;        | AT+CWMODE=2     | AP            | 
| &nbsp;        | AT+CWMODE=3     | BOTH          | 
| Join Access Point      | &nbsp;      | &nbsp;          | 
| &nbsp;        | AT+CWJAP="SSID","Password"     | &nbsp;|

#### Send data through TCP
| FUNCTION      | AT command      | Response      |
|:------------- |:---------------:| -------------:|
| Set up TCP or UDP connection      | &nbsp;      | &nbsp;| 
| &nbsp;|(CIPMUX=0) AT+CIPSTART =type,addr,port; (CIPMUX=1) AT+CIPSTART=id,type,addr,port|id = 0-4, type = TCP/UDP, addr = IP address, port = port|
| Send TCP/IP data       | &nbsp;      | &nbsp;| 
| &nbsp;        | (CIPMUX=0) AT+CIPSEND=length; (CIPMUX=1) AT+CIPSEND= id,length | &nbsp;|