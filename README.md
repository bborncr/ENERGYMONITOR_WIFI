# ENERGYMONITOR_WIFI
This tutorial demonstrates how to connect an arduino + esp8266 board, a energy monitor shield and two current transformers to Adafruit IO.

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

