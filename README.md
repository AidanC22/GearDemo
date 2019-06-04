# GearDemo
This project is a demonstration of the following:
 * CAD design of mechanical parts
 * 3D printing of parts
 * Design of spur gears
 * Driving stepper motors using the Pololu TIC T825 driver
 * Controlling the TIC T825 using an Arduino board
 * Programming the Arduino microprocessor over I2C

# CAD Models
The CAD models for the housing and gears were created in Fusion 360:

<img src="https://github.com/AidanC22/GearDemo/blob/master/media/housing.png" width="300">

<img src="https://github.com/AidanC22/GearDemo/blob/master/media/gear.png" width="300">

<img src="https://github.com/AidanC22/GearDemo/blob/master/media/assembled-top.png" width="300">

Additionally models in STEP format for the boards and motors were downloaded from the Pololu and McMaster websites:

<img src="https://github.com/AidanC22/GearDemo/blob/master/media/assembled-bottom.png" width="300">

# 3D Printed Parts
The parts were sliced using Prusa Slic3r:

<img src="https://github.com/AidanC22/GearDemo/blob/master/media/3d-print-slicer.png" width="300">

They were then printed on a Prusa I3 MK3S in orange PETG plastic:

<img src="https://github.com/AidanC22/GearDemo/blob/master/media/printing.jpg" width="300">

# Arduino Configuration
This project uses the following hardware from Pololu:
 * A-Star 32U4 Prime SV
 * Tic T825 Stepper Motor Controller

The electrical components are wired as follows:
 * 24V power brick:
   * 24V Power wire (Red) to:
     * A-Star 32U4 Prime SV "Power In +" pin
     * Pololu Tic T825 "VIN" pin
   * Ground wire (Black) to:
     * A-Star 32U4 Prime SV "Power In -" pin
     * Ground to Pololu Tic T825 "GND" pin
 * I2C Connection
   * SCL wire (Orange):
     * A-Star 32U4 Prime SV "SCL" pin
     * Pololu Tic T825 "SCL" pin
   * SDA wire (Yellow):
     * A-Star 32U4 Prime SV "SDA" pin
     * Pololu Tic T825 "SDA" pin
   * GND wire (Green):
     * A-Star 32U4 Prime SV "GND" pin
     * Pololu Tic T825 "GND" pin
 * Push Button:
   * GND wire (black):
     * A-Star 32U4 Prime SV "GND" pin
     * One side of push button
   * Signal wire (purple)
     * Other side of push button
     * A-Star 32U4 Prime SV "Digital Pin 7" pin
 * Stepper Motor
   * Coil A1 (Black) to Pololu Tic T825 "A1" pin
   * Coil A2 (Green) to Pololu Tic T825 "A2" pin
   * Coil B1 (Blue) to Pololu Tic T824 "B1" pin
   * Coil B2 (Red) to Pololu Tic T825 "B2" pin
   
Programming the software requires:
 1. Install Arduino IDE 1.6.4 or newer
 2. Follow the instructions at https://www.pololu.com/docs/0J61/6.2 to add the Pololu boards to Arduino IDE
 3. Follow the Software instructions at https://github.com/pololu/tic-arduino to add the Tic library to the Arduino IDE

# Tic Programming
The Pololu Tic library contains some examples to move stepper motors. The following is needed to get the Tic library working:
 1. Add `#include <Tic.h>` to include the Tic header file.
 2. Enter `TicI2C tic;` to declare an instance of the TicI2C manager called tic.
 3. In the setup function call `Wire.begin();` to set up the I2C communications.
 4. Sleep for 20 milliseconds to give the Tic board time to power up.
 5. Send commands to the Tic controller using the functions in the tic instance.

The `tic.resetCommandTimeout();` function must be called many times a second to prevent the Tic board from shutting down.

# Tic Configuration
The following commands configure the Tic T825 to smoothly drive the NEMA 17 motor:
 * `tic.setProduct(TicProduct::T825);` to set the board type to Tic T825
 * `tic.setStepMode(TicStepMode::Microstep32);` to set the microstep resolution to 32 microsteps per step
 * `tic.setCurrentLimit(500);` to set the motor current to 500 milli-amps
 * `tic.setDecayMode(TicDecayMode::Fast);` to set the motor decay mode to fast (less vibration)
 * `tic.setMaxSpeed(64000000);` to set the top speed to 6400 microsteps per second
 * `tic.setMaxAccel(640000);` to set the acceleration to 6400 microsteps per second squared
 * `tic.setMaxDecel(640000);` to set the deceleration to 6400 microsteps per second squared

The stepper motor drive values were found out by experimentation.
The speed and acceleration values are due to the 200-step-motor * 32-micro-steps-per-step resulting in 6400 micro-steps per revolution.

# Push Button Programming
The push button is connected to the A-Star Digital Pin 7. To detect the push button:
 1. Add `pinMode(7, INPUT_PULLUP);` to the start function.
 2. Read the pin using `digitalRead(7);`

How this works is that configuring the pin for `INPUT_PULLUP` makes it an input-pin that can be read, but also weakly pulls the pin voltage up to 5V. When the button is released the pull-up will bring the pin to 5V and `digitalRead(7)` will return `HIGH`. When the button is pressed, pin 7 is connected through the push-button to ground draining the voltage to 0V and `digitalRead(7)` will return `LOW`.
