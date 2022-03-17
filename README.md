# ESP8266 with DHT11 and OLED
My second trying with Arduino and show temperature data on a mini OLED display.<br>
Its display a test text and after that its will the data.

## Parts: 
- Adafruit ESP8266 as NodeMCU 1.0 (ESP-12E modul),
- 0.96″ 128x64 mini OLED display (I use white color for that project),
- DHT11 temperature and humidity sensor
- Jumper cables.


You can see a picture from the full setup here:<br>
![Picture from the setup](/ESP8266-OLED-DHT11.jpg)

## Arduino Modules:
- Adafruit_SSD1306,
- Adafruit_GFX,
- DHT

It is the next step on my first project as ![ESP8266_with_OLED](https://github.com/Mategm/ESP8266_with_OLED)

## Connection:
- Display GND to ESP G
- Display VCC to ESP 3V
- Display SCL to ESP D1 as GPIO 1
- Display SDA to ESP D2 as GPIO 2
- DHT + to ESP 3V (Can be the same as where the display VCC)
- DHT - to ESP G (Can be the same as where the display GND)
- DHT OUT to ESO D5 as GPIO 14

Coding in Arduino IDE 1.8.19<br>
I made this code from sources of the internet. There is no copyright, use it as you want.
