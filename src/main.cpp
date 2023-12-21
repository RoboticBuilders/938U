#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

controller driver = controller();

motor fl = motor(PORT1);
motor ml = motor(PORT2);
motor bl = motor(PORT3);
motor fr = motor(PORT4);
motor mr = motor(PORT5);
motor br = motor(PORT6);

motor_group left = motor_group(fl, ml, bl);
motor_group right = motor_group(fr, mr, br);

void joystick_curve(int axis, int reading) {
  // front-back
  if (axis == 2) {
    int speed = float(sqrt(reading) / 100);
    
  }

  // left-right
  if (axis == 4) {
    int left_speed = float(sqrt(reading) / 100);
    int right_speed = -1 * float(sqrt(reading) / 100);
  }
}

void pre_auton(void) {

}

void autonomous(void) {
}

void usercontrol(void) {
  while (1) {
    // implementation of joystick curves

    // front-back joystick curve
    if (driver.Axis2.position() != 0) {
      int axis_2_pos = driver.Axis2.position();
      joystick_curve(2, axis_2_pos);
    }

    // right-left joystick curve
    if (driver.Axis4.position() != 0) {
      int axis_4_pos = driver.Axis4.position();
      joystick_curve(4, axis_4_pos);
    }
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
