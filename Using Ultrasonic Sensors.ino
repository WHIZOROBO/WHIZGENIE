#define TRIG_PIN 9

#define ECHO_PIN 10
void setup() {
Serial.begin(9600);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
}

void loop() {
long duration, distance_cm, distance_inch;

// Send a 10us pulse to the TRIG pin
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

// Measure the duration of the echo pulse
duration = pulseIn(ECHO_PIN, HIGH);

// Calculate the distance in centimeters and inches
distance_cm = duration / 58;
distance_inch = duration / 148;

// Print the distance to the serial monitor
Serial.print("Distance: ");
Serial.print(distance_cm);
Serial.print("cm ");
Serial.print(distance_inch);
Serial.println("in");

// Wait for 100ms
delay(100);
}
