# Rover CAN Bus
Some example code to interface with the CAN bus on the Raspberry Pi and Teensy 4.1

## Configuring the Pi
To setup the Pi using the Raspberry Pi CAN Bus Hat run this command: <br />
`make setup_can OSC_FREQ=16000000 INT_PIN=12`

If using different hardware set the above environment variables accordingly

You also need to enable the CAN network interface (This will need to be run on every reboot):
`make enable_can_interface BAUD_RATE=250000`
The teensy example code uses a baud rate of 250k

## Building and Running the example code
To build and run the code for the Raspberry Pi run the following commands:<br />
`make` <br />
`make run_blink_example`

## Wiring up the Teensy 4.1
The example code uses the CAN1 interface so wire the CAN tranceiver like so: <br />
Pin 22 -> CAN Tx <br />
Pin 23 -> CAN Rx

## Building an flashing the example code to the Teensy 4.1
Unfortunately there isn't a nice way to build and flash the Teensy 4.1
from the command line so you will need to download and install the Arduino IDE
along with teensyduino and build and flash from the IDE GUI environment