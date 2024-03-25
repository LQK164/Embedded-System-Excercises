const int buttonPin = A5;
int led[13] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A4};
const int differentColorLED = 7;

int currentLed = 0;
int score = 0;
int speed = 500;

void proc()
{
  digitalWrite(led[currentLed], HIGH);
  delay(speed);
  digitalWrite(led[currentLed], LOW);
  
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH && led[currentLed] == differentColorLED) {
    score++;
    speed -= 100; // Tăng tốc độ
    Serial.println("Correct!");
    Serial.print("Score: ");
    Serial.println(score);
  } else if (buttonState == HIGH) {
    if (score > 0)
    {
        score--;
        speed += 100; // Giảm tốc độ
    }
    Serial.println("Wrong!");
    Serial.print("Score: ");
    Serial.println(score);
  }
  speed = constrain(speed, 100, 1000);
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < 13; i++) {
    pinMode(led[i], OUTPUT);
  }
  Serial.print("Diem: ");
  Serial.println(score);
}

void loop() {
  // Hiển thị đèn tại vị trí hiện tại
  digitalWrite(led[currentLed], HIGH);

  delay(speed);

  digitalWrite(led[currentLed], LOW);

  for (; currentLed < 13; currentLed++)
    proc();
  
  for (; currentLed >= 1; currentLed--)
    proc();
  
}