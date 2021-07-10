#include <EEPROM.h>
// Entradas
const int PUL_S1 = 2;
const int PUL_S2 = 4;
const int PUL_S3 = 7;
const int Master = 8;
const int Micro = 12;
const int Reset = 13;

// Salidas
const int S1 = 3;
const int S2 = 5;
const int S3 = 6;
const int S4 = 9;
const int S5 = 10;
const int S6 = 11;
//CONSTANTES
const int delayPrueba = 200;
const int delayAntiRebote = 100;
const int dirMemoria = 0;

//VARIABLES
int entrada_PUL_S1 = 0;
int entrada_PUL_S2 = 0;
int entrada_PUL_S3 = 0;
int entrada_Master = 0;
int entrada_Micro = 0;

int oFF_Salidas = 1;
bool memoriaOK = true;
int valueMemoria;

void setup() {
    //  Serial.begin(9600);
    //  while (!Serial) {
    //    ; // wait for serial port to connect. Needed for native USB port only
    //  }
  pinMode(PUL_S1, INPUT_PULLUP);
  pinMode(PUL_S2, INPUT_PULLUP);
  pinMode(PUL_S3, INPUT_PULLUP);
  pinMode(Master, INPUT_PULLUP);
  pinMode(Micro, INPUT_PULLUP);
  pinMode(Reset, INPUT_PULLUP);

  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(S5, OUTPUT);
  pinMode(S6, OUTPUT);
  setLowOutputs();
  check_eeprom();
}

void loop() {
  inicioLogicaControlador();
}

void inicioLogicaControlador(){
  
  leerEntradas();
  if(entrada_Master == LOW){

    if(entrada_PUL_S1 == 0){
      digitalWrite(S1, !oFF_Salidas);
      if(entrada_Micro == LOW){
        digitalWrite(S4, !oFF_Salidas);
      }else{
        digitalWrite(S4, oFF_Salidas);
      }
    }else{
      digitalWrite(S1, oFF_Salidas);
      digitalWrite(S4, oFF_Salidas);
    }

    if(entrada_PUL_S2 == 0 and memoriaOK == true){
      digitalWrite(S2, !oFF_Salidas);
      if(entrada_Micro == LOW){
        digitalWrite(S5, !oFF_Salidas);
      }else{
        digitalWrite(S5, oFF_Salidas);
      }    
    }else{
      digitalWrite(S2, oFF_Salidas);
      digitalWrite(S5, oFF_Salidas);
    }

    if(entrada_PUL_S3 == 0 and memoriaOK == true){
      digitalWrite(S3, !oFF_Salidas);
      if(entrada_Micro == LOW){
        digitalWrite(S6, !oFF_Salidas);
      }else{
        digitalWrite(S6, oFF_Salidas);
      }    
    }else{
      digitalWrite(S3, oFF_Salidas);
      digitalWrite(S6, oFF_Salidas);
    }
    delay(delayAntiRebote);
    }else{
      setLowOutputs();
    }
}

void resetMemoria(){
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}

void leerEntradas(){
  entrada_PUL_S1 = digitalRead(PUL_S1);
  entrada_PUL_S2 = digitalRead(PUL_S2);
  entrada_PUL_S3 = digitalRead(PUL_S3);
  entrada_Master = digitalRead(Master);
  entrada_Micro = digitalRead(Micro);
}

void setLowOutputs(){
  
  digitalWrite(S1, oFF_Salidas);
  digitalWrite(S2, oFF_Salidas);
  digitalWrite(S3, oFF_Salidas);
  digitalWrite(S4, oFF_Salidas);
  digitalWrite(S5, oFF_Salidas);
  digitalWrite(S6, oFF_Salidas);  
}

void PruebasSalidas(){
  for(int i = 0; i < 3; i++){
    secuecniaPrueba();
  }

  for(int i = 0; i < 3; i++){
    blinkAllOut();
  }
}

void secuecniaPrueba(){
  digitalWrite(S1, !oFF_Salidas);
  delay(delayPrueba);  
  digitalWrite(S1, oFF_Salidas);
  delay(delayPrueba);
  digitalWrite(S2, !oFF_Salidas);
  delay(delayPrueba);  
  digitalWrite(S2, oFF_Salidas);
  delay(delayPrueba);
  digitalWrite(S3, !oFF_Salidas);
  delay(delayPrueba);  
  digitalWrite(S3, oFF_Salidas);
  delay(delayPrueba);
  digitalWrite(S4, !oFF_Salidas);
  delay(delayPrueba);  
  digitalWrite(S4, oFF_Salidas);
  delay(delayPrueba);
  digitalWrite(S5, !oFF_Salidas);
  delay(delayPrueba);  
  digitalWrite(S5, oFF_Salidas);
  delay(delayPrueba);
  digitalWrite(S6, !oFF_Salidas);
  delay(delayPrueba);  
  digitalWrite(S6, oFF_Salidas);
  delay(delayPrueba);
}

void blinkAllOut(){
  oFF_Salidas = 0;
  setLowOutputs();
  delay(delayPrueba);
  oFF_Salidas = 1;
  setLowOutputs();
  delay(delayPrueba);
  
}

void check_eeprom(){

  if(digitalRead(Reset) == LOW){
    resetMemoria();
    memoriaOK = true;
  }else{
    valueMemoria = EEPROM.read(0);
    if(valueMemoria < 100){
      valueMemoria = valueMemoria + 1;
      EEPROM.write(0, valueMemoria);
    }else{
      memoriaOK = false;
    }
    delay(500);
  }
  
}
