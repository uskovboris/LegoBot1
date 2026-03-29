#include "motor_controller.h"

const int MOTOR_FORWARD_BACKWARD = 1;
const int MOTOR_LEFT_RIGHT = 2;

MotorController motorController_(MOTOR_FORWARD_BACKWARD, MOTOR_LEFT_RIGHT);

void setup() {

  Serial.begin(9600);
}

void loop() {
  motorController_.moveForward(3000);
  motorController_.turnRight(1000);
}
