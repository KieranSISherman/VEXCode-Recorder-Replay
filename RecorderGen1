#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.
controller Controller = controller();
motor IntakeMotorA = motor(PORT10, true);
motor IntakeMotorB = motor(PORT5, false);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);

motor CatapultMotorA = motor(PORT11, true);
motor CatapultMotorB = motor(PORT4, false);
motor_group Catapult = motor_group(CatapultMotorA, CatapultMotorB);

bumper Booty = bumper(PORT6);
motor LeftDriveSmart = motor(PORT9, 1, false);
motor RightDriveSmart = motor(PORT3, 1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 200, 173, 76, mm, 1);



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration

//----------------------------------------------------------------------------
//                                                                            
//    Module:       main.cpp                                                  
//    Author:       {author}                                                  
//    Created:      {date}                                                    
//    Description:  IQ project                                                
//                                                                            
//----------------------------------------------------------------------------

// Include the IQ Library
#include "iq_cpp.h"

// Allows for easier use of the VEX Library
using namespace vex;

int Brain_precision = 0;

float timePoint, startTime;

int arrCount, arrCounter;

bool rec, autoOn, started;

float arr[370] = {}, arr2[370] = {};

void onevent_ControllerButtonRUp_pressed_0() {
  Catapult.spin(forward);
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 1;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonRUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 13;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonRDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 2;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonRDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 14;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonLUp_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 3;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonLUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 15;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonLDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 4;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonLDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 16;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonFUp_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    autoOn = false;
    arr[arrCount] = 5;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonFUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 17;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}
void onevent_ControllerButtonFDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    autoOn = true;
    arr[arrCount] = 6;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonFDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 18;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonEUp_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 7;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonEUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 19;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonEDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 8;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerButtonEDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 20;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

void onevent_ControllerAxisAChanged_0() {
  if (rec) {
    if (Controller.AxisA.position() > 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 9;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
    if (Controller.AxisA.position() < 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 10;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
  }
}

void onevent_ControllerAxisDChanged_0() {
  if (rec) {
    if (Controller.AxisD.position() > 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 11;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
    if (Controller.AxisD.position() < 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 12;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
  }
}

int whenStarted1() {
  autoOn = true;
  started = false;

  timePoint = 0.0;
  arrCount = 0.0;
  arrCounter = 0.0;

  Drivetrain.setDriveVelocity(100.0, percent);
  Catapult.setStopping(hold);
  Intake.setVelocity(100.0, percent);
  Catapult.setVelocity(100.0, percent);

  while (true) {
    if ((Controller.ButtonEUp.pressing()) && !rec && !started) {
      Brain.playNote(3, 0, 100);
      started = true;
      startTime = vex::timer::system();
      waitUntil (!(Controller.ButtonEUp.pressing()));
      wait(20,msec);
      rec = true;
    }
    if ((Controller.ButtonEDown.pressing()) && rec && started) {
      Brain.playNote(3, 1, 100);
      rec = false;
      waitUntil (!(Controller.ButtonEUp.pressing() && Controller.ButtonEDown.pressing()));
    }
    if (!rec && started) {
      Brain.Screen.print("Starting time is");
      Brain.Screen.newLine();
      Brain.Screen.print("%f", startTime);
      Brain.Screen.newLine();
      Brain.Screen.print("arrCount is");
      Brain.Screen.newLine();
      Brain.Screen.print("%f", arrCount);
      waitUntil(Controller.ButtonEUp.pressing());
      while (!(arrCounter == arrCount)) {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("%f", arr[arrCounter]);
        Brain.Screen.newLine();
        Brain.Screen.print("%f", arr[arrCounter + 1]);
        wait(1.5, seconds);
        waitUntil(Controller.ButtonEUp.pressing());
        arrCounter = arrCounter + 2.0;
        wait(20, msec);
      }
    }
    if (autoOn) {
      if (!Booty.pressing() && autoOn) {
        Catapult.spin(forward);
      }
    }
    wait(20,msec);
    }
  return 0;
}

// "when Booty pressed" hat block
void onevent_Booty_pressed_0() {
  Catapult.stop();
}

int main() {
  Booty.pressed(onevent_Booty_pressed_0);
  Controller.ButtonFUp.pressed(onevent_ControllerButtonFUp_pressed_0);
  Controller.ButtonFUp.released(onevent_ControllerButtonFUp_released_0);
  Controller.ButtonFDown.pressed(onevent_ControllerButtonFDown_pressed_0);
  Controller.ButtonFDown.released(onevent_ControllerButtonFDown_released_0);
  Controller.ButtonRUp.pressed(onevent_ControllerButtonRUp_pressed_0);
  Controller.ButtonRUp.released(onevent_ControllerButtonRUp_released_0);
  Controller.ButtonRDown.pressed(onevent_ControllerButtonRDown_pressed_0);
  Controller.ButtonRDown.released(onevent_ControllerButtonRDown_released_0);
  Controller.ButtonLUp.pressed(onevent_ControllerButtonLUp_pressed_0);
  Controller.ButtonLUp.released(onevent_ControllerButtonLUp_released_0);
  Controller.ButtonLDown.pressed(onevent_ControllerButtonLDown_pressed_0);
  Controller.ButtonLDown.released(onevent_ControllerButtonLDown_released_0);
  Controller.ButtonEUp.pressed(onevent_ControllerButtonEUp_pressed_0);
  Controller.ButtonEUp.released(onevent_ControllerButtonEUp_released_0);
  Controller.ButtonEDown.pressed(onevent_ControllerButtonEDown_pressed_0);
  Controller.ButtonEDown.released(onevent_ControllerButtonEDown_released_0);

  wait(15, msec);
  whenStarted1();
}
