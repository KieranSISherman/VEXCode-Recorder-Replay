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
// Put motors, ports, sensors, and motor groups here.


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

//Establishing Varibles
int Brain_precision = 0;

float timePoint, startTime;

int arrCount, arrCounter;

bool rec, autoOn, started;

//Arrays for storing the recorded data
float arr[370] = {}, arr2[370] = {};

//When controller button R Up is pressed
void onevent_ControllerButtonRUp_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 1;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}
//When controller button R Up is released
void onevent_ControllerButtonRUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 13;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button R Down is pressed
void onevent_ControllerButtonRDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 2;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller Button R Down is released
void onevent_ControllerButtonRDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 14;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller L Up is pressed
void onevent_ControllerButtonLUp_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 3;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller L Up is released
void onevent_ControllerButtonLUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 15;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button L Down is pressed
void onevent_ControllerButtonLDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 4;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button L Down is released
void onevent_ControllerButtonLDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 16;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controllr button F Up is pressed
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

//When controller button F Up is released
void onevent_ControllerButtonFUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 17;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button F Down is pressed
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

//When controller button F Down is released
void onevent_ControllerButtonFDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 18;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button E Up is pressed
void onevent_ControllerButtonEUp_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 7;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button E Up is released
void onevent_ControllerButtonEUp_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 19;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button E Down is pressed
void onevent_ControllerButtonEDown_pressed_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 8;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When controller button E Down is released
void onevent_ControllerButtonEDown_released_0() {
  if (rec) {
    timePoint = vex::timer::system();
    arr[arrCount] = 20;
    arrCount = arrCount + 1;
    arr[arrCount] = timePoint;
    arrCount = arrCount + 1;
  }
}

//When the left joystick is moved
void onevent_ControllerAxisAChanged_0() {
  if (rec) {
    
    //When the left joystick is moved forward
    if (Controller.AxisA.position() > 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 9;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
    
    //When the left joystick is moved backward
    if (Controller.AxisA.position() < 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 10;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
  }
}

//When the right joystick is moved
void onevent_ControllerAxisDChanged_0() {
  if (rec) {
    
    //When the right joystick is moved forward
    if (Controller.AxisD.position() > 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 11;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
    
    //When the right joystick is moved backward
    if (Controller.AxisD.position() < 0.0) {
      timePoint = vex::timer::system();
      arr[arrCount] = 12;
      arrCount = arrCount + 1;
      arr[arrCount] = timePoint;
      arrCount = arrCount + 1;
    }
  }
}

//When started function
int whenStarted1() {
  
  //Assigning varibles
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
    
    //Starting the recording
    if ((Controller.ButtonEUp.pressing()) && !rec && !started) {
      Brain.playNote(3, 0, 100);
      started = true;
      startTime = vex::timer::system();
      waitUntil (!(Controller.ButtonEUp.pressing()));
      wait(20,msec);
      rec = true;
    }
    
    //Stopping the recording
    if ((Controller.ButtonEDown.pressing()) && rec && started) {
      Brain.playNote(3, 1, 100);
      rec = false;
      waitUntil (!(Controller.ButtonEUp.pressing() && Controller.ButtonEDown.pressing()));
    }
    
    //Printing the information to the brain after the recording has ended
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
    wait(20,msec);
    }
  return 0;
}


int main() {
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
