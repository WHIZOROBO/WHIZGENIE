#include <NewPing.h>
#include <Servo.h>

// Define the pins for the ultrasonic sensor and servo motor
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define SERVO_PIN 9

// Define the maximum distance in cm and the angle limits for the servo motor
#define MAX_DISTANCE 50
#define ANGLE_CLOSED 0
#define ANGLE_OPEN 90

// Initialize the NewPing and Servo libraries with the pins and angle limits
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo servo;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Attach the servo to the servo pin
  servo.attach(SERVO_PIN);

  // Set the servo to its closed position
  servo.write(ANGLE_CLOSED);
}

void loop() {
  // Get the distance from the ultrasonic sensor in cm
  int distance = sonar.ping_cm();

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  // Check if the distance is within the threshold for opening the door
  if (distance < MAX_DISTANCE) {
    // Set the servo to its open position
    servo.write(ANGLE_OPEN);
    delay(1000);
  } else {
    // Set the servo to its closed position
    servo.write(ANGLE_CLOSED);
  }
