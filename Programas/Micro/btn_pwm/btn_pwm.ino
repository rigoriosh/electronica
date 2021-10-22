const int btn_TRIGGER = 4;
const int salida_pwm_TEMP = 6;
void setup() {

  pinMode(btn_TRIGGER, INPUT_PULLUP);
  pinMode(salida_pwm_TEMP, OUTPUT);

  
}

void loop() {
  
  if(digitalRead(btn_TRIGGER)==LOW){
    analogWrite(salida_pwm_TEMP, 255);
  }else{
    analogWrite(salida_pwm_TEMP, 0);
  }


}
