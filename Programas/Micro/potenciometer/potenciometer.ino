int testpotenciometer = A1;
float lecturaPotenciometro = 0;
float voltajeOut = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lecturaPotenciometro = map(analogRead(testpotenciometer), 0, 1023, 0, 10);
  //float volSalida = ( 255 * lecturaPotenciometro)/ 1023;
  // analogWrite(13, lecturaPotenciometro);
  Serial.print("lecturaPotenciometro => ");
  Serial.println(lecturaPotenciometro);

  if(lecturaPotenciometro == 0){
    digitalWrite(LED_BUILTIN, LOW);
  }else{
    for(int i = 0; i < 500; i++){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(lecturaPotenciometro);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(lecturaPotenciometro);
    }  
  }

  
  
}
