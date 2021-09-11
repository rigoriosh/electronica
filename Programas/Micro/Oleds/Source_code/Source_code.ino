#include <Wire.h>  //  Include I2C library
#include<Adafruit_GFX.h>   //  include Graphical Library
#include<Adafruit_SSD1306.h>  // Oled library


// Make a oled class
Adafruit_SSD1306 oled(128, 64, &Wire, 4);  //  182= Oled width, 64 = oled height, 4 is reset pin 

void setup()
{
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // SSD1306_SWITCHCAPPVCC is generate 3.3volt internaly,  0x3c is I2c slave(oled) address
  oled.clearDisplay();  // Celar display function
}
 void loop()
 {
  
 oled.setTextSize(1);    // first we have to decide font size
 oled.setTextColor(WHITE);     //we have to decide back ground color
 oled.setCursor(0,0);    //then set print location or printing cursor
 oled.println(F("Hello, World!"));   // print conmmand
 oled.display();  // oled display command
 oled.invertDisplay(true);
 }
 
