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
  float ControllerHorizontalAxis = pow(controller.Axis4.position(), 3) / 10000.0;
  float ControllerVerticalAxis = pow(controller.Axis4.position(), 3) / 10000;

  DriveMotorGroupLeft.spin(forward, ControllerVerticalAxis + ControllerHorizontalAxis, pct);
  DriveMotorGroupRight.spin(forward, ControllerVerticalAxis - ControllerHorizontalAxis, pct);
}

void gtaDrive() {
  float ControllerHorizontalAxis = pow(controller.Axis4.position(), 3) / 10000.0;
  if (controller.ButtonR1.pressing()) {
    float ControllerVerticalAxis = 100;
  }
  else if (controller.ButtonR2.pressing()) {
    float ControllerVerticalAxis = -100;
  }
  else {
    float ControllerVerticalAxis = 0;
  }
  DriveMotorGroupLeft.spin(forward, ControllerVerticalAxis + ControllerHorizontalAxis, pct);
  DriveMotorGroupRight.spin(forward, ControllerVerticalAxis - ControllerHorizontalAxis, pct);
}

void pre_auton() {
  // pre auton
}

void autonomous() {
  // auton
}

void usercontrol() {
  while (1) {
    drive()
    // gtaDrive()
    // ^ you could kill me before making me uncomment that line
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
