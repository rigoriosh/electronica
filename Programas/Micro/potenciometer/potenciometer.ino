int testpotenciometer = A1;
float lecturaPotenciometro = 0;
float voltajeOut = 0;
int memoryLectura = 0;
long sumaMuestra = 0;
int promedio = 0;
int muestras = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // toma muestras y realiza promedio

  
  sumaMuestra = 0;
  promedio = 0;
  for(int muestra = 0 ; muestra <= 10; muestra ++){
    lecturaPotenciometro = analogRead(testpotenciometer);
    sumaMuestra = sumaMuestra + lecturaPotenciometro;
  }
  promedio = sumaMuestra / 10;

if(promedio < 10){
  promedio = 1;
}else if (promedio > 1000){
  promedio = 1023;
}

if(promedio != memoryLectura){
  memoryLectura = promedio;
  // float volSalida = ( 255 * lecturaPotenciometro)/ 1023;
  // analogWrite(13, lecturaPotenciometro);
  Serial.println("///***************\\\\");
  int mapeado = map(promedio, 1, 1023, 0, 255);
  Serial.print("promedio => ");
  Serial.println(promedio);
  Serial.print("mapeado => ");
  Serial.println(mapeado);

  analogWrite(3, mapeado);
  
//  if(mapeado <= 3){
//    //digitalWrite(LED_BUILTIN, LOW);
//    analogWrite(3, 0);
//  }else{
//    
//    for(int i = 0; i < 500; i++){
//      digitalWrite(LED_BUILTIN, HIGH);   
//      delayMicroseconds(lecturaPotenciometro);                      
//      digitalWrite(LED_BUILTIN, LOW);   
//      delayMicroseconds(lecturaPotenciometro);
//    }  
//  }

}
  
  
  
}
