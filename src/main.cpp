#include "vex.h"

using namespace vex;

competition Competition;

controller Controller = controller();

motor DriveMotorBackLeft = motor(PORT1, true);
motor DriveMotorBackRight = motor(PORT2, true);
motor DriveMotorFrontLeft = motor(PORT3, true);
motor DriveMotorFrontRight = motor(PORT4, true);

motor_group DriveMotorGroupLeft = motor_group(DriveMotorBackLeft, DriveMotorFrontLeft);
motor_group DriveMotorGroupRight = motor_group(DriveMotorBackRight, DriveMotorFrontRight);

void drive() {
  float ControllerHorizontalAxis =  controller.Axis4.position()^3/10000;
  float ControllerVerticleAxis = controller.Axis2.position()^3/10000;

  DriveMotorGroupLeft.spin(forward, ControllerVerticleAxis + ControllerHorizontalAxis, pct);
  DriveMotorGroupRight.spin(forward, ControllerVerticleAxis - ControllerHorizontalAxis, pct);
}

void pre_auton() {
  // pre auton
}

void autonomous() {
  // auton
}

void usercontrol() {
  while (1) {
    // user controls
    wait(20, msec);               
  }
}

int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
