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
#pragma endregion VEXcode Generated Robot Configuration

//----------------------------------------------------------------------------
//                                                                            
//    Module:       main.cpp                                                  
//    Author:       Kieran Sherman                                                
//    Created:      4/26/2022                                                    
//    Description:  Driver movement recording program                                                
//                                                                            
//----------------------------------------------------------------------------

// Include the IQ Library
#include "iq_cpp.h"

// Allows for easier use of the VEX Library
using namespace vex;

//Initilizing Variables
int Brain_precision = 0;

uint32_t timePoint, timePointRev, timePointRevTemp;

float motorNum;

int timePointLen, startTime, arrCount, arrCounter, select2, arr1len, arr2len, arr3len;

bool rec, autoOn, started, select1, buttonEnable1, save, leftJoystickUp, leftJoystickDown, rightJoystickUp, rightJoystickDown;

//Saves a number corresponding to what button was pressed/released to the SD card
void motorNumSdSave() {
  
  if(motorNum == 1) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 2) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 3) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 4) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 5) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 6) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 7) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 8) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 9) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 10) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"10", sizeof("10"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 11) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 12) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 13) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 14) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 15) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 16) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 17) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 18) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 19) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 20) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 21) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 22) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 23) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if(motorNum == 24) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  //The following are only for the joysticks.
  if (motorNum == 26) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.05) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.1) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.15) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.2) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.25) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.3) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  if (motorNum == 26.35) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.4) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.4) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.5) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.55) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.6) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.65) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.7) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.75) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.8) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.85) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.9) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 26.95) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 27) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.95) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.9) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.85) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.8) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.75) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.7) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.65) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.6) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.55) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.5) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.45) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.4) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.35) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.3) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.25) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.2) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.15) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.1) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25.05) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 25) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.05) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.1) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.15) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.2) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.25) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.3) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.35) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.4) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.45) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.5) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.55) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.6) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.65) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.7) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.75) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.8) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.8) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.9) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 29.95) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 30) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 27) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.05) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.1) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.15) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.2) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.25) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.3) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.35) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.4) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.45) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.5) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.55) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.6) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.65) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.7) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.75) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.8) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.85) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.9) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
  
  if (motorNum == 28.95) {
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)".", sizeof("."));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
    Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
  }
}

//Saves the time that a button was pressed/released to the SD card
void timePointSdSave() {
  
  //reverses the number
  timePointRev = 0;
  timePointLen = trunc(log10(timePoint)) + 1;
  while (timePointLen != 0) {
    timePointRevTemp = timePoint % 10;
    timePointRev += timePointRevTemp;
    timePointRev *= 10;
    timePointLen -= 1;
    timePoint = (timePoint - timePointRevTemp) / 10;
    wait(5,msec);
  }
  timePointLen = trunc(log10(timePointRev)) + 1;
  timePointRev /= 10;
  
  //Save the time from back to from, reversing it again.
  while(timePointLen != 0) {
    
    timePointRevTemp = timePointRev % 10;
    
    if (timePointRevTemp == 0) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"0", sizeof("0"));
      timePointRev -= 0;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 1) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"1", sizeof("1"));
      timePointRev -= 1;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 2) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"2", sizeof("2"));
      timePointRev -= 2;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 3) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"3", sizeof("3"));
      timePointRev -= 3;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 4) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"4", sizeof("4"));
      timePointRev -= 4;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 5) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"5", sizeof("5"));
      timePointRev -= 5;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 6) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"6", sizeof("6"));
      timePointRev -= 6;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 7) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"7", sizeof("7"));
      timePointRev -= 7;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 8) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"8", sizeof("8"));
      timePointRev -= 8;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    if (timePointRevTemp == 9) {
      Brain.SDcard.appendfile("slot1.txt", (uint8_t *)"9", sizeof("9"));
      timePointRev -= 9;
      timePointRev /= 10;
      timePointLen -= 1;
    }
    
    wait(5,msec);
  }
  
  Brain.SDcard.appendfile("slot1.txt", (uint8_t *)",", sizeof(","));
}

//Function that saves the time and button pressed/released to the SD card
void sdSave() {
  
  wait(5,msec);
  if (rec) {
    
    motorNumSdSave();
    timePointSdSave();
  }
}

//When controller button R Up is pressed
void onevent_ControllerButtonRUp_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 1;
  sdSave();
}

//When controller button R Up is released
void onevent_ControllerButtonRUp_released_0() {
  timePoint = vex::timer::system();
  motorNum = 13;
  sdSave();
}

//When controller button R Down is pressed
void onevent_ControllerButtonRDown_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 2;
  sdSave();
}

//When controller Button R Down is released
void onevent_ControllerButtonRDown_released_0() {
  timePoint = vex::timer::system();
  motorNum = 14;
  sdSave();
}

//When controller L Up is pressed
void onevent_ControllerButtonLUp_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 3;
  sdSave();
}

//When controller L Up is released
void onevent_ControllerButtonLUp_released_0() {
  timePoint = vex::timer::system();
  motorNum = 15;
  sdSave();
}

//When controller button L Down is pressed
void onevent_ControllerButtonLDown_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 4;
  sdSave();
}

//When controller button L Down is released
void onevent_ControllerButtonLDown_released_0() {
  timePoint = vex::timer::system();
  motorNum = 16;
  sdSave();
}

//When controllr button F Up is pressed
void onevent_ControllerButtonFUp_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 5;
  sdSave();
}

//When controller button F Up is released
void onevent_ControllerButtonFUp_released_0() {
  timePoint = vex::timer::system();
  motorNum = 17;
  sdSave();
}

//When controller button F Down is pressed
void onevent_ControllerButtonFDown_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 6;
  sdSave();
}

//When controller button F Down is released
void onevent_ControllerButtonFDown_released_0() {
  timePoint = vex::timer::system();
  motorNum = 18;
  sdSave();
}

//When controller button E Up is pressed
void onevent_ControllerButtonEUp_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 7;
  sdSave();
}

//When controller button E Up is released
void onevent_ControllerButtonEUp_released_0() {
  timePoint = vex::timer::system();
  motorNum = 19;
  sdSave();
}

//When controller button E Down is pressed
void onevent_ControllerButtonEDown_pressed_0() {
  timePoint = vex::timer::system();
  motorNum = 8;
  sdSave();
}

//When controller button E Down is released
void onevent_ControllerButtonEDown_released_0() {
  timePoint = vex::timer::system();
  motorNum = 20;
  sdSave();
}

//When controller joystick axis a is changed
void onevent_ControllerAxisAChanged_1() {
  if (Controller.AxisA.position() == 0) {
    timePoint = vex::timer::system();
    motorNum = 26;
    sdSave();
  }
  if (Controller.AxisA.position() == 5) {
    timePoint = vex::timer::system();
    motorNum = 26.05;
    sdSave();
  }
  if (Controller.AxisA.position() == 10) {
    timePoint = vex::timer::system();
    motorNum = 26.1;
    sdSave();
  }
  if (Controller.AxisA.position() == 15) {
    timePoint = vex::timer::system();
    motorNum = 26.15;
    sdSave();
  }
  if (Controller.AxisA.position() == 20) {
    timePoint = vex::timer::system();
    motorNum = 26.2;
    sdSave();
  }
  if (Controller.AxisA.position() == 25) {
    timePoint = vex::timer::system();
    motorNum = 26.25;
    sdSave();
  }
  if (Controller.AxisA.position() == 30) {
    timePoint = vex::timer::system();
    motorNum = 26.3;
    sdSave();
  }
  if (Controller.AxisA.position() == 35) {
    timePoint = vex::timer::system();
    motorNum = 26.35;
    sdSave();
  }
  if (Controller.AxisA.position() == 40) {
    timePoint = vex::timer::system();
    motorNum = 26.4;
    sdSave();
  }
  if (Controller.AxisA.position() == 45) {
    timePoint = vex::timer::system();
    motorNum = 26.45;
    sdSave();
  }
  if (Controller.AxisA.position() == 50) {
    timePoint = vex::timer::system();
    motorNum = 26.5;
    sdSave();
  }
  if (Controller.AxisA.position() == 55) {
    timePoint = vex::timer::system();
    motorNum = 26.55;
    sdSave();
  }
  if (Controller.AxisA.position() == 60) {
    timePoint = vex::timer::system();
    motorNum = 26.6;
    sdSave();
  }
  if (Controller.AxisA.position() == 65) {
    timePoint = vex::timer::system();
    motorNum = 26.65;
    sdSave();
  }
  if (Controller.AxisA.position() == 70) {
    timePoint = vex::timer::system();
    motorNum = 26.7;
    sdSave();
  }
  if (Controller.AxisA.position() == 75) {
    timePoint = vex::timer::system();
    motorNum = 26.75;
    sdSave();
  }
  if (Controller.AxisA.position() == 80) {
    timePoint = vex::timer::system();
    motorNum = 26.8;
    sdSave();
  }
  if (Controller.AxisA.position() == 85) {
    timePoint = vex::timer::system();
    motorNum = 26.85;
    sdSave();
  }
  if (Controller.AxisA.position() == 90) {
    timePoint = vex::timer::system();
    motorNum = 26.9;
    sdSave();
  }
  if (Controller.AxisA.position() == 95) {
    timePoint = vex::timer::system();
    motorNum = 26.95;
    sdSave();
  }
  if (Controller.AxisA.position() == 100) {
    timePoint = vex::timer::system();
    motorNum = 27;
    sdSave();
  }
  if (Controller.AxisA.position() == -5) {
    timePoint = vex::timer::system();
    motorNum = 25.95;
    sdSave();
  }
  if (Controller.AxisA.position() == -10) {
    timePoint = vex::timer::system();
    motorNum = 25.9;
    sdSave();
  }
  if (Controller.AxisA.position() == -15) {
    timePoint = vex::timer::system();
    motorNum = 25.85;
    sdSave();
  }
  if (Controller.AxisA.position() == -20) {
    timePoint = vex::timer::system();
    motorNum = 25.8;
    sdSave();
  }
  if (Controller.AxisA.position() == -25) {
    timePoint = vex::timer::system();
    motorNum = 25.75;
    sdSave();
  }
  if (Controller.AxisA.position() == -30) {
    timePoint = vex::timer::system();
    motorNum = 25.7;
    sdSave();
  }
  if (Controller.AxisA.position() == -35) {
    timePoint = vex::timer::system();
    motorNum = 25.65;
    sdSave();
  }
  if (Controller.AxisA.position() == -40) {
    timePoint = vex::timer::system();
    motorNum = 25.6;
    sdSave();
  }
  if (Controller.AxisA.position() == -45) {
    timePoint = vex::timer::system();
    motorNum = 25.55;
    sdSave();
  }
  if (Controller.AxisA.position() == -50) {
    timePoint = vex::timer::system();
    motorNum = 25.5;
    sdSave();
  }
  if (Controller.AxisA.position() == -55) {
    timePoint = vex::timer::system();
    motorNum = 25.45;
    sdSave();
  }
  if (Controller.AxisA.position() == -60) {
    timePoint = vex::timer::system();
    motorNum = 25.4;
    sdSave();
  }
  if (Controller.AxisA.position() == -65) {
    timePoint = vex::timer::system();
    motorNum = 25.35;
    sdSave();
  }
  if (Controller.AxisA.position() == -70) {
    timePoint = vex::timer::system();
    motorNum = 25.3;
    sdSave();
  }
  if (Controller.AxisA.position() == -75) {
    timePoint = vex::timer::system();
    motorNum = 25.25;
    sdSave();
  }
  if (Controller.AxisA.position() == -80) {
    timePoint = vex::timer::system();
    motorNum = 25.2;
    sdSave();
  }
  if (Controller.AxisA.position() == -85) {
    timePoint = vex::timer::system();
    motorNum = 25.15;
    sdSave();
  }
  if (Controller.AxisA.position() == -90) {
    timePoint = vex::timer::system();
    motorNum = 25.1;
    sdSave();
  }
  if (Controller.AxisA.position() == -95) {
    timePoint = vex::timer::system();
    motorNum = 25.05;
    sdSave();
  }
  if (Controller.AxisA.position() == -100) {
    timePoint = vex::timer::system();
    motorNum = 25;
    sdSave();
  }
}

//When controller axis d is changed
void onevent_ControllerAxisDChanged_1() {
  if (Controller.AxisD.position() == 0) {
    timePoint = vex::timer::system();
    motorNum = 29;
    sdSave();
  }
  if (Controller.AxisD.position() == 5) {
    timePoint = vex::timer::system();
    motorNum = 29.05;
    sdSave();
  }
  if (Controller.AxisD.position() == 10) {
    timePoint = vex::timer::system();
    motorNum = 29.1;
    sdSave();
  }
  if (Controller.AxisD.position() == 15) {
    timePoint = vex::timer::system();
    motorNum = 29.15;
    sdSave();
  }
  if (Controller.AxisD.position() == 20) {
    timePoint = vex::timer::system();
    motorNum = 29.2;
    sdSave();
  }
  if (Controller.AxisD.position() == 25) {
    timePoint = vex::timer::system();
    motorNum = 29.25;
    sdSave();
  }
  if (Controller.AxisD.position() == 30) {
    timePoint = vex::timer::system();
    motorNum = 29.3;
    sdSave();
  }
  if (Controller.AxisD.position() == 35) {
    timePoint = vex::timer::system();
    motorNum = 29.35;
    sdSave();
  }
  if (Controller.AxisD.position() == 40) {
    timePoint = vex::timer::system();
    motorNum = 29.4;
    sdSave();
  }
  if (Controller.AxisD.position() == 45) {
    timePoint = vex::timer::system();
    motorNum = 29.45;
    sdSave();
  }
  if (Controller.AxisD.position() == 50) {
    timePoint = vex::timer::system();
    motorNum = 29.5;
    sdSave();
  }
  if (Controller.AxisD.position() == 55) {
    timePoint = vex::timer::system();
    motorNum = 29.55;
    sdSave();
  }
  if (Controller.AxisD.position() == 60) {
    timePoint = vex::timer::system();
    motorNum = 29.6;
    sdSave();
  }
  if (Controller.AxisD.position() == 65) {
    timePoint = vex::timer::system();
    motorNum = 29.65;
    sdSave();
  }
  if (Controller.AxisD.position() == 70) {
    timePoint = vex::timer::system();
    motorNum = 29.7;
    sdSave();
  }
  if (Controller.AxisD.position() == 75) {
    timePoint = vex::timer::system();
    motorNum = 29.75;
    sdSave();
  }
  if (Controller.AxisD.position() == 80) {
    timePoint = vex::timer::system();
    motorNum = 29.8;
    sdSave();
  }
  if (Controller.AxisD.position() == 85) {
    timePoint = vex::timer::system();
    motorNum = 29.85;
    sdSave();
  }
  if (Controller.AxisD.position() == 90) {
    timePoint = vex::timer::system();
    motorNum = 29.9;
    sdSave();
  }
  if (Controller.AxisD.position() == 95) {
    timePoint = vex::timer::system();
    motorNum = 29.95;
    sdSave();
  }
  if (Controller.AxisD.position() == 100) {
    timePoint = vex::timer::system();
    motorNum = 30;
    sdSave();
  }
  if (Controller.AxisD.position() == -5) {
    timePoint = vex::timer::system();
    motorNum = 28.95;
    sdSave();
  }
  if (Controller.AxisD.position() == -10) {
    timePoint = vex::timer::system();
    motorNum = 28.9;
    sdSave();
  }
  if (Controller.AxisD.position() == -15) {
    timePoint = vex::timer::system();
    motorNum = 28.85;
    sdSave();
  }
  if (Controller.AxisD.position() == -20) {
    timePoint = vex::timer::system();
    motorNum = 28.8;
    sdSave();
  }
  if (Controller.AxisD.position() == -25) {
    timePoint = vex::timer::system();
    motorNum = 28.75;
    sdSave();
  }
  if (Controller.AxisD.position() == -30) {
    timePoint = vex::timer::system();
    motorNum = 28.70;
    sdSave();
  }
  if (Controller.AxisD.position() == -35) {
    timePoint = vex::timer::system();
    motorNum = 28.65;
    sdSave();
  }
  if (Controller.AxisD.position() == -40) {
    timePoint = vex::timer::system();
    motorNum = 28.6;
    sdSave();
  }
  if (Controller.AxisD.position() == -45) {
    timePoint = vex::timer::system();
    motorNum = 28.55;
    sdSave();
  }
  if (Controller.AxisD.position() == -50) {
    timePoint = vex::timer::system();
    motorNum = 28.5;
    sdSave();
  }
  if (Controller.AxisD.position() == -55) {
    timePoint = vex::timer::system();
    motorNum = 28.45;
    sdSave();
  }
  if (Controller.AxisD.position() == -60) {
    timePoint = vex::timer::system();
    motorNum = 28.4;
    sdSave();
  }
  if (Controller.AxisD.position() == -65) {
    timePoint = vex::timer::system();
    motorNum = 28.35;
    sdSave();
  }
  if (Controller.AxisD.position() == -70) {
    timePoint = vex::timer::system();
    motorNum = 28.3;
    sdSave();
  }
  if (Controller.AxisD.position() == -75) {
    timePoint = vex::timer::system();
    motorNum = 28.25;
    sdSave();
  }
  if (Controller.AxisD.position() == -80) {
    timePoint = vex::timer::system();
    motorNum = 28.2;
    sdSave();
  }
  if (Controller.AxisD.position() == -85) {
    timePoint = vex::timer::system();
    motorNum = 28.15;
    sdSave();
  }
  if (Controller.AxisD.position() == -90) {
    timePoint = vex::timer::system();
    motorNum = 28.1;
    sdSave();
  }
  if (Controller.AxisD.position() == -95) {
    timePoint = vex::timer::system();
    motorNum = 28.05;
    sdSave();
  }
  if (Controller.AxisD.position() == -100) {
    timePoint = vex::timer::system();
    motorNum = 27;
    sdSave();
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
  rec = false;

  timePoint = 0.0;
  arrCount = 0.0;
  arrCounter = 0.0;
  select2 = 0.0;

  Catapult.setStopping(hold);
  Drivetrain.setStopping(hold);
  Intake.setStopping(hold);
  Drivetrain.setDriveVelocity(100.0, percent);
  Intake.setVelocity(100.0, percent);
  Catapult.setVelocity(100.0, percent);

  while (true) {
    
    //Starting the recording
    if ((Controller.ButtonEUp.pressing()) && !rec && !started) {
      Brain.playNote(3, 0, 1000);
      Brain.Screen.print("started");
      started = true;
      startTime = vex::timer::system();
      waitUntil (!(Controller.ButtonEUp.pressing()));
      wait(20,msec);
      rec = true;
    }

    //Stopping the recording
    if ((Controller.ButtonEDown.pressing()) && rec && started) {
      Brain.playNote(3, 6, 1000);
      Brain.Screen.print(" stopped");
      rec = false;
      waitUntil (!(Controller.ButtonEUp.pressing() && Controller.ButtonEDown.pressing()));
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
  Controller.AxisA.changed(onevent_ControllerAxisAChanged_1);
  Controller.AxisD.changed(onevent_ControllerAxisDChanged_1);
  wait(15, msec);
  whenStarted1();
}
