int ledPin = 9;     // LED connected to PWM pin 9

void setup() {
  pinMode(ledPin, OUTPUT);   // Set the LED pin as an output
}

void loop() {
  // Increase the brightness of the LED
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // Set the PWM duty cycle
    delay(10);   // Wait for 10 milliseconds
  }

  // Decrease the brightness of the LED
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);  // Set the PWM duty cycle
    delay(10);   // Wait for 10 milliseconds
  }
}