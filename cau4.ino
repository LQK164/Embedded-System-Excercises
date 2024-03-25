#include <BH1750.h>
#include <Wire.h>

int LED = 2;

BH1750 lightMeter;
const int thresh = 100;

void setup() {

Serial.begin(9600);
pinMode(LED, OUTPUT);
Wire.begin();
lightMeter.begin();

}
void loop() {
float lux = lightMeter.readLightLevel();
Serial.print("Light: ");
Serial.print(lux);
Serial.println(" lx");

if(lux < thresh)
{
  analogWrite(LED, 255);
  delay(500);
}
else{
  analogWrite(LED, 0);
  delay(500);
}

delay(1000);
}