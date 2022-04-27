# VEXCode-Recorder-Replay

These programs are designed to record and replay driver controller inputs. this allows for replaying driver skills matches as programming skills. The following will explain how the codes work, the differences between them, and how to use them. **The codes are still a work in progress.**

# Generation 1 Programs
The generation 1 recording program functions as our normal driver control code would. The difference is that you can push E Up on the controller to start a recording of all the buttons being pressed on the controller. This allows for all movements to be replay later. To end the recording, you press the E Down button on the controller. When the recording has been stopped, it will start printing out all the information to the brain for you to write down. Generation 1 VEX IQ brains can't save data so this is the only way to retrieve the data from the program. 

Once the data has been retrieved from the recording program, you put the information into the array in the replay code. After importing the data, you want to set the starting time that was first shown on from the recording. If the program skips the first controller inputs when the replay starts, you may need to add a latency by changing the latency varible in the code. You have to go through the code and put in what each button does when its pressed and/or released. Each button is labled on the code and you put the code where it says to input movements. From there, you can download the program and push E Up to run it. You can push E Up to run it again after it has finished.

# Generation 2 Programs
The Generation 2 programs function the same as the generation 1 programs, the only difference being that you can only save to an SD card. Because of the addition of SD card in the generation 2 brains, it allows you to save the data instead of printing it to the brain, like you have to do with the generation 1 programs. Besides only saving to an SD card, the code works the same as the generation 1 codes.

After you record some driving, the SD card will have a text document on it called 'slot1.txt'. This is the file that the recording gets saved to. To replay the recorded driving you copy the information from the text document and paste it in the character variable in the generation 2 replay code. From there, you look through the code and add what functions your robot does when a button is pressed. The buttons are labeled and you only replace the comment that says to be replaced. Starting the replay is the same as the generation 1 replay, you push E Up and it will run the recording. You can play as many times as you want after it finishes.

*You have to manually delete the information from the text file on the SD card if you want a new recording. Otherwise it will add to the original recording.*
