#include <BH1750.h>
#include <Wire.h>
#include "DHT.h"
#define DHTPIN 5     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
#include <RH_RF95.h>

BH1750 lightMeter;
RH_RF95 rf95;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
// Initialize the I2C bus (BH1750 library doesn’t do this automatically)
Wire.begin();
// On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);
// For Wemos / Lolin D1 Mini Pro and the Ambient Light shield use
// Wire.begin(D2, D1);

lightMeter.begin();
dht.begin();
if (!rf95.init())
    Serial.println("init failed");
  rf95.setFrequency(433.0);

Serial.println(F("BH1750 Test begin"));
}

void loop() {
  float lux = lightMeter.readLightLevel();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t ");

  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}