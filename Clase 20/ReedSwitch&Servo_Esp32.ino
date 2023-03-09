#include <ESP32Servo.h>

const int pinSensor = 4;
const int pinLED = 2;
Servo myServo;

void setup() {
  //configurar pin como entrada con resistencia pull-up interna
  pinMode(pinSensor, INPUT_PULLUP);
  pinMode(pinLED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Example servo");
  //Initializing servo object
  myServo.attach(2);
}

void loop() {
  int value = digitalRead(pinSensor);

  if (value == LOW) {
    digitalWrite(pinLED, HIGH);
    myServo.write(90);
  } else {
    digitalWrite(pinLED, LOW);
    myServo.write(0);
  }

  delay(1000);
}