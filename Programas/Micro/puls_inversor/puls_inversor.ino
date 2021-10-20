int testpotenciometer = A1;
int t1 = 0;
float lecturaPotenciometro = 0;
const int pulso1 = 5;
const int pulso2 = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pulso1, OUTPUT);
  pinMode(pulso2, OUTPUT);
}

void loop() {
  
  lecturaPotenciometro = map(analogRead(testpotenciometer), 0, 1023, 0, 1023);
  t1 = lecturaPotenciometro / 8;
  Serial.print("lecturaPotenciometro => ");
  Serial.println(lecturaPotenciometro);
  if(lecturaPotenciometro == 0){
    analogWrite(pulso1, LOW);
    analogWrite(pulso2, LOW);
  }else{
    for(int i = 0; i < 500; i++){
      analogWrite(pulso1, 0);
      delayMicroseconds(t1);  
      analogWrite(pulso1, 150);
      delayMicroseconds(t1); 
      analogWrite(pulso1, 200);
      delayMicroseconds(t1); 
      analogWrite(pulso1, 255);
      delayMicroseconds(2*t1); 
      analogWrite(pulso1, 200);
      delayMicroseconds(t1);
      analogWrite(pulso1, 150);
      delayMicroseconds(t1); 
      analogWrite(pulso1, 0);
      delayMicroseconds(t1);

      analogWrite(pulso2, 0);
      delayMicroseconds(t1);  
      analogWrite(pulso2, 150);
      delayMicroseconds(t1); 
      analogWrite(pulso2, 200);
      delayMicroseconds(t1); 
      analogWrite(pulso2, 255);
      delayMicroseconds(2*t1); 
      analogWrite(pulso2, 200);
      delayMicroseconds(t1);
      analogWrite(pulso2, 150);
      delayMicroseconds(t1); 
      analogWrite(pulso2, 0);
      delayMicroseconds(t1);
      
    }  
    
  }
}

