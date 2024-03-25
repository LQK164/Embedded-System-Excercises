int led[] = {2,3,4,5,6,7,8,9,10,11,12,13}; // Đặt các đèn lần lượt vào các chân từ 2 đến 12
int POT = A1;
void setup()
{
  Serial.begin(9600);
  for(int i =0; i < sizeof(led[i])/sizeof(led[0]); i++)
  {
    pinMode(led[i], OUTPUT);
  }
  pinMode(POT, INPUT);
}
void loop()
{
  int potValue = analogRead(POT);
  Serial.println(potValue);
  int index = map(potValue, 0 , 1007, 0, 12);
  for(int i =0; i < index; i++)
  {
     analogWrite(led[i], 255);
    //delay(10);
  }
  for(int i =index; i < 12 ; i++)
  {
     analogWrite(led[i], 0);
    //delay(10);
  }
}