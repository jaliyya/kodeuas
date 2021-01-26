#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN 2         
#define DHTTYPE DHT22  

char auth[] = "90jyDL1oRoGDUl_zLi35fQLppWba2UlP";
char ssid[] = "ONET-House";
char pass[] = "mimimeow123";
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
void setup(){
  dht.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Blynk.run();
  timer.run();
  Blynk.virtualWrite(V5, h);  
  Blynk.virtualWrite(V6, t); 
}
