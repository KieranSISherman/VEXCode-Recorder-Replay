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


#pragma endregion VEXcode Generated Robot Configuration

//----------------------------------------------------------------------------
//                                                                            
//    Module:       main.cpp                                                  
//    Author:       Kieran Sherman                                                  
//    Created:      5/2/2022                                                    
//    Description:  A program to replay driver movement that has been recorded                                                
//                                                                            
//----------------------------------------------------------------------------

// Include the IQ Library
#include "iq_cpp.h"

// Allows for easier use of the VEX Library
using namespace vex;

bool replayOn;

float startTime, recStartTime, latency;

int ptrFltCon, ptrFltConTemp, ptrFlt, ptrFltConLen, ptrFltRev, ptrFltSave;

char infoChar[1200] = "";

void charFloatConverter() {
  ptrFlt = 0;
  ptrFltRev = 0;
  ptrFltConLen = trunc(log10(ptrFltCon)) + 1;
  
  while (ptrFltConLen != 0) {
    ptrFltConTemp = ptrFltCon % 10;
    ptrFltRev += ptrFltConTemp;
    ptrFltRev *= 10;
    ptrFltConLen -= 1;
    ptrFltCon = (ptrFltCon - ptrFltConTemp) / 10;
    wait(5,msec);
  }
  
  ptrFltRev /= 10;
  ptrFltConLen = trunc(log10(ptrFltRev)) + 1;

  while (ptrFltConLen != 0) {
    ptrFltConTemp = ptrFltRev % 10;
    ptrFlt += ptrFltConTemp;
    ptrFlt *= 10;
    ptrFltConLen -= 1;
    ptrFltRev = (ptrFltRev - ptrFltConTemp) / 10;
    wait(5,msec);
  }
  
  ptrFlt /= 10;
}

void playBack() {
  recStartTime = 0; //change zero to start time shown in recording program.
  latency = 0; //makes the timer take longer to start.
  char*ptr;
  ptr = strtok(infoChar, ",");
  
  while (true) {
    if (Controller.ButtonEUp.pressing()) {
      startTime = vex::timer::system();
      replayOn = true;
    }

    if (replayOn) {
      ptrFltCon = (int)strtod(ptr,NULL);
      charFloatConverter();
      ptrFltSave = ptrFlt;

      if (ptrFltSave == 1) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 2) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 3) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 4) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 6) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 7) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 8) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 13) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 14) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 15) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 16) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 18) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 19) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }
      if (ptrFltSave == 20) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        //movement here
      }

      //Left Drivetrain
      if (ptrFltSave == 25) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(100, percent);
        LeftDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 26) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(82, percent);
        LeftDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 27) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(49, percent);
        LeftDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 28) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(16, percent);
        LeftDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 29) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(0, percent);
        LeftDriveSmart.stop();
      }
      if (ptrFltSave == 30) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(16, percent);
        LeftDriveSmart.spin(forward);
      }
      if (ptrFltSave == 31) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(49, percent);
        LeftDriveSmart.spin(forward);
      }
      if (ptrFltSave == 32) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(82, percent);
        LeftDriveSmart.spin(forward);
      }
      if (ptrFltSave == 33) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        LeftDriveSmart.setVelocity(100, percent);
        LeftDriveSmart.spin(forward);
      }

      //Right Drivetrain
      if (ptrFltSave == 34) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(-100, percent);
        RightDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 35) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(82, percent);
        RightDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 36) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(49, percent);
        RightDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 37) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(16, percent);
        RightDriveSmart.spin(reverse);
      }
      if (ptrFltSave == 38) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(0, percent);
        RightDriveSmart.stop();
      }
      if (ptrFltSave == 39) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(16, percent);
        RightDriveSmart.spin(forward);
      }
      if (ptrFltSave == 40) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(49, percent);
        RightDriveSmart.spin(forward);
      }
      if (ptrFltSave == 41) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(82, percent);
        RightDriveSmart.spin(forward);
      }
      if (ptrFltSave == 42) {
        ptr = strtok(NULL, ",");
        charFloatConverter();
        waitUntil((ptrFlt - recStartTime) >= (vex::timer::system() - startTime - latency));
        RightDriveSmart.setVelocity(100, percent);
        RightDriveSmart.spin(forward);
      }
    ptr = strtok(NULL, ",");
    }
  }
}

int main() {
  playBack();
}
