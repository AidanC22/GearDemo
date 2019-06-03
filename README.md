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

# Arduino Configuration
This project uses the following hardware from Pololu:
 * A-Star 32U4 Prime SV
 * Tic T825 Stepper Motor Controller

Programming the software requires:
 1. Install Arduino IDE 1.6.4 or newer
 2. Follow the instructions at https://www.pololu.com/docs/0J61/6.2 to add the Pololu boards to Arduino IDE
 3. Follow the Software instructions at https://github.com/pololu/tic-arduino to add the Tic library to the Arduino IDE
