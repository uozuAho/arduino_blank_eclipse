arduino_blank_eclipse
=====================

This is a (nearly) blank Eclipse project to be used as a base for building more complex
Arduino programs. Currently only the Arduino Uno is supported.

Using this project, you don't need a main() function - this is in the library. It calls
setup() then continuously calls loop(). These two functions must be defined by you in 
"sketch.cpp". That's all you need to get running. On top of that, you can add more source
files etc. just as you would a regular c project.

You'll need:

 - Eclipse CDT (http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/junosr2)

 - Eclipse AVR plugin. Get from Eclipse marketplace or here:
  - http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_Eclipse_Plugin
 
 - AVR-gcc toolchain. This comes with the Arduino IDE (http://arduino.cc/en/Main/Software), 
   or can be found separately...here?: http://winavr.sourceforge.net/. Make sure the binary 
   path is in your system path, either in the global PATH variable of your system or the PATH 
   variable set within Eclipse. In my case, I added C:\arduino-1.0.4\hardware\tools\avr\bin 
   to Windows' PATH variable.
   
 - MinGW  http://www.mingw.org/ for make (if you're using Windows).

Uploading to target hardware
============================

This project has an avrdude configuration, however I think it relies on local paths so you
may not be able to program your arduino straight away. If this is the case, do the following
(assumes you've got the Arduino IDE installed in C:\arduino-1.0.4):

- In Eclipse, go to Window->Preferences->AVR->Paths
- Assuming your Arduino installation is in C:\arduino-1.0.4\, set the following:
 - AVR-GCC: Source: custom, Current value: C:\arduino-1.0.4\hardware\tools\avr\bin
 - GNU make: (if using Windows) Source: custom, Current value: C:\MinGW\bin
 - AVR Header files: Source: custom, Current value: C:\arduino-1.0.4\hardware\tools\avr\avr\include
 - AVRDude: Source: custom, Current value: C:\arduino-1.0.4\hardware\tools\avr\bin

- Now in Eclipse, go to Window->Preferences->AVRDude, enable 
  "Use custom configuration file for AVRDude" and set it to 
  C:\arduino-1.0.4\hardware\tools\avr\etc\avrdude.conf
  
- Click "Add" in the "Programmer Configuration" section. A window should appear.
- Give the configuration a meaningful name
- Pick "Arduino" under "Programmer Hardware(-c)"
- Select the serial port that your arduino is connected to, eg. com8 (Windows) or 
  /dev/ttyACM0 (Linux). This may change if you restart/reconnect your arduino.
- Override the baud rate to 115200
- Click OK
- You should now be able to upload your binary to your Arduino!



Adding/updating arduino core library
====================================

To use this project for other Arduino hardware, you must add the pre-compiled arduino core
library to this project. The compiled core library can be obtained by doing the following:

- Download the Arduino IDE
- Open the Arduino IDE
- Go to File->Preferences and enable both "Show verbose output during:" check boxes.
- Select the arduino hardware you want the library for (Tools->board)
- Build any project ("Blink" example or anything).
- Wade through the console output, looking for line(s) ending with "core.a". This will tell you
  where the Arduino IDE stores the library. Mine was in 
  C:\Users\wstone\AppData\Local\Temp\build4728966023683276903.tmp\core.a
- Copy core.a into this project, and give it a more meaningful name. Include the hardware it's 
  built for, and what built it. For example, the current library in this project is
  "libarduino-1.0.4-core-Uno.a"
- Create a new Eclipse build configuration and point it to the newly copied library. Look at the 
  current build configuration settings for clues on how to do this. I'll write it later if I can
  be bothered. Oh you'll also need to add the "pins_arduino.h" file for the hardware you chose
  to the project. See the "variants" directory in arduino_core. You'll need each configuration to
  only include the correct "pins_arduino.h" header.


NOTES
=====
- Eclipse might give you errors regarding implementation of abstract classes - just turn these
errors off (go to problems view, right click on the error & turn it off or make it a warning 
instead). Eclipse is wrong...probably because it can't see inside the arduino core library.
    
    
TODO
====

- I think the Eclipse project file is broken - I keep getting a Java null pointer exception
  after each build. Luckily the thing still builds.
- Add pre-built libraries & pin headers for all Arduino hardware
- Make a generic "pins_arduino.h" file which includes the correct header file based on 
the Eclipse build configuration
- Add LICENSE and .gitignore files
