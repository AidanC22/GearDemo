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
