#define SSID "your_SSID"
#define PASS "your_pass"
#define IP "184.106.153.149" // thingspeak.com IP
String GET = "GET /update?key=your_apikey&field1=";

long randNumber;

void setup()
{
  Serial.begin(9600);
  Serial.println("AT");
  delay(5000);
  if (Serial.find("OK")) {
    connectWiFi();
  }
}

void loop() {
  char buffer[10];
  randNumber = random(1,100);
  String tempF = dtostrf(randNumber, 4, 1, buffer);
  updateData(tempF);
  delay(60000);
}

void updateData(String data) {
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  delay(2000);
  if (Serial.find("Error")) {
    return;
  }
  cmd = GET;
  cmd += data;
  cmd += "\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if (Serial.find(">")) {
    Serial.print(cmd);
  } else {
    Serial.println("AT+CIPCLOSE");
  }
}

boolean connectWiFi() {
  Serial.println("AT+CWMODE=1");
  delay(2000);
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  Serial.println(cmd);
  delay(5000);
  if (Serial.find("OK")) {
    return true;
  } else {
    return false;
  }
}
