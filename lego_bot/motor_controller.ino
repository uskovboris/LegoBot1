#include "motor_controller.h"

#include <math.h>

MotorController::MotorController(int forwardBackwardMotor, int leftRightMotor, Speed initialSpeed, Speed speedStep)
  : forwardBackwardMotor_(forwardBackwardMotor), leftRightMotor_(leftRightMotor), speed_(initialSpeed), speedStep_(speedStep) {
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

  speedUp(0, getSpeed(), movingDuration);

  speedDown(getSpeed(), 0, movingDuration);

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
  Serial.print("timeQuant: ");
  Serial.print(static_cast<int>(timeQuant));
  Serial.print(" seconds\n");

  for (uint8_t i = fromSpeed; i < toSpeed; i += speedStep_) {
    forwardBackwardMotor_.setSpeed(i);
    delay(timeQuant);
  }
}

void MotorController::speedDown(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration) {
  unsigned int timeQuant = calculateTimeQuant(fromSpeed, toSpeed, movingDuration);
  for (uint8_t i = fromSpeed; i != toSpeed; i -= speedStep_) {
    forwardBackwardMotor_.setSpeed(i);
    delay(timeQuant);
  }
}

unsigned int MotorController::calculateTimeQuant(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration) {
  unsigned int timeQuantsCount = abs(fromSpeed - toSpeed) / speedStep_;
  return movingDuration / timeQuantsCount;
}
