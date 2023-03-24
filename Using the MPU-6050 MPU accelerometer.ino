#include <Wire.h>
#include <MPU6050.h>

MPU6050 accelgyro;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  accelgyro.initialize();
}

void loop() {
  // Read the accelerometer data
  int16_t ax, ay, az;
  accelgyro.getAcceleration(&ax, &ay, &az);

  // Print the data to the serial monitor
  Serial.print("X acceleration: ");
  Serial.print(ax);
  Serial.print(" Y acceleration: ");
  Serial.print(ay);
  Serial.print(" Z acceleration: ");
  Serial.println(az);

  // Wait for 100ms
  delay(100);
}
