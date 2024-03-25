int sensor;

const int greenled = 8;
const int redled = 12;
const int thresh = 200;

void setup()
{
  Serial.begin(9600);

  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
}

void loop()
{
  delay(100);
  sensor = analogRead(A5);
  Serial.println(sensor);
  
  if(sensor > thresh)
  {
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
  }
  else
  {
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
  }
  delay(100);
}