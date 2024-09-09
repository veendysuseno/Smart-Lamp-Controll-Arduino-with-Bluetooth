# Smart Lamp Control with Arduino and Bluetooth

## Overview

This project uses an Arduino to control a lamp and various LEDs based on Bluetooth commands. It integrates an RTC module for real-time clock functionality, an LCD for displaying time and date, and a buzzer for notifications.

## Components Used

- Arduino Uno
- Bluetooth Module (HC-05 or similar)
- RTC DS1307 Module
- LiquidCrystal I2C Display
- Buzzer
- Relay
- Red LED
- Green LED

## Connections

- **Bluetooth Module**: Connected to pins 2 (TX) and 3 (RX) on the Arduino.
- **RTC Module**: Connected via I2C (SDA to A4, SCL to A5).
- **LCD Display**: Connected via I2C.
- **Relay**: Connected to pin 13.
- **LEDs**: Connected to pins 10 (Red) and 11 (Green).
- **Buzzer**: Connected to pin 12.

## Features

- **Voice Commands**: Control the lamp and LEDs using predefined voice commands via Bluetooth.
- **Real-Time Clock**: Display current time and date on an LCD using the RTC module.
- **Notification**: Buzzer provides audible feedback for actions.

## Code Explanation

### Initialization

- Initialize the LCD, Bluetooth, and RTC modules.
- Display a welcome message and a notification to stop Bluetooth connection.

### Loop Function

- Continuously check for incoming Bluetooth data.
- Execute commands based on received data:
  - **Turn lamp on/off**: Control relay and LEDs.
  - **Voice commands**: Special commands for greeting and notifications.
- Update LCD with current time and date.

### Functions

- `myTimer()`: Updates the LCD with current time and date.
- `notif()`: Activates the buzzer for a brief notification sound.

## Usage

1. **Setup**: Connect all components as described and upload the code to the Arduino.
2. **Control**: Send Bluetooth commands from a paired device to control the lamp and LEDs.

## Example Commands

- `"lampu menyala"` or `"on"`: Turn on the lamp.
- `"off"`: Turn off the lamp.
- `"Assalamualaikum"`: Blink green LED.
- `"Hidupkan lampu"`: Turn on the lamp.

## License

### © Veendy 2020
