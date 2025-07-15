🚜 Arduino-Based Land Survey Bot

The Land Survey Bot is an autonomous, Arduino-powered robot designed for land surveying and data collection. It logs GPS coordinates to an SD card, calculates and displays the distance traveled on an LCD, tracks movement using rotary encoders, and enables wireless control and data transmission via Bluetooth. The logged GPS data can be visualized as a route on a map using GPSVisualizer.
This project is ideal for applications such as agricultural land mapping, environmental monitoring, or educational robotics projects. The bot combines precise GPS tracking, real-time data display, and remote control capabilities, making it a versatile tool for surveying tasks.

🎯 Features

GPS Data Logging: Captures latitude, longitude, date, and time using the NEO-6M GPS module and stores them in a .csv file on an SD card.
Distance Tracking: Measures the bot’s travel distance using rotary encoders and displays it on a 16x2 LCD.
Bluetooth Control: Sends live GPS data to a mobile device via the HC-05 Bluetooth module and supports wireless motor control commands.
Path Visualization: Exports logged GPS data for visualization on GPSVisualizer as a route on Google Maps.
Motorized Movement: Controls four DC motors using the L298N motor driver for precise navigation.
Open-Source: Fully customizable Arduino code and hardware design for hobbyists and developers.


🧰 Hardware Requirements

Component
Description


*Arduino Nano/UNO
Microcontroller for processing and control


*NEO-6M GPS Module
Captures GPS coordinates


*SD Card Module
Logs GPS data to a .csv file


*16x2 LCD + Potentiometer
Displays real-time distance traveled


*HC-05 Bluetooth Module
Enables wireless data transfer and control


*Rotary Encoders (x2)
Tracks wheel rotations for distance measurement


*L298N Motor Driver
Controls four DC motors


*DC Motors (x4)
Drives the bot for movement


*Battery Pack
9V or AAA batteries for power supply


*Chassis & Wheels
Mechanical structure for mobility


Optional:

Jumper wires, breadboard, or custom PCB for connections.
Potentiometer for LCD contrast adjustment.
Push buttons or switches for manual control (if implemented).


📷 Bot Preview
Image placeholder: The actual bot image will be added soon.



📡 GPS Data Visualization

The GPS data logged by the bot can be visualized as a route on a map using GPSVisualizer.
Steps to Visualize:

Remove the SD card from the bot and access the log.csv file.

Visit GPSVisualizer.

Select "Convert to GPX" or "Draw a map".

Upload the log.csv file.

Choose Google Maps as the output format.

View and analyze the bot’s travel path.


⚙️ Installation and Setup
Prerequisites

Arduino IDE: Download and install from arduino.cc.

Libraries:

*TinyGPS++: For GPS data parsing.
*SD: For SD card operations.
*SoftwareSerial: For GPS and Bluetooth communication.
*LiquidCrystal: For LCD display.
*Install these via the Arduino Library Manager.


GPSVisualizer Account (optional): For advanced visualization features.


Install Libraries:

In the Arduino IDE, go to Sketch > Include Library > Manage Libraries and install:

TinyGPS++

SD

SoftwareSerial

LiquidCrystal




Upload the Code:

Connect the Arduino to your computer via USB.

Select the correct board and port in the Arduino IDE.

Upload the sketch to the Arduino.



Bluetooth Setup

Pair the HC-05 Bluetooth module with your mobile device (default password is usually 1234 or 0000).

Use a Bluetooth serial terminal app (e.g., Serial Bluetooth Terminal for Android) to receive GPS data and send motor control commands.


📜 Usage

Power On:

Turn on the bot using the battery pack.

The LCD will display the initial distance (0 meters).

The LED will indicate the system status (e.g., blinking for SD/GPS initialization).


GPS Logging:

The bot logs GPS coordinates (latitude, longitude, date, time) to log.csv on the SD card every 5 seconds when a valid GPS fix is acquired.


Distance Tracking:

Rotary encoders track wheel rotations to calculate the distance traveled.
The distance is displayed on the 16x2 LCD in real-time.


Bluetooth Control:

Send commands via Bluetooth to control motor direction (e.g., forward, backward, turn).
Receive live GPS coordinates on your mobile device.


Data Visualization:

After the survey, remove the SD card and upload log.csv to GPSVisualizer to plot the route.



🔧 Troubleshooting

No GPS Data:
Ensure the NEO-6M module has a clear view of the sky for a GPS fix.
Check RX/TX pin connections and baud rate (9600).


SD Card Errors:
Verify the SD card is formatted as FAT32.
Check the chip select pin (default: 10).


LCD Not Displaying:
Adjust the potentiometer for contrast.
Verify LCD pin connections.


Bluetooth Issues:
Ensure the HC-05 is paired and the correct serial pins are used.
Use a Bluetooth terminal app to test communication.


Motor Not Moving:
Check L298N connections and battery voltage.
Verify motor control commands via Bluetooth.




🛠️ Future Enhancements

Add obstacle detection using ultrasonic sensors.
Implement a web interface for real-time path visualization.
Integrate a real-time clock (RTC) for accurate timestamps during GPS signal loss.
Optimize power consumption for longer battery life.
Add support for waypoint navigation.


📜 License
This project is licensed under the MIT License. Feel free to use, modify, and distribute the code.

🙌 Contributing
Contributions are welcome! Please follow these steps:




Made by Ayush N | Electronics & Embedded Hobbyist

Feel free to ⭐ star this repo or fork it to improve!



🌟 Happy Surveying!
