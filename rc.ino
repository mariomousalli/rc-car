#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7, 6); // RX, TX for Bluetooth module

const int motoraspeed = 3;
const int adirection = 12;

const int motorbspeed = 11;
const int bdirection = 13;

void setup() {
  pinMode(adirection, OUTPUT);
  pinMode(motoraspeed, OUTPUT);

  pinMode(bdirection, OUTPUT);
  pinMode(motorbspeed, OUTPUT);

  Serial.begin(9600);   // Start serial communication with PC for debugging
  BTSerial.begin(9600); // Start Bluetooth communication with HC-05 module
}

void loop() {
  if (BTSerial.available()) {  // Read command from Bluetooth
    char command = BTSerial.read();

    if (command == 'w') { // Move Forward
      digitalWrite(adirection, HIGH);
      analogWrite(motoraspeed, 255);

      digitalWrite(bdirection, LOW);
      analogWrite(motorbspeed, 255);
    } 
    else if (command == 's') { // Move Backward
      digitalWrite(adirection, LOW);
      analogWrite(motoraspeed, 255);

      digitalWrite(bdirection, HIGH);
      analogWrite(motorbspeed, 255);
    } 
    else if (command == 'd') { // Turn Right (Left Motor Forward, Right Motor Backward)
      digitalWrite(adirection, LOW);
      analogWrite(motoraspeed, 150);

      digitalWrite(bdirection, LOW);
      analogWrite(motorbspeed, 150);
    } 
    else if (command == 'a') { // Turn Left (Left Motor Backward, Right Motor Forward)
      digitalWrite(adirection, HIGH);
      analogWrite(motoraspeed, 150);

      digitalWrite(bdirection, HIGH);
      analogWrite(motorbspeed, 150);
    } 
    else { // Stop
      analogWrite(motoraspeed, 0);
      analogWrite(motorbspeed, 0);
    }
  }
}