


int BtnSubir_Velocidad = 12;
int BtnBajar_Velocidad = 7;
int out_pinBase_FAN = 11;
int INDICADOR = 13;
int salida_PWM = 0;
int delay_antirrebote = 20;
int multiplicador_delay_antirrebote = 3;

void setup() {
  Serial.begin(9600);
  pinMode(BtnSubir_Velocidad, INPUT_PULLUP);
  pinMode(BtnBajar_Velocidad, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(BtnSubir_Velocidad)==LOW){
    delay(delay_antirrebote);
    if(digitalRead(BtnSubir_Velocidad)==LOW){
      changePWM(true);
    }   
  }else if(digitalRead(BtnBajar_Velocidad)==LOW){
    delay(delay_antirrebote);
    if(digitalRead(BtnBajar_Velocidad)==LOW){
      changePWM(false);    
    }
  }
  Serial.println(salida_PWM);
  
}

void changePWM(boolean SUBIR){
  if(SUBIR){
    salida_PWM = salida_PWM + 10;  
    if(salida_PWM > 255){
      salida_PWM = 255;
    }
    
  }else{
    salida_PWM = salida_PWM - 10;  
    if(salida_PWM < 0){
      salida_PWM = 0;
    }
  }
  analogWrite(out_pinBase_FAN, salida_PWM);
  delay(delay_antirrebote * multiplicador_delay_antirrebote);
  }
