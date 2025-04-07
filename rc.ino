<<<<<<< HEAD
void setup() {
  Serial.begin(9600);
  Serial.println("RC Car Controller");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN2, OUTPUT);
  pinMode(LED_BUILTIN3, OUTPUT);
  pinMode(LED_BUILTIN4, OUTPUT);
}

  // Initialize the motor driver pins
  pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);

  // Initialize the servo
  myServo.attach(SERVO_PIN);
  myServo.write(90); // Set initial position to center (90 degrees)

  // Initialize the Bluetooth module
  SerialBT.begin("RC_Car"); // Bluetooth device name
  Serial.println("Bluetooth device is ready to pair");
=======
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

    if (command == 'b') { // Move Forward
      digitalWrite(adirection, HIGH);
      analogWrite(motoraspeed, 255);

      digitalWrite(bdirection, LOW);
      analogWrite(motorbspeed, 255);
    } 
    else if (command == 'f') { // Move Backward
      digitalWrite(adirection, LOW);
      analogWrite(motoraspeed, 255);

      digitalWrite(bdirection, HIGH);
      analogWrite(motorbspeed, 255);
    } 
    else if (command == 'l') { // Turn Right (Left Motor Forward, Right Motor Backward)
      digitalWrite(adirection, LOW);
      analogWrite(motoraspeed, 255);

      digitalWrite(bdirection, LOW);
      analogWrite(motorbspeed, 255);
    } 
    else if (command == 'r') { // Turn Left (Left Motor Backward, Right Motor Forward)
      digitalWrite(adirection, HIGH);
      analogWrite(motoraspeed, 255);

      digitalWrite(bdirection, HIGH);
      analogWrite(motorbspeed, 255);
    } 
    else { // Stop
      analogWrite(motoraspeed, 0);
      analogWrite(motorbspeed, 0);
    }
  }
>>>>>>> c00a0007a2c63e195f39eef01e164439c40592bc
}