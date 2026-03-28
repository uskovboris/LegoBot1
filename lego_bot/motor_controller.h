#pragma once

#include <AFMotor.h>

using Speed = uint8_t;

class MotorController {
public:
  MotorController(int forwardBackwardMotor, int leftRightMotof, Speed initialSpeed, Speed speedStep);

  void setSpeed(Speed speed);
  Speed getSpeed();

  void moveForward(unsigned int movingDuration);
  void moveBackward(unsigned int movingDuration);

  void turnLeft(unsigned int movingDuration);
  void turnRight(unsigned int movingDuration);
private:
  void speedUp(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration);
  void speedDown(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration);

  unsigned int calculateTimeQuant(Speed fromSpeed, Speed toSpeed, unsigned int movingDuration);

  Speed speed_;
  Speed speedStep_;

  AF_DCMotor forwardBackwardMotor_;
  AF_DCMotor leftRightMotor_;
};