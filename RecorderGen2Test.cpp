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
inertial BrainInertial = inertial();
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

//Initilizing Variables
int Brain_precision = 0;

float timePoint, startTime;

int arrCount, arrCounter, select2, arr1len, arr2len, arr3len, motorNum;

bool rec, autoOn, started, select1, buttonEnable1, save, leftJoystickUp, leftJoystickDown, rightJoystickUp, rightJoystickDown;

float arr[368] = {}, arr2[368] = {}, arr3[368] = {};

//Setting varibles to the lengths of the arrays
void arrLengths() {
  arr1len = sizeof(arr)/sizeof(arr[0]);
  arr2len = sizeof(arr2)/sizeof(arr2[0]);
  arr3len = sizeof(arr3)/sizeof(arr3[0]);

  //Tests if there is still recording space
  if (arr3len == 368) {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.playNote(5,1,1000);
    Brain.Screen.print("Ran out of recording space")
  }
}

void arr1() {
  arr[arrCount] = motorNum;
  arrCount = arrCount + 1;
  arr[arrCount] = timePoint;
  arrCount = arrCount + 1;
  arrLengths();
}

void arr2() {
  arr2[arrCount] = motorNum;
  arrCount = arrCount + 1;
  arr2[arrCount] = timePoint;
  arrCount = arrCount + 1;
  arrLengths();
}

void arr3() {
  arr3[arrCount] = motorNum;
  arrCount = arrCount + 1;
  arr3[arrCount] = timePoint;
  arrCount = arrCount + 1;
  arrLengths();
}

//When controller button R Up is pressed
void onevent_ControllerButtonRUp_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 1;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button R Up is released
void onevent_ControllerButtonRUp_released_0() {
  timePoint - vex::timer::system();
  motorNum = 13;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button R Down is pressed
void onevent_ControllerButtonRDown_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 2;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller Button R Down is released
void onevent_ControllerButtonRDown_released_0() {
  timePoint - vex::timer::system();
  motorNum = 14;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller L Up is pressed
void onevent_ControllerButtonLUp_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 3;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller L Up is released
void onevent_ControllerButtonLUp_released_0() {
  timePoint - vex::timer::system();
  motorNum = 15;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button L Down is pressed
void onevent_ControllerButtonLDown_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 4;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button L Down is released
void onevent_ControllerButtonLDown_released_0() {
  timePoint - vex::timer::system();
  motorNum = 16;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controllr button F Up is pressed
void onevent_ControllerButtonFUp_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 5;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button F Up is released
void onevent_ControllerButtonFUp_released_0() {
  timePoint - vex::timer::system();
  motorNum = 17;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button F Down is pressed
void onevent_ControllerButtonFDown_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 6;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button F Down is released
void onevent_ControllerButtonFDown_released_0() {
  timePoint - vex::timer::system();
  motorNum = 18;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button E Up is pressed
void onevent_ControllerButtonEUp_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 7;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button E Up is released
void onevent_ControllerButtonEUp_released_0() {
  timePoint - vex::timer::system();
  motorNum = 19;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button E Down is pressed
void onevent_ControllerButtonEDown_pressed_0() {
  timePoint - vex::timer::system();
  motorNum = 8;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When controller button E Down is released
void onevent_ControllerButtonEDown_released_0() {
  timePoint - vex::timer::system();
  motorNum = 20;

  if (rec && arr1len != 368) {
    arr1();
  }
  if (rec && arr2len != 368 && arr1len == 368) {
    arr2();
  }
  if (rec && arr3len != 368 && arr2len == 368) {
    arr3();
  }
}

//When the left joystick is moved
void onevent_ControllerAxisAChanged_0() {
  if (rec) {
    
    //When the left joystick is moved forward
    if (Controller.AxisA.position() > 0.0) {
      timePoint - vex::timer::system();
      motorNum = 9;

      if (rec && arr1len != 368) {
        arr1();
        leftJoystickUp = true;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        leftJoystickUp = true;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        leftJoystickUp = true;
      }
    }

    if (Controller.AxisA.position() <= 0.0 && leftJoystickUp) {
      timePoint - vex::timer::system();
      motorNum = 21;

      if (rec && arr1len != 368) {
        arr1();
        leftJoystickUp = false;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        leftJoystickUp = false;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        leftJoystickUp = false;
      }
    }
    
    //When the left joystick is moved backward
    if (Controller.AxisA.position() < 0.0) {
      timePoint - vex::timer::system();
      motorNum = 10;

      if (rec && arr1len != 368) {
        arr1();
        leftJoystickdown = true;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        leftJoystickdown = true;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        leftJoystickdown = true;
      }
    }

    if (Controller.AxisA.position() >= 0.0 && leftJoystickDown) {
      timePoint - vex::timer::system();
      motorNum = 22;

      if (rec && arr1len != 368) {
        arr1();
        leftJoystickdown = false;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        leftJoystickdown = false;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        leftJoystickdown = false;
      }
    }
  }
}

//When the right joystick is moved
void onevent_ControllerAxisDChanged_0() {
  if (rec) {
    
    //When the right joystick is moved forward
    if (Controller.AxisD.position() > 0.0) {
      timePoint - vex::timer::system();
      motorNum = 11;

      if (rec && arr1len != 368) {
        arr1();
        rightJoystickUp = true;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        rightJoystickUp = true;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        rightJoystickUp = true;
      }
    }

    if (Controller.AxisD.position() <= 0.0 && rightJoystickUp) {
      timePoint - vex::timer::system();
      motorNum = 23;

      if (rec && arr1len != 368) {
        arr1();
        rightJoystickUp = false;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        rightJoystickUp = false;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        rightJoystickUp = false;
      }
    }

    if (Controller.AxisD.position() < 0.0) {
      timePoint - vex::timer::system();
      motorNum = 12;

      if (rec && arr1len != 368) {
        arr1();
        rightJoystickDown = true;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        rightJoystickDown = true;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        rightJoystickDown = true;
      }
    }

    if (Controller.AxisD.position() >= 0.0) {
      timePoint - vex::timer::system();
      motorNum = 24;

      if (rec && arr1len != 368) {
        arr1();
        rightJoystickDown = false;
      }
      if (rec && arr2len != 368 && arr1len == 368) {
        arr2();
        rightJoystickDown = false;
      }
      if (rec && arr3len != 368 && arr2len == 368) {
        arr3();
        rightJoystickDown = false;
      }
    }
  }
}

//When started function
int whenStarted1() {
  //Assigning varibles
  select1 = true;
  autoOn = true;
  started = false;
  buttonEnable1 = true;
  save = false;
  leftJoystickUp = false;
  leftJoystickDown = false;
  rightJoystickUp = false;
  rightJoystickDown = false;

  timePoint = 0.0;
  arrCount = 0.0;
  arrCounter = 0.0;
  select2 = 0.0;

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

    //Brain select interface
    if (!rec && started && !save) {

      //Interace 1 selection
      if (select1 && buttonEnable1) {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(red);
        Brain.Screen.print("Save Data");
        Brain.Screen.setPenColor(white);
        Brain.Screen.setCursor(2,1);
        Brain.Screen.print("Print Data");

        if (Controller.ButtonEDown.pressing()) {
          select1 = false;
        }

        if (Controller.ButtonFUp.pressing()) {
          buttonEnable1 = false;
        }
        wait(20,msec);
      }

      //Interface 1 selection
      if (!select1 && buttonEnable1 && !save) {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Save Data");
        Brain.Screen.setPenColor(red);
        Brain.Screen.setCursor(2,1);
        Brain.Screen.print("Print Data");

        if (Controller.ButtonEUp.pressing()) {
          select1 = true;
        }
        wait(20,msec);

        if (Controller.ButtonFUp.pressing()) {

          if (!rec && started) {
            Brain.Screen.setPenColor(white);
            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(1,1);
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
            Brain.Screen.clearScreen();
          }
        }
      }

      //Interface 2 selection
      if (select2 == 0 && !buttonEnable1 && !save) {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(red);
        Brain.Screen.print("Save Slot 1");
        Brain.Screen.setCursor(2,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Save Slot 2");
        Brain.Screen.setCursor(3,1);
        Brain.Screen.print("Save Slot 3");
        waitUntil(!(Controller.ButtonFUp.pressing()));

        if (Controller.ButtonEDown.pressing()) {
          select2 += 1;
        }

        if (Controller.ButtonFUp.pressing()) {
          save = true;
        }

        if (Controller.ButtonFDown.pressing()) {
          buttonEnable1 = true;
        }
        wait(100,msec);
      }

      //Saving to slot 1
      if (save && select2 == 0) {
        waitUntil(!(Controller.ButtonFUp.pressing()) && !(Controller.ButtonFDown.pressing()));
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Saving to slot 1");

        int nWritten = Brain.SDcard.savefile("Slot1.h", (arr[] + arr2[] + arr3[]), sizeof(arr[] + arr2[] + arr3[]));
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        wait(20,msec);

        if( nWritten > 0) {
          // display on screen how many bytes we wrote
          Brain.Screen.setCursor( 2, 2 );
          Brain.Screen.print( "Wrote %d bytes to the SD Card", nWritten );

        wait(2.5, seconds);
        Brain.Screen.clearScreen();
        wait(20,msec);
      }

      //Interface 2 selection 
      if (select2 == 1 && !buttonEnable1 && !save) {
        waitUntil(!(Controller.ButtonFUp.pressing()) && !(Controller.ButtonFDown.pressing()));
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Save Slot 1");
        Brain.Screen.setCursor(2,1);
        Brain.Screen.setPenColor(red);
        Brain.Screen.print("Save Slot 2");
        Brain.Screen.setCursor(3,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Save Slot 3");
        waitUntil(!(Controller.ButtonFUp.pressing()));

        if (Controller.ButtonEDown.pressing()) {
          select2 += 1;
        }

        if (Controller.ButtonEUp.pressing()) {
          select2 = select2 - 1;
        }

        if (Controller.ButtonFUp.pressing()) {
          save = true;
        }

        if (Controller.ButtonFDown.pressing()) {
          buttonEnable1 = true;
        }
        wait(100,msec);

      }

      //Saving to slot 2
      if (save && select2 == 1) {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Saving to slot 2");

        int nWritten = Brain.SDcard.savefile("Slot2.h", (arr[] + arr2[] + arr3[]), sizeof(arr[] + arr2[] + arr3[]));
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        wait(20,msec);

        if( nWritten > 0) {
          // display on screen how many bytes we wrote
          Brain.Screen.setCursor( 2, 2 );
          Brain.Screen.print( "Wrote %d bytes to the SD Card", nWritten );

        wait(2.5, seconds);
        Brain.Screen.clearScreen();
        wait(20,msec);
      }

      //Interface 2 selection
      if (select2 == 2 && !buttonEnable1 && !save) {
        waitUntil(!(Controller.ButtonFUp.pressing()) && !(Controller.ButtonFDown.pressing()));
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Save Slot 1");
        Brain.Screen.setCursor(2,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Save Slot 2");
        Brain.Screen.setCursor(3,1);
        Brain.Screen.setPenColor(red);
        Brain.Screen.print("Save Slot 3");
        waitUntil(!(Controller.ButtonFUp.pressing()));

        if (Controller.ButtonEUp.pressing()) {
          select2 = select2 - 1;
        }

        if (Controller.ButtonFUp.pressing()) {
          save = true;
        }

        if (Controller.ButtonFDown.pressing()) {
          buttonEnable1 = true;
        }

        wait(100,msec);
      }

      //Saving to slot 3
      if (save && select2 == 2) {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.setPenColor(white);
        Brain.Screen.print("Saving to slot 3");

        int nWritten = Brain.SDcard.savefile("Slot3.h", (arr[] + arr2[] + arr3[]), sizeof(arr[] + arr2[] + arr3[]));
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        wait(20,msec);

        if( nWritten > 0) {
          // display on screen how many bytes we wrote
          Brain.Screen.setCursor( 2, 2 );
          Brain.Screen.print( "Wrote %d bytes to the SD Card", nWritten );

        wait(2.5, seconds);
        Brain.Screen.clearScreen();
        wait(20,msec);
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
