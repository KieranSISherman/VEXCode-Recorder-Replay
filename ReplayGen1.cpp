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
// Put robot motors, sensors, and motor groups here.



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

bool replayOn, autoOn, catapultSpinning;

int arrCount, arrLen;

float startTime, recStartTime, latency;

// Put information into the curly brackets below
float arr[] = {};

//add stopping for drivetrain forward and backward

// Function to playback the recording
void playBack() {
  
  //Setting the values of varibles
  recStartTime = 0; //change zero to start time shown in recording program.
  latency = 0; //makes the timer take longer to start.
  arrCount = 0;
  arrLen = sizeof(arr)/sizeof(arr[0]);
  
  while (true) {
   
    // Start playback when button E Up is pressed
    if (Controller.ButtonEUp.pressing()) {
      startTime = vex::timer::system();
      arrCount = 0;
      replayOn = true;
    }
    
    // Replay the recording is replay is on
    if (replayOn) {
      
      // R Up Button pressed
      if (arr[arrCount] == 1) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // R Down Button Pressed
      if (arr[arrCount] == 2) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // L Up Button Pressed
      if (arr[arrCount] == 3) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // L Down Button Pressed
      if (arr[arrCount] == 4) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // F Up Button Pressed
      if (arr[arrCount] == 5) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // F Down Button Pressed
      if (arr[arrCount] == 6) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // E Up Button Pressed
      if (arr[arrCount] == 7) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
       waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // E Down Button Pressed
      if (arr[arrCount] == 8) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // Joystick A Up True
      if (arr[arrCount] == 9) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // Joystick A Down True
      if (arr[arrCount] == 10) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // Joystick D Up True
      if (arr[arrCount] == 11) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // Joystick D Down True
      if (arr[arrCount] == 12) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // R Up Button Released
      if (arr[arrCount] == 13) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // R Down Button Released
      if (arr[arrCount] == 14) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // L Up Button Released
      if (arr[arrCount] == 15) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        // Robot Movement Here
        arrCount += 2;
      }
      
      // L Down Button Released
      if (arr[arrCount] == 16) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // F Up Button Released
      if (arr[arrCount] == 17) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // F Down Button Released
      if (arr[arrCount] == 18) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // E Up Button Released
      if (arr[arrCount] == 19) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // E Down Button Released
      if (arr[arrCount] == 20) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // Joystick A Up Released
      if (arr[arrCount] == 21) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // Joystick A Down Released
      if (arr[arrCount] == 22) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // Joystick D Up Released
      if (arr[arrCount] == 23) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
      // Joystick D Down Released
      if (arr[arrCount] == 24) {
        
        if (arrCount >= arrLen) {
          replayOn = false;
          arrCount = 0;
        }
        
        waitUntil((arr[arrCount + 1] - recStartTime) < (vex::timer::system() - startTime - latency));
        //robot movement here
        arrCount += 2;
      }
      
    }
    wait(20,msec);
  }
}

int main() {
  playBack();
}
