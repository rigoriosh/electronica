#include <OLED_I2C.h>
#include <math.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];// Selecciono el tamaño de fuente (Small o Big)
//extern uint8_t MediumNumbers[];// Selecciono el tamaño de fuente para los numeros

void setup()
{
  myOLED.begin();//inicializa el display OLED
  myOLED.setFont(SmallFont);//seteo el tamaño de la fuente
  myOLED.print("OLED 128x64", CENTER, 0);//imprime la frase entre comillas
  myOLED.update();// actualiza la pantalla haciendo lo anterior
  delay(1000);
  myOLED.clrScr(); // borra la pantalla
  myOLED.setBrightness(207); // brillo por defecto
  myOLED.sleepMode(SLEEP_OFF); // MODO SLEEP => SLEEP_ON
  // myOLED.rotateDisplay(true); // rotación de la pantalla
  // myOLED.fillScr(); // fill the screen buffer 
  myOLED.invert(false); //  invierter el backgroud del display
  myOLED.setPixel(0,0); //  pinta un pixel de la pantalla por coordenada (x, y)
  myOLED.update();
//  myOLED.clrPixel(0,10); //  limpia un pixel de la pantalla por coordenada (x, y)
//  myOLED.update();
  delay(500);
//  myOLED.invert(true); //  invierter el backgroud del display
//  myOLED.invPixel(0, 10);
  myOLED.print("Thiago, Luisa y Rigo", 2, 0);
//  myOLED.update();
  myOLED.printNumI(555,50,10);
  myOLED.printNumF(555.123,3,0,10);
//  myOLED.invertText(true);
  myOLED.drawLine(0,20,30,30);
  myOLED.update();
  delay(500);
  myOLED.clrLine(0,20,20,20); // limpia una fracción de linea segun las coordenadas
  myOLED.update();
  myOLED.drawRect(64,32,127,63); // dibuja rectangulo
  myOLED.drawRoundRect(0,40,60,60); // dibuja rectangulo
  myOLED.drawCircle(65,45,20); // dibuja rectangulo
  myOLED.update();
  
}

void loop () 
{
  
//  int i=0;
//  int j=0;
//  for(i=0;i<64;i++){
//  myOLED.printNumI(j,j-12,20);// imprime el valor de la entrada analogica(valor,x,y)
//  myOLED.printNumI(i,1,i-8);// imprime el valor de la entrada analogica
//  myOLED.drawLine(1,i,30,i);// dibuja una recta entre (X0,Y0) y (X1,Y1) seteando (X0,Y0,X1,Y1)
//  myOLED.drawLine(j,10,j,30);// dibuja una recta entre (X0,Y0) y (X1,Y1) seteando (X0,Y0,X1,Y1)
//  myOLED.update();//actualiza la pantalla
//  delay(100);
//  myOLED.clrScr(); //borra la pantalla 
//  j=j+1;
//  }
//  delay(500);
//  for(j=63;j<128;j++){
//  myOLED.printNumI(j,j-17,20);// imprime el valor de la entrada analogica(valor,x,y)
//  myOLED.printNumI(63,1,i-8);// imprime el valor de la entrada analogica
//  myOLED.drawLine(1,63,30,63);// dibuja una recta entre (X0,Y0) y (X1,Y1) seteando (X0,Y0,X1,Y1)
//  myOLED.drawLine(j,10,j,30);// dibuja una recta entre (X0,Y0) y (X1,Y1) seteando (X0,Y0,X1,Y1)
//  myOLED.update();//actualiza la pantalla
//  delay(100);
//  myOLED.clrScr(); //borra la pantalla 
//  }
//  myOLED.printNumI(j,j-21,20);// imprime el valor de la entrada analogica(valor,x,y)
//  delay(3000);
}
