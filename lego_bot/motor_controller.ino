#include "motor_controller.h"

#include <math.h>

MotorController::MotorController(int forwardBackwardMotor, int leftRightMotor, Speed initialSpeed, Speed finalSpeed, Speed speedStep)
  : forwardBackwardMotor_(forwardBackwardMotor), leftRightMotor_(leftRightMotor), initialSpeed_(initialSpeed), finalSpeed_(finalSpeed), speedStep_(speedStep), speed_(0) {
}

void MotorController::setSpeed(Speed speed) {
  Serial.print("Set speed ");
  Serial.print(speed);
  Serial.print("\n");
  speed_ = speed;
}

Speed MotorController::getSpeed() {
  return speed_;
}

void MotorController::moveForward(unsigned int movingDuration) {
  Serial.print("Move forward ");
  Serial.print(movingDuration);
  Serial.print(" seconds\n");

  forwardBackwardMotor_.run(RELEASE);

  //Motor spinning anti-clockwise
  forwardBackwardMotor_.run(BACKWARD);

  speedUp(initialSpeed_, finalSpeed_, movingDuration);

  speedDown(finalSpeed_, initialSpeed_, movingDuration);

  // Now turn off motor
  forwardBackwardMotor_.run(RELEASE);
}

void MotorController::moveBackward(unsigned int movingDuration) {
}

void MotorController::turnLeft(unsigned int movingDuration) {
  delay(movingDuration);
}

void MotorController::turnRight(unsigned int movingDuration) {
  delay(movingDuration);
}

void MotorController::speedUp(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration) {
  unsigned int timeQuant = calculateTimeQuant(fromSpeed, toSpeed, movingDuration);
  for (uint8_t i = fromSpeed; i < toSpeed; i += speedStep_) {
    forwardBackwardMotor_.setSpeed(i);
    setSpeed(i);
    delay(timeQuant);
  }
}

void MotorController::speedDown(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration) {
  unsigned int timeQuant = calculateTimeQuant(fromSpeed, toSpeed, movingDuration);
  for (uint8_t i = fromSpeed; i != toSpeed; i -= speedStep_) {
    forwardBackwardMotor_.setSpeed(i);
    setSpeed(i);
    delay(timeQuant);
  }
}

unsigned int MotorController::calculateTimeQuant(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration) {
  unsigned int speedDiff = abs(fromSpeed - toSpeed);
  unsigned int timeQuantsCount = speedDiff / speedStep_;
  unsigned int timeQuant = movingDuration / timeQuantsCount;
  return timeQuant;
}
