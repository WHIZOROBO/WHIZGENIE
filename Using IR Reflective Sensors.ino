int sensorPin = A0; // Connect sensor to analog pin A0
int threshold = 500; // Set the threshold value for detecting an object

void setup() {
  Serial.begin(9600); // Initialize the serial communication
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the sensor value
  Serial.println(sensorValue); // Print the sensor value to the serial monitor

  if (sensorValue > threshold) { // If an object is detected
    Serial.println("Object detected!");
  }
  else { // If no object is detected
    Serial.println("No object detected");
  }

  delay(500); // Wait for 500 milliseconds before reading the sensor again
}

