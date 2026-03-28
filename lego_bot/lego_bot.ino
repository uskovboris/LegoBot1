#include "motor_controller.h"

const int MOTOR_FORWARD_BACKWARD = 1;
const int MOTOR_LEFT_RIGHT = 2;

MotorController motorController_(MOTOR_FORWARD_BACKWARD, MOTOR_LEFT_RIGHT, 0, 255, 50);

void setup() {

  Serial.begin(9600);
}

void loop() {
  motorController_.moveForward(10000);

  motorController_.moveBackward(10000);
}
