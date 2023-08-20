#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define led1 D3
#define led2 D2
#define led3 D1

const char* ssid = "LogicGatesGame";
const char* password = "12345678"; 
bool led1_state = LOW, led2_state = LOW, led3_state = LOW;
ESP8266WebServer Server(80);
IPAddress localIP(192,168,6,6), gateway(192,168,1,1), subnet(255,255,255,0);

void setup()
{
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(localIP, gateway, subnet);

  Server.on("/", handleOnConnect);
  Server.on("/led1_true", handlelled1On);
  Server.on("/led1_false", handlelled1Off);
  Server.on("/led2_true", handlelled2On);
  Server.on("/led2_false", handlelled2Off);
  Server.on("/led3_true", handlelled3On);
  Server.on("/led3_false", handlelled3Off);
  Server.onNotFound(handleNotFound);
  Server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  Server.handleClient();
  digitalWrite(led1, led1_state);
  digitalWrite(led2, led2_state);
  digitalWrite(led3, led3_state);
}

void handleOnConnect()
{
  led1_state = LOW;
  led2_state = LOW;
  led3_state = LOW;
  Serial.println("led1 state : OFF");
  Serial.println("led2 state : OFF");
  Serial.println("led3 state : OFF");
  Server.send(200, "text/plain", "connected");
}
void handlelled1On()
{
  led1_state = HIGH;
  digitalWrite(led1, led1_state);
  Serial.println("led1 state : ON");
  Server.send(200, "text/plain", "ON");
}
void handlelled1Off()
{
  led1_state = LOW;
  Serial.println("led1 state : OFF");
  Server.send(200, "text/plain", "OFF");
}
void handlelled2On()
{
  led2_state = HIGH;
  Serial.println("led2 state : ON");
  Server.send(200, "text/plain", "ON");
}
void handlelled2Off()
{
  led2_state = LOW;
  Serial.println("led2 state : OFF");
  Server.send(200, "text/plain", "OFF");
}

void handlelled3On()
{
  led3_state = HIGH;
  Serial.println("led3 state : ON");
  Server.send(200, "text/plain", "ON");
}
void handlelled3Off()
{
  led3_state = LOW;
  Serial.println("led3 state : OFF");
  Server.send(200, "text/plain", "OFF");
}
void handleNotFound()
{
  Server.send(404, "text/plain", "Not found");
}
