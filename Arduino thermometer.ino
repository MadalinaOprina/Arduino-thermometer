#include "DHT.h"
#define DHTPIN 14   
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  pinMode(25,OUTPUT);
}

void loop() {
  
  delay(2000);

  float h;
  h = dht.readHumidity();
  if(h>30 & h<60)
    digitalWrite(25,HIGH);
  else digitalWrite(25,LOW);
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("%"));

  
}
