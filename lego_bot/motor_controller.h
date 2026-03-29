#pragma once

#include <AFMotor.h>

using Speed = uint8_t;

class MotorController {
public:
  MotorController(int forwardBackwardMotor, int leftRightMotor);

  void moveForward(unsigned int movingDuration);
  void moveBackward(unsigned int movingDuration);

  void turnLeft(unsigned int movingDuration);
  void turnRight(unsigned int movingDuration);
private:
  static constexpr uint8_t LEGO_MOTOR_SPEED = 255;

  AF_DCMotor forwardBackwardMotor_;
  AF_DCMotor leftRightMotor_;
};