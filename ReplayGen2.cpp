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
motor LeftDriveSmart = motor(PORT9, 1, false);
motor RightDriveSmart = motor(PORT3, 1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 200, 173, 76, mm, 1);
motor CatapultMotorA = motor(PORT11, true);
motor CatapultMotorB = motor(PORT4, false);
motor_group Catapult = motor_group(CatapultMotorA, CatapultMotorB);

motor IntakeMotorA = motor(PORT10, true);
motor IntakeMotorB = motor(PORT5, false);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);

bumper Booty = bumper(PORT6);
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

bool replayOn, autoOn, catapultSpinning, select1, buttonEnabled;

int arrCount, arrLen, select2;

float startTime, recStartTime, latency;

float arr[] = {};

//add stopping for drivetrain forward and backward
//add code to go back to loadInterface after the replay is done

void loadInterface() {
  buttonEnabled = true;
  select1 = true;
  select2 = 0;
  while(true) {
    if (select1 && buttonEnabled) {
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1,1);
      Brain.Screen.setPenColor(red);
      Brain.Screen.print("Load File")
      Brain.Screen.setCursor(2,1);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Run Imported Data");

      if (Controller.ButtonEDown.pressing()) {
        select1 = false;
      }
      
      if (Controller.ButtonFUp.pressing()) {
        buttonEnabled = false;
      }
    }
    if (!select1 && buttonEnabled) {
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(white);
      Brain.Screen.setCursor(1,1);
      Brain.Screen.print("Load File");
      Brain.Screen.setCursor(2,1);
      Brain.Screen.setPenColor(red);
      Brain.Screen.print("Run Imported Data");

      if (Controller.ButtonEUp.pressing()) {
        select1 = true;
      }

      if (Controller.ButtonFUp.pressing()) {
        arrLen = sizeof(arr)/sizeof(arr[0]);
        if (arrLen > 0) {
          playBack();
          break;
        }
        else {
          Brain.Screen.clearScreen();
          Brain.Screen.setCursor(1,1);
          Brain.Screen.setPenColor(white);
          Brain.Screen.print("No Imported Code");
          wait(5, seconds);
          Brain.Screen.clearScreen();
          select1 = true;
        }
      }
    }
    if (!buttonEnabled && select2 == 0) {
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1,1);
      Brain.Screen.setPenColor(red);
      Brain.Screen.print("Load Save 1");
      Brain.Screen.newLine();
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Load Save 2");
      Brain.Screen.newLine();
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Load Save 3");

      if (Controller.ButtonFUp.pressing()) {
        //code to load from save slot 1
        Brain.Screen.clearScreen();
        playBack();
        break;
      }

      if (Controller.ButtonEDown.pressing()) {
        select2 += 1;
      }
    }
    if (!buttonEnabled && select2 == 1) {
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1,1);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Load Save 1");
      Brain.Screen.newLine();
      Brain.Screen.setPenColor(red);
      Brain.Screen.print("Load Save 2");
      Brain.Screen.newLine();
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Load Save 3");

      if (Controller.ButtonFUp.pressing()) {
        //code to load from save slot 2
        Brain.Screen.clearScreen();
        playBack();
        break;
      }

      if (Controller.ButtonEDown.pressing()) {
        select2 += 1;
      }

      if (Controller.ButtonEUp.pressing()) {
        select2 -= 1;
      }
    }
    if (!buttonEnabled && select2 == 2) {
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1,1);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Load Save 1");
      Brain.Screen.newLine();
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Load Save 2");
      Brain.Screen.newLine();
      Brain.Screen.setPenColor(red);
      Brain.Screen.print("Load Save 3");

      if (Controller.ButtonFUp.pressing()) {
        //code to load from save slot 3
        Brain.Screen.clearScreen();
        playBack();
        break;
      }

      if (Controller.ButtonEUp.pressing()) {
        select2 -= 1;
      }
    }
  }
}

void playBack() {
  recStartTime = 0; //change zero to start time shown in recording program.
  latency = 0; //makes the timer take longer to start.
  arrCount = 0;
  arrLen = sizeof(arr)/sizeof(arr[0]);
  while (true) {
    if (autoOn) {
      if (!Booty) {
        Catapult.spin(forward);
      }
      else {
        if (!catapultSpinning) {
          Catapult.stop();
        }
      }
    }
    if (Controller.ButtonEUp.pressing()) {
      startTime = vex::timer::system();
      arrCount = 0;
      replayOn = true;
    }
    if (replayOn) {
      if (arr[arrCount] = 1) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        catapultSpinning = true;
        Catapult.spin(forward);
        arrCount += 2;
      }
      if (arr[arrCount] = 2) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        Catapult.spin(reverse);
        arrCount += 2;
      }
      if (arr[arrCount] = 3) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        Intake.spin(forward);
        arrCount += 2;
      }
      if (arr[arrCount] = 4) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        Intake.spin(reverse);
        arrCount += 2;
      }
      if (arr[arrCount] = 5) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        autoOn = false;
        arrCount += 2;
      }
      if (arr[arrCount] = 6) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        autoOn = true;
        arrCount += 2;
      }
      if (arr[arrCount] = 7) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
       waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        //robot movement here
        arrCount += 2;
      }
      if (arr[arrCount] = 8) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        //robot movement here
        arrCount += 2;
      }
      if (arr[arrCount] = 9) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        LeftDriveSmart.spin(forward);
        arrCount += 2;
      }
      if (arr[arrCount] = 10) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        RightDriveSmart.spin(forward);
        arrCount += 2;
      }
      if (arr[arrCount] = 11) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        LeftDriveSmart.spin(reverse);
        arrCount += 2;
      }
      if (arr[arrCount] = 12) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        RightDriveSmart.spin(reverse);
        arrCount += 2;
      }
      if (arr[arrCount] = 13) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        catapultSpinning = false;
        arrCount += 2;
      }
      if (arr[arrCount] = 14) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        Catapult.stop();
        arrCount += 2;
      }
      if (arr[arrCount] = 15) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        Intake.stop();
        arrCount += 2;
      }
      if (arr[arrCount] = 16) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        Intake.stop();
        arrCount += 2;
      }
      if (arr[arrCount] = 17) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        //robot movement here
        arrCount += 2;
      }
      if (arr[arrCount] = 18) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        //robot movement here
        arrCount += 2;
      }
      if (arr[arrCount] = 19) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        //robot movement here
        arrCount += 2;
      }
      if (arr[arrCount] = 20) {
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
          loadInterface();
        }
        waitUntil((arr[arrCount + 1] - recStartTime) == (vex::timer::system() - startTime - latency))
        //robot movement here
        arrCount += 2;
      }
    }
  }
  return 0;
}

int main() {
  loadInterface();
}