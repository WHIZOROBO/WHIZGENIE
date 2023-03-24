#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo servoMotor;

int servoPosition = 90;

void setup() {
  servoMotor.attach(3);
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) {
    moveBackward();
    delay(500);
    turnLeft();
  } else {
    moveForward();
  }
}

void moveForward() {
  servoMotor.write(servoPosition);
  delay(100);
}

void moveBackward() {
  servoMotor.write(servoPosition + 180);
  delay(100);
}

void turnLeft() {
  servoMotor.write(servoPosition - 45);
  delay(100);
}
