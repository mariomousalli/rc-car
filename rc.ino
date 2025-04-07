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
}