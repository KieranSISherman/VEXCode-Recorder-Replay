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
motor LeftDriveSmart = motor(PORT9, 1, false);
motor RightDriveSmart = motor(PORT3, 1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 200, 173, 76, mm, 1);
motor CatapultMotorA = motor(PORT11, true);
motor CatapultMotorB = motor(PORT4, false);
motor_group Catapult = motor_group(CatapultMotorA, CatapultMotorB);

motor IntakeMotorA = motor(PORT10, false);
motor IntakeMotorB = motor(PORT5, true);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);

bumper Booty = bumper(PORT6);
controller Controller = controller();



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool ControllerLeftShoulderControlMotorsStopped = true;
bool ControllerRightShoulderControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller = true;
bool DrivetrainRNeedsToBeStopped_Controller = true;

// define a task that will handle monitoring inputs from Controller
int rc_auto_loop_function_Controller() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = AxisA
      // right = AxisD
      int drivetrainLeftSideSpeed = Controller.AxisA.position();
      int drivetrainRightSideSpeed = Controller.AxisD.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
      // check the ButtonLUp/ButtonLDown status to control Intake
      if (Controller.ButtonLUp.pressing()) {
        Intake.spin(forward);
        ControllerLeftShoulderControlMotorsStopped = false;
      } else if (Controller.ButtonLDown.pressing()) {
        Intake.spin(reverse);
        ControllerLeftShoulderControlMotorsStopped = false;
      } else if (!ControllerLeftShoulderControlMotorsStopped) {
        Intake.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        ControllerLeftShoulderControlMotorsStopped = true;
      }
      // check the ButtonRUp/ButtonRDown status to control Catapult
      if (Controller.ButtonRUp.pressing()) {
        Catapult.spin(forward);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (Controller.ButtonRDown.pressing()) {
        Catapult.spin(reverse);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (!ControllerRightShoulderControlMotorsStopped) {
        Catapult.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        ControllerRightShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

task rc_auto_loop_task_Controller(rc_auto_loop_function_Controller);
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
#include <thread>

// Allows for easier use of the VEX Library
using namespace vex;

bool AutoOn;

// "when started" hat block
int whenStarted1() {
  while (!(!Booty.pressing())) {
    if (Controller.ButtonRUp.pressing()) {
      Catapult.spin(forward);
    }
  wait(20, msec);
  }
  return 0;
}

void shutdown() { 
  Brain.playNote(7, 4.5, 250); //maybe 4.5 if flat
  //Brain.playNote(2, 5, 500);
  //Brain.playNote(3, 2, 500);
  Brain.playNote(6, 1.5, 250); //maybe 1.5 if flat
  Brain.playNote(6, 4.5, 250); //maybe 4.5 if flat
  Brain.playNote(6, 5.5, 250); //maybe 5.5 if flat
  //Brain.playNote(2, 6, 250);
  //Brain.playNote(3, 1, 250);
  wait(20, msec);
  exit(0);
}


// "when started" hat block
int whenStarted2() {
  AutoOn = true;
  Drivetrain.setDriveVelocity(100.0, percent);
  Drivetrain.setStopping(hold);
  Catapult.setStopping(hold);
  Intake.setVelocity(100.0, percent);
  Intake.setStopping(hold);
  Catapult.setVelocity(100.0, percent);
  while (true) {
    if (Controller.ButtonFUp.pressing()) {
      AutoOn = false;
    }
    if (Controller.ButtonFDown.pressing()) {
      AutoOn = true;
    }
    if (Controller.ButtonEUp.pressing() && Controller.ButtonEDown.pressing() && Controller.ButtonFUp.pressing() && Controller.ButtonFDown.pressing()) {
      shutdown();
    }
  wait(20, msec);
  }
  return 0;
}

// "when started" hat block
int whenStarted3() {
  while (true) {
    if (AutoOn) {
      if (!Controller.ButtonRUp.pressing()) {
        if (Booty.pressing()) {
          Catapult.stop();
        }
        else {
          Catapult.spin(forward);
        }
      }
    }
  wait(20, msec);
  }
  return 0;
}

int main() {
  vex::task ws1 (whenStarted2);
  vex::task ws2 (whenStarted3);
  whenStarted1();
}
