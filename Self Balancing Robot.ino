// Self-balancing Robot Code

// Include the required libraries
#include <Wire.h>
#include <MPU6050.h>

// Define the pins for the motor driver
int motor1Input1 = 5;
int motor1Input2 = 6;
int motor1Enable = 3;
int motor2Input1 = 9;
int motor2Input2 = 10;
int motor2Enable = 11;

// Define the PID constants
float Kp = 30;
float Kd = 1;
float Ki = 0;

// Define the setpoint angle
float setpoint = 0;

// Initialize the MPU6050 sensor
MPU6050 mpu;

// Initialize the PID variables
float error, lastError = 0;
float P, I = 0, D;
float pidOutput;

void setup() {
  // Set the motor control pins as outputs
  pinMode(motor1Input1, OUTPUT);
  pinMode(motor1Input2, OUTPUT);
  pinMode(motor1Enable, OUTPUT);
  pinMode(motor2Input1, OUTPUT);
  pinMode(motor2Input2, OUTPUT);
  pinMode(motor2Enable, OUTPUT);

  // Set the motor enable pins high
  digitalWrite(motor1Enable, HIGH);
  digitalWrite(motor2Enable, HIGH);
 
  // Initialize the serial communication
  Serial.begin(9600);
 
  // Initialize the MPU6050 sensor
  Wire.begin();
  mpu.initialize();
 
  // Set the gyro offset
  mpu.setXGyroOffset(220);
  mpu.setYGyroOffset(76);
  mpu.setZGyroOffset(-85);
}

void loop() {
  // Read the sensor data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 
  // Calculate the angle
  float angle = atan2(ax, az) * 180 / PI;
 
  // Calculate the error
  error = setpoint - angle;
 
  // Calculate the PID output
  P = Kp * error;
  I = I + Ki * error;
  D = Kd * (error - lastError);
  pidOutput = P + I + D;
 
  // Update the last error
  lastError = error;
 
  // Control the motors
  int motor1Speed = pidOutput;
  int motor2Speed = pidOutput;
 
  // Check if the robot is leaning forwards or backwards
  if (error > 0) {
    // Lean forwards, slow down the front motor
    motor1Speed -= abs(error);
  } else {
    // Lean backwards, slow down the rear motor
    motor2Speed += abs(error);
  }
 
  // Set the motor speeds
  analogWrite(motor1Input1, motor1Speed);
  analogWrite(motor1Input2, 0);
  analogWrite(motor2Input1, motor2Speed);
  analogWrite(motor2Input2, 0);
 
  // Print the sensor and PID values to the serial monitor
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print(" | ");
  Serial.print("Error: ");
  Serial.print(error);
  Serial.print(" | ");

Serial.print("P: ");

Serial.print(P);

Serial.print(" | ");

Serial.print("I: ");

Serial.print(I);

Serial.print(" | ");

Serial.print("D: ");

Serial.print(D);

Serial.print(" | ");

Serial.print("PID Output: ");

Serial.print(pidOutput);

Serial.print("n");

// Delay for 10 milliseconds

delay(10);

}

