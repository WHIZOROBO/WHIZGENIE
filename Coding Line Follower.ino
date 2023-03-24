// Line Follower Robot Code

// Define the pins for the motors
int leftMotorControl1 = 5;
int leftMotorControl2 = 6;
int leftMotorEnable = 3;
int rightMotorControl1 = 9;
int rightMotorControl2 = 10;
int rightMotorEnable = 11;

// Define the pins for the sensors
int leftSensor = A0;
int rightSensor = A1;

// Define the threshold for detecting the line
int threshold = 500;

void setup() {
  // Set the motor control pins as outputs
  pinMode(leftMotorControl1, OUTPUT);
  pinMode(leftMotorControl2, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorControl1, OUTPUT);
  pinMode(rightMotorControl2, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);
 
  // Set the sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
 
  // Set the motor enable pins high
  digitalWrite(leftMotorEnable, HIGH);
  digitalWrite(rightMotorEnable, HIGH);
}

void loop() {
  // Read the sensor values
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);
 
  // Check if both sensors are on the line
  if (leftValue > threshold && rightValue > threshold) {
    // Move forward
    digitalWrite(leftMotorControl1, HIGH);
    digitalWrite(leftMotorControl2, LOW);
    digitalWrite(rightMotorControl1, HIGH);
    digitalWrite(rightMotorControl2, LOW);
  }
  // Check if only the left sensor is off the line
  else if (leftValue < threshold && rightValue > threshold) {
    // Turn right
    digitalWrite(leftMotorControl1, HIGH);
    digitalWrite(leftMotorControl2, LOW);
    digitalWrite(rightMotorControl1, LOW);
    digitalWrite(rightMotorControl2, HIGH);
  }
  // Check if only the right sensor is off the line
  else if (leftValue > threshold && rightValue < threshold) {
    // Turn left
    digitalWrite(leftMotorControl1, LOW);
    digitalWrite(leftMotorControl2, HIGH);
    digitalWrite(rightMotorControl1, HIGH);
    digitalWrite(rightMotorControl2, LOW);
  }
  // Check if both sensors are off the line
  else {
    // Stop
    digitalWrite(leftMotorControl1, LOW);
    digitalWrite(leftMotorControl2, LOW);
    digitalWrite(rightMotorControl1, LOW);
    digitalWrite(rightMotorControl2, LOW);
  }
}

