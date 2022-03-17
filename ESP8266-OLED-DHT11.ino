#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins) SDA = D2; SCL = D1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 14     // Digital pin as GPIO 14 as pin D5 connected to the DHT sensor out
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  //Serial.begin(230400);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Its works for my 128x64 OLED 0,96" screen
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();

  display.setTextSize(1); //1-8; 1 is default, not needed
  display.setTextColor(WHITE); // Not relevant for one or two color OLED display
  display.setCursor(0,0); //0,0 to 120,57
  display.println("DHT11 test!");
  display.display();
  delay(2000);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Read temperature as Fahrenheit (isFahrenheit = true; default C as false)
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    display.println("Failed to read from DHT sensor!");
    return;
  }
  String temp = String(t,1); //Convert to string and cut de second decimal number
  String humi = String(h,1);
  display.clearDisplay();
  
  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setCursor(92,0);
  display.print(temp);
  display.print("  ");
  display.drawCircle(119, 1, 1, WHITE); // degree sign
  display.setCursor(122,0); // repositioning the Celsius display
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.print("Humidity:   ");
  display.setCursor(92,10);
  display.print(humi);
  display.print(" %"); 
  
  display.display();
  delay(2000);
}
