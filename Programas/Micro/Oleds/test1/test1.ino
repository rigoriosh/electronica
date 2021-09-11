#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
extern uint8_t SmallFont[];// Selecciono el tamaño de fuente (Small o Big)
void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.setFont(SmallFont);
}

void loop() {
  // put your main code here, to run repeatedly:
  myOLED.print("TEMP", LEFT, 0);//imprime la frase entre comillas
  myOLED.update();
  for(int i = 0; i <= 100; i++){
//    myOLED.setFont(BigNumbers);
    myOLED.printNumF(float(i)/3,2,RIGHT,0);

    myOLED.update();
  }


  
}
