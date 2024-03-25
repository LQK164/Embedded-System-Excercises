#define TRIG_PIN 13 // Chân Trig của cảm biến kết nối với chân 2 trên Arduino
#define ECHO_PIN 12 // Chân Echo của cảm biến kết nối với chân 3 trên Arduino

#define LED_COUNT 10 // Số lượng đèn LED sử dụng

unsigned long duration;
int distance;
int ledPins[LED_COUNT] = {2,3,4,5,6,7,8,9,10,11}; // Chân kết nối đèn LED

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Tắt tất cả các đèn LED ban đầu
  }
}

void loop() {
  // Gửi xung ultrasonic để kích hoạt cảm biến
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Đọc thời gian trả về từ cảm biến
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Chuyển thời gian thành khoảng cách (đơn vị cm)
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Ánh xạ khoảng cách thành số lượng đèn LED cần bật
  int numLEDsToLight = map(distance, 0, 100, 0, LED_COUNT); // 100cm là khoảng cách gần nhất
  
  for (int i = 0; i < LED_COUNT; i++) {
    if (i < numLEDsToLight) {
      digitalWrite(ledPins[i], LOW); // Tắt các đèn LED còn lại
    } else {
      digitalWrite(ledPins[i], HIGH); // Bật các đèn LED từ 0 đến numLEDsToLight - 1
    }
  }
  
  delay(100); // Đợi một chút trước khi đo lại khoảng cách
}
