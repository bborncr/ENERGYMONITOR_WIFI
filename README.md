# ENERGYMONITOR_WIFI
This tutorial demonstrates how to connect an ATMEGA328p + esp8266 board, a energy monitor shield and two current transformers to Adafruit IO.

This project is aimed at people wanting to monitor the energy consumption of a home or small office. Only current is monitored. [Adafruit IO](https://io.adafruit.com/) is used to create a simple dashboard.

## Hardware
The microcontroller board is a combination of an ATMEGA328p and an ESP8266. Although this board is quite the Frankenstein's monster, it works well for this project.

* [Microcontroller Board with ATMEGA328p and ESP8266](https://www.crcibernetica.com/uno-atmega328p-esp8266-usb-ttl-ch340g/)
* [Energy Monitor Shield](https://www.crcibernetica.com/energy-monitor-shield-v0-2/)
* 2 x [Current Transformers](https://www.crcibernetica.com/non-invasive-ac-current-sensor-sct-013-100a-max/)

## Code
The microcontroller board contains two distinct microcontrollers. The arduino uno compatible is used to read the current levels from two current transformers and send the data via UART to the ESP8266 which transmits the data to Adafruit IO using wifi.

* Arduino UNO code: CRCSA_ENERGY_MONITOR_WIFI_UART
* ESP8266 code: ESP8266_ADAFRUITIO_UART

### Arduino IDE Preparation
The board definition for the ESP8266 must be installed.

1. Install the current Arduino IDE (1.8.12 or later). The current version is on the Arduino website.
1. Start Arduino and open the Preferences window.
1. Enter https://arduino.esp8266.com/stable/package_esp8266com_index.json into the Additional Board Manager URLs field. You can add multiple URLs, separating them with commas.
1. Open Boards Manager from Tools > Board menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).

The following libraries are required:
* AdafruitIO Arduino
* EmonLib

Both these libraries may be installed directly from **Tools-->Manage Libraries...** in the Arduino IDE.

## STEP 1 Sign up for a Adafruit IO account
1. Go to https://io.adafruit.com and sign up for an account.
1. At the main page click on **Adafruit IO Key**.
1. Your Username and Active Key should be displayed (these will be used shortly).

## Programming the ESP8266
1. Before setting the dip switches make sure the board is not connected to the USB port.
1. Set the dip switches to: `OFF, OFF, OFF, OFF, ON, ON, ON`. See the product web site for the reference `CH340 connect to ESP8266 (upload sketch)`. Pay attention to the orientation of the board.
1. Start the Arduino IDE. Make sure the Generic ESP8266 board is selected.
1. Plug in the microcontroller board and select the correct port in the Arduino IDE.
1. Open the `ESP8266_ADAFRUITIO_UART` sketch.
1. Rename the `config_example.h` to `config.h`.
1. Edit the following constants in the `config.h` file: 
   1. IO_USERNAME: Username from the Adafruit IO Key page.
   1. IO_KEY: Active Key from the Adafruit IO Key page.
   1. WIFI_SSID: Your local WIFI SSID.
   1. WIFI_PASS: Your local WIFI password.
1. Save the file and upload the sketch.

## Testing the ESP8266
1. Before setting the dip switches make sure the board is disconnected.
1. Set the dip switches to `OFF, OFF, OFF, OFF, ON, ON, OFF`. See the product web site for the reference `CH340 connect to ESP8266 (connect)`.
1. Connect the board to the PC. Make sure that the correct serial port is selected. Open the `Serial Monitor` and select `Newline` and `115200`.
1. After a few seconds the serial monitor should display: **Adafruit IO connected. Waiting for commands...**.
1. In the Adafruit IO page click on the `Feeds` tab and select `View All`.
1. If everything is working correctly a Group/Feed named `energymonitor` should have appeared and the feed connect should have a Last Value of 1.
1. In the serial monitor type: `S:10:20` and hit ENTER. Make sure the `S` is in capital letters.
1. Two feeds `ct1` and `ct2` should appear with their corresponding values.
1. Now all we have to do is make an arduino sketch to send data to the ESP8266 to be published.

## Programming the ATMEGA328p (Arduino UNO compatible)
1. Before setting the dip switches make sure the board is not connected to the USB port.
1. Set the dip switches to: `OFF, OFF, ON, ON, OFF, OFF, OFF`. See the product web site for the reference `CH340 connect to ATMEGA328 (upload sketch)`.
1. Start the Arduino IDE. Make sure the Arduino UNO board is selected.
1. Plug in the microcontroller board and select the correct port in the Arduino IDE.
1. Open the `CRCSA_ENERGY_MONITOR_WIFI_UART` sketch.
1. No configuration is required.
1. Upload the sketch.


