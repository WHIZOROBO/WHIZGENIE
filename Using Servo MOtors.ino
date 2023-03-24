#include <Servo.h>

// Create a Servo object
Servo myservo;

void setup() {
  // Attach the servo motor to digital pin 9
  myservo.attach(9);
}

void loop() {
  // Move the servo to the starting position
  myservo.write(0);

  // Wait for 1 second
  delay(1000);

  // Move the servo to the middle position
  myservo.write(90);

  // Wait for 1 second
  delay(1000);

  // Move the servo to the ending position
  myservo.write(180);

  // Wait for 1 second
  delay(1000);
}
