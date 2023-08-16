# VEXCode-Recorder-Replay

These programs are designed to record and replay driver controller inputs. this allows for replaying driver skills matches as programming skills. The following will explain how the codes work, the differences between them, and how to use them. 

*The generation 1 and 2 codes do not work. They were both worked on during the year 2022 for Vex IQ. Generation 3 is built for Vex VRC using the V5 brains and is being worked on in 2023. Generation 3 may be compatible with Vex IQ brains but has not been tested. Generation 2 and 3 require a sd card in the brain to function.*

# Generation 1 Programs
The generation 1 recording program functions as our normal driver control code would. The difference is that you can push E Up on the controller to start a recording of all the buttons being pressed on the controller. This allows for all movements to be replay later. To end the recording, you press the E Down button on the controller. When the recording has been stopped, it will start printing out all the information to the brain for you to write down. Generation 1 VEX IQ brains can't save data so this is the only way to retrieve the data from the program. 

Once the data has been retrieved from the recording program, you put the information into the array in the replay code. After importing the data, you want to set the starting time that was first shown on from the recording. If the program skips the first controller inputs when the replay starts, you may need to add a latency by changing the latency varible in the code. You have to go through the code and put in what each button does when its pressed and/or released. Each button is labled on the code and you put the code where it says to input movements. From there, you can download the program and push E Up to run it. You can push E Up to run it again after it has finished.

# Generation 2 Programs
The Generation 2 programs function the same as the generation 1 programs, the only difference being that you can only save to an SD card. Because of the addition of SD card in the generation 2 brains, it allows you to save the data instead of printing it to the brain, like you have to do with the generation 1 programs. Besides only saving to an SD card, the code works the same as the generation 1 codes.

After you record some driving, the SD card will have two text documents on it called 'slot1.txt' and 'startTime'. This is the file that the recording gets saved to. To replay the recorded driving you copy the information from the 'slot1.txt' text document and paste it in the character variable in the generation 2 replay code. Then, you copy the time from the 'startTime.txt' to the startTime variable. From there, you look through the code and add what functions your robot does when a button is pressed. The buttons are labeled and you only replace the comment that says to be replaced. Starting the replay is the same as the generation 1 replay, you push E Up and it will run the recording. You can play as many times as you want after it finishes.

*You have to manually delete the information from the text file on the SD card if you want a new recording. Otherwise it will add to the original recording.*

# Button Input List
Below shows what button input it equal to what number:

### Buttons:

- Button R Up Pressed = 1 .............. Button R Up Released = 13 
- Button R Down Pressed = 2 ........ Button R Down Released = 14
- Button L Up Pressed = 3 .............. Button L Up Released = 15
- Button L Down Pressed = 4 ........ Button L Down Released = 16
- Button F Up Pressed = 5 .............. Button F Up Released = 17
- Button F Down Pressed = 6 ........ Button F Down Released = 18
- Button E Up Pressed = 7 .............. Button E Up Released = 19
- Button E Down Pressed = 8 ........ Button E Down Released = 20
- Button R3 Pressed = 9 .................. Button R3 Released = 10
- Button L3 Pressed = 11 ................ Button L3 Released = 12

### Joysticks Axis A:
- Joystick Axis A -100% = 25
- Joystick Axis A >-66% <-99% = 26
- Joystick Axis A >-33% <-66% = 27
- Joystick Axis A >0% <-33% = 28
- Joystick Axis A 0% = 29
- Joystick Axis A >0% <33% = 30
- Joystick Axis A >33% <66% = 31
- Joystick Axis A >66% >99% = 32
- Joystick Axis A 100% = 33

### Joystick Axis D:
- Joystick Axis D -100% = 34
- Joystick Axis D >-66% <-99% = 35
- Joystick Axis D >-33% <-66% = 36
- Joystick Axis D >0% <-33% = 37
- Joystick Axis D 0% = 38
- Joystick Axis D >0% <33% = 39
- Joystick Axis D >33% <66% = 40
- Joystick Axis D >66% <99% = 41
- Joystick Axis D 100% = 42

# Generation 3 Programs

Generation 3 moves from using C++ *(which im not very good at)* to using Python *(which I am quite good at)*. Like the previous generations, generation 3 records driver inputs to be replayed as driver skills. Generation 3 requires that an SD card is in the brain to save data too; it saves a file for button inputs and the times the buttons were pressed/released. The difference between this version and the others is that you do not need to manually input the information into the replay program. When running both programs there is a interface on the brains screen that lets you select what file slot to save/load. Use the up and down button to choose between options and A to select the choosen option.

When setting up the replay program, you have to go through and add what functions each button has so the replay has something to execute. After that, you do not need to touch the code again; it will automatically import the saved information from the SD card and run it. When adding the drivetrain use a single motor or motor group and name the left side of the drivetrain "leftDrive" and the right side "rightDrive". If the driving is being weird you need to reverse one or both of the motors/motor groups.

### Buttons:
- Button R1 Pressed = 1 ...................... Button R1 Released = 2
- Button R2 Pressed = 3 ...................... Button R2 Released = 4
- Button L1 Pressed = 5 ....................... Button L1 Released = 6
- Button L2 Pressed = 7 ....................... Button L2 Released = 8
- Button A Pressed = 9 ......................... Button A Released = 10
- Button B Pressed = 11 ....................... Button B Released = 12
- Button Y Pressed = 13 ....................... Button Y Released = 14
- Button X Pressed = 15 ....................... Button X Released = 16
- Button Up Pressed = 17 .................... Button Up Released = 18
- Button Right Pressed = 19 ............... Button Right Released = 20
- Button Down Pressed = 21 .............. Button Down Released = 22
- Button Left Pressed = 23 .................. Button Left Released == 24

*Joystick input are saved from -100 to 100 for each joystick.*
