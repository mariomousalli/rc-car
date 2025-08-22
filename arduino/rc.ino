#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7, 6); // RX, TX for Bluetooth module

const int motoraspeed = 3;
const int adirection = 12;

const int motorbspeed = 11;
const int bdirection = 13;

// Define functions for movements
void moveForward() {
  digitalWrite(adirection, HIGH);
  analogWrite(motoraspeed, 255);

  digitalWrite(bdirection, LOW);
  analogWrite(motorbspeed, 255);
}

void moveBackward() {
  digitalWrite(adirection, LOW);
  analogWrite(motoraspeed, 255);

  digitalWrite(bdirection, HIGH);
  analogWrite(motorbspeed, 255);
}

void turnLeft() {
  digitalWrite(adirection, HIGH);  // Left motor backward
  analogWrite(motoraspeed, 150);   // Left motor speed

  digitalWrite(bdirection, HIGH);   // Right motor forward
  analogWrite(motorbspeed, 150);   // Right motor speed
}

void turnRight() {
  digitalWrite(adirection, LOW);   // Left motor forward
  analogWrite(motoraspeed, 150);   // Left motor speed

  digitalWrite(bdirection, LOW);  // Right motor backward
  analogWrite(motorbspeed, 150);  // Right motor speed
}

void stopMovement() {
  analogWrite(motoraspeed, 0);
  analogWrite(motorbspeed, 0);
}

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
      moveForward();  // Call the function to move forward
    } 
    else if (command == 's') { // Move Backward
      moveBackward();  // Call the function to move backward
    } 
    else if (command == 'a') { // Turn Left
      turnLeft();  // Call the function to turn left
    } 
    else if (command == 'd') { // Turn Right
      turnRight();  // Call the function to turn right
    } 
    else { // Stop
      stopMovement();  // Stop movement if no command is active
    }
  }
}
