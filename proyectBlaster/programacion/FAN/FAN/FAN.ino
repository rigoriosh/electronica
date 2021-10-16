#include <Wire.h>      // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306
 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64

#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto

static const unsigned char PROGMEM logoBmp[] =

{
0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xf8, 0x03, 0xe0, 0x00, 0x01, 
  0xc0, 0x30, 0x70, 0x00, 0x03, 0x81, 0xfe, 0x38, 0x00, 0x06, 0x03, 0xff, 0x0c, 0x00, 0x0c, 0x03, 
  0xff, 0x86, 0x00, 0x18, 0x03, 0xff, 0x83, 0x00, 0x38, 0x03, 0xff, 0x03, 0x80, 0x30, 0x03, 0xfe, 
  0x01, 0x80, 0x73, 0x03, 0xfc, 0x01, 0xc0, 0x67, 0x83, 0xf8, 0x00, 0xc0, 0x6f, 0xc3, 0xf8, 0x00, 
  0xc0, 0xcf, 0xe1, 0xf0, 0x00, 0x60, 0xcf, 0xf9, 0xe3, 0xfc, 0x60, 0xcf, 0xfd, 0xff, 0xfc, 0x60, 
  0xcf, 0xff, 0xff, 0xfe, 0x60, 0xcf, 0xff, 0xff, 0xfe, 0x60, 0xcf, 0xff, 0xff, 0xfe, 0x60, 0xc7, 
  0xff, 0xf7, 0xfe, 0x60, 0xc7, 0xf8, 0xf3, 0xfe, 0x60, 0xc0, 0x01, 0xf0, 0xfe, 0x60, 0x60, 0x01, 
  0xf8, 0x7e, 0xc0, 0x60, 0x03, 0xf8, 0x3c, 0xc0, 0x70, 0x07, 0xf8, 0x19, 0xc0, 0x30, 0x0f, 0xf8, 
  0x01, 0x80, 0x38, 0x1f, 0xf8, 0x03, 0x80, 0x18, 0x3f, 0xf8, 0x03, 0x00, 0x0c, 0x3f, 0xf8, 0x06, 
  0x00, 0x06, 0x1f, 0xf8, 0x0c, 0x00, 0x03, 0x8f, 0xf0, 0x38, 0x00, 0x01, 0xc1, 0x80, 0x70, 0x00, 
  0x00, 0xf8, 0x03, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00
};






void setup() {
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
}
 
void loop() {
  oled.clearDisplay();      // limpia pantalla
  oled.drawBitmap(5, 22, logoBmp, 35, 35, WHITE); 
  oled.display();     // muestra en pantalla todo lo establecido anteriormente
  delay(5000);
}