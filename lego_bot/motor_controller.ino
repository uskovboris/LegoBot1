#include "motor_controller.h"

#include <math.h>

MotorController::MotorController(int forwardBackwardMotor, int leftRightMotor)
  : forwardBackwardMotor_(forwardBackwardMotor), leftRightMotor_(leftRightMotor) {
}

void MotorController::moveForward(unsigned int movingDuration) {
  Serial.print("Move forward ");
  Serial.print(movingDuration);
  Serial.print(" seconds\n");

  leftRightMotor_.run(RELEASE);

  //Motor spinning anti-clockwise
  forwardBackwardMotor_.run(BACKWARD);
  forwardBackwardMotor_.setSpeed(LEGO_MOTOR_SPEED);

  delay(movingDuration);

  // Now turn off motor
  forwardBackwardMotor_.run(RELEASE);
}


void MotorController::moveBackward(unsigned int movingDuration) {
  Serial.print("Move backward ");
  Serial.print(movingDuration);
  Serial.print(" seconds\n");

  leftRightMotor_.run(RELEASE);

  //Motor spinning clockwise
  forwardBackwardMotor_.run(FORWARD);
  forwardBackwardMotor_.setSpeed(LEGO_MOTOR_SPEED);

  delay(movingDuration);

  // Now turn off motor
  forwardBackwardMotor_.run(RELEASE);
}

void MotorController::turnLeft(unsigned int movingDuration) {
  Serial.print("Tern left ");
  Serial.print(movingDuration);
  Serial.print(" seconds\n");

  // forwardBackwardMotor_.setSpeed(finalSpeed_);
  leftRightMotor_.setSpeed(LEGO_MOTOR_SPEED);
  leftRightMotor_.run(BACKWARD);

  forwardBackwardMotor_.run(FORWARD);
  forwardBackwardMotor_.setSpeed(LEGO_MOTOR_SPEED);

  delay(movingDuration);

  // Now turn off motors
  forwardBackwardMotor_.run(RELEASE);
  leftRightMotor_.run(RELEASE);
}

void MotorController::turnRight(unsigned int movingDuration) {
  Serial.print("Tern right ");
  Serial.print(movingDuration);
  Serial.print(" seconds\n");

  leftRightMotor_.run(FORWARD);
  leftRightMotor_.setSpeed(LEGO_MOTOR_SPEED);

  forwardBackwardMotor_.run(FORWARD);
  forwardBackwardMotor_.setSpeed(LEGO_MOTOR_SPEED);

  delay(movingDuration);

  // Now turn off motors
  forwardBackwardMotor_.run(RELEASE);
  leftRightMotor_.run(RELEASE);
}
