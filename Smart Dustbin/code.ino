#include <Servo.h>

#define TRIGGER_PIN  9 
#define ECHO_PIN     10 
#define SERVO_PIN    11 
#define MAX_DISTANCE 20 

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;
 
  if (distance <= MAX_DISTANCE) {
    servo.write(90); 
    delay(1000); 
  } else {
    servo.write(0); 
  }
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
  delay(1000); 
}
