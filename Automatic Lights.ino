#include <NewPing.h>

// Define the pins for the ultrasonic sensor and LED
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13

// Define the maximum distance in cm
#define MAX_DISTANCE 200

// Initialize the NewPing library with the pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Get the distance from the ultrasonic sensor in cm
  int distance = sonar.ping_cm();

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  // If the distance is 10cm or less, turn on the LED
  if (distance <= 10) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Delay for 500 milliseconds
  delay(500);
}

