const int MOTOR_LEFT_PIN = 13;
const int MOTRO_RIGHT_PIN = 12;
int lastState = LOW;

class DistanceSensor {
public:
  DistanceSensor();
};

DistanceSensor::DistanceSensor() {

}

class MotorController {
public:
  MotorController(int leftPin, rightPin);

private:
  int leftPin_;
  int rightPin;
};

void setupMotorPins() {
  Serial.write("Initialize motor control pins\n");
  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  pinMode(MOTRO_RIGHT_PIN, OUTPUT);
}

void spinRight() {
  Serial.write("Rotate motor right\n");
  digitalWrite(MOTRO_RIGHT_PIN, HIGH);
  digitalWrite(MOTOR_LEFT_PIN, LOW);
}

void spinLeft() {
  Serial.write("Rotate motor left\n");
  digitalWrite(MOTOR_LEFT_PIN, HIGH);
  digitalWrite(MOTRO_RIGHT_PIN, LOW);
}

void stopMotor() {
  Serial.write("StopMotor\n");
  digitalWrite(MOTRO_RIGHT_PIN, LOW);
  digitalWrite(MOTOR_LEFT_PIN, LOW);
}

void setup() {
  Serial.begin(9600);

  setupMotorPins();
}

void loop() {
  spinRight();
  delay(5000);

  spinLeft();
  delay(5000);

  stopMotor();
  delay(5000);
}
