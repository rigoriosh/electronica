#include <Wire.h>      // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306
 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64

#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto

static const unsigned char PROGMEM logoBmp[] =

{
0x01, 0xfe, 0x00, 0x03, 0x03, 0x00, 0x06, 0x01, 0x80, 0x04, 0x30, 0x80, 0x0c, 0xfc, 0xc0, 0x0c, 
  0xcc, 0xc0, 0x0c, 0x84, 0xc0, 0x0f, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 
  0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0f, 0x84, 0xc0, 0x0e, 0x84, 0xc0, 
  0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 
  0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0c, 0x84, 0xc0, 0x0f, 0xfc, 0xc0, 0x0f, 0xfc, 
  0xc0, 0x0c, 0xfc, 0xc0, 0x0c, 0xfc, 0x40, 0x18, 0xfc, 0x70, 0x31, 0xfe, 0x30, 0x63, 0xff, 0x18, 
  0x47, 0xff, 0x8c, 0xc7, 0xff, 0x8c, 0x8f, 0xff, 0xc4, 0x8f, 0xff, 0xc4, 0x9f, 0xff, 0xe4, 0x9f, 
  0xff, 0xe4, 0x9f, 0xff, 0xe4, 0x8f, 0xff, 0xe4, 0x8f, 0xff, 0xc4, 0xcf, 0xff, 0xcc, 0x47, 0xff, 
  0x88, 0x63, 0xff, 0x18, 0x30, 0xfc, 0x30, 0x18, 0x00, 0x60, 0x0c, 0x00, 0xc0, 0x07, 0xff, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



void setup() {
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
}
 
void loop() {
  oled.clearDisplay();      // limpia pantalla
  oled.drawBitmap(53, 10, logoBmp, 22, 50, WHITE); 
  oled.display();     // muestra en pantalla todo lo establecido anteriormente
  delay(5000);
}