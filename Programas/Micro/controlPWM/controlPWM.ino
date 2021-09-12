int salida_PWM = 0;
int out_pinBase_FAN = 11;
int delay_antirrebote = 20;
int multiplicador_delay_antirrebote = 3;

int BtnSubir_Velocidad = 12;
int BtnBajar_Velocidad = 7;
int INDICADOR = 13;

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
      // sube la potenciaz
      salida_PWM = changePWM(true, salida_PWM, 0, 255, 10);
      
    }   
  }else if(digitalRead(BtnBajar_Velocidad)==LOW){
    delay(delay_antirrebote);
    if(digitalRead(BtnBajar_Velocidad)==LOW){
      // baja la potenciaz
      salida_PWM = changePWM(false, salida_PWM, 0, 255, 10);
    }
    
  }
  Serial.println(salida_PWM);
  analogWrite(out_pinBase_FAN, salida_PWM);
  delay(delay_antirrebote * multiplicador_delay_antirrebote);    

}


int changePWM(boolean SUBIR, int salidaPWM, int rangoMinimo, int rangoMaximo, int constanteModificarPWM){
  int salida_PWM = salidaPWM;
  if(SUBIR){
    salida_PWM = salida_PWM + constanteModificarPWM;  
    if(salida_PWM > rangoMaximo){
      salida_PWM = rangoMaximo;
    }
    
  }else{
    salida_PWM = salida_PWM - constanteModificarPWM;  
    if(salida_PWM < rangoMinimo){
      salida_PWM = rangoMinimo;
    }
  }
  return salida_PWM;
}