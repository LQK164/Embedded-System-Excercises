int ledPin1 = A0; 
int ledPin2 = A1; 


int sensorPin = A2;

void setup() 
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() 
{
  int sensorValue = analogRead(sensorPin); 
  if (sensorValue > 500) 
  { 
    flashAlternate(); 
  } else 
  {
    analogWrite(ledPin1, 0); 
    analogWrite(ledPin2, 0); 
  }
}


void flashAlternate() 
{
  analogWrite(ledPin1, 255);
  analogWrite(ledPin2, 0); 
  delay(500); 
  analogWrite(ledPin1, 0); 
  analogWrite(ledPin2, 255); 
  delay(500); 
}