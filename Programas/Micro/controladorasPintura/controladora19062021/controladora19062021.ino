// Entradas
const int PUL_S1 = 2;
const int PUL_S2 = 4;
const int PUL_S3 = 7;
const int Master = 8;
const int Micro = 12;
// Salidas
const int S1 = 3;
const int S2 = 5;
const int S3 = 6;
const int S4 = 9;
const int S5 = 10;
const int S6 = 11;
//CONSTANTES
const int delayPrueba = 200;

//VARIABLES
int oFF_Salidas = 1;

int entrada_PUL_S1 = 0;
int entrada_PUL_S2 = 0;
int entrada_PUL_S3 = 0;
int entrada_Master = 0;
int entrada_Micro = 0;
 

void setup() {
  pinMode(PUL_S1, INPUT_PULLUP);
  pinMode(PUL_S2, INPUT_PULLUP);
  pinMode(PUL_S3, INPUT_PULLUP);
  pinMode(Master, INPUT_PULLUP);
  pinMode(Micro, INPUT_PULLUP);

  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(S5, OUTPUT);
  pinMode(S6, OUTPUT);
  setLowOutputs();
}


void loop() {
  
  probandoEntradas();

  
}

void probandoEntradas(){
  leerEntradas();
  if(entrada_PUL_S1 == LOW){
    digitalWrite(S1, !oFF_Salidas);
  }else if(entrada_PUL_S2 == LOW){
    digitalWrite(S2, !oFF_Salidas);
  }else if(entrada_PUL_S3 == LOW){
    digitalWrite(S3, !oFF_Salidas);
  }else if(entrada_Master == LOW){
    digitalWrite(S4, !oFF_Salidas);
  }else if(entrada_Micro == LOW){
    digitalWrite(S5, !oFF_Salidas);
  }else{
    setLowOutputs();
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