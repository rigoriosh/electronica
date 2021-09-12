// variables hardware
const int btn_inSetup = 8;
const int btn_UP = 12;
const int btn_DOWN = 7;
const int btn_TRIGGER = 4;
const int salida_pwm_TEMP = 10;
const int salida_pwm_FAN = 11;

/// utils app
const int delay_antirrebote = 20;
const int delay_estados = 300;

// variales temperatura
const int rangTEMP_Min = 0;
const int rangTEMP_Max = 10;
const int constIncremetoDecrementoTEMP = 1;
int stateTEMP = 5;

// variales FAN
const int rangFAN_Min = 0;
const int rangFAN_Max = 255;
const int constIncremetoDecrementoFAN = 10;
int stateFAN = 150;
///

void setup() {
  Serial.begin(9600);
  pinMode(btn_inSetup, INPUT_PULLUP);
  pinMode(btn_UP, INPUT_PULLUP);
  pinMode(btn_DOWN, INPUT_PULLUP);
  pinMode(btn_TRIGGER, INPUT_PULLUP);
  
  renderizaPanelFrontal();
}

void loop() {
  
  
  if(query_state_inputDigital(btn_inSetup)){ // ingreso a ajustes
    TEMP_FAN_off_on("off");
    ajustes_TEMP_FAN();
  }else{
    // consulta gatillo oprimido
    if(query_state_inputDigital(btn_TRIGGER)){
      // contenedor y nivel de escencia ok ?
      if(true){
        TEMP_FAN_off_on("on");
      }else{
        TEMP_FAN_off_on("off");
      }
    }else{
      TEMP_FAN_off_on("off");
    }
  }
  // delay(500);
}


void renderizaPanelFrontal(){
  Serial.println("panelFrontal");
  Serial.print("Temp: ");
  Serial.println(stateTEMP);
  Serial.print("Fan: ");
  Serial.println(stateFAN);
  delay(delay_estados);
}

boolean query_state_inputDigital(int pin){
  boolean state = false;
  if(digitalRead(pin)==LOW){
    delay(delay_antirrebote);
    if(digitalRead(pin)==LOW){
      state = true;
    }   
  }
    return state;
}

void TEMP_FAN_off_on(char action[]){
  if(action == "on"){
    analogWrite(salida_pwm_TEMP, stateTEMP);
    analogWrite(salida_pwm_FAN, stateFAN);
  }else{
    analogWrite(salida_pwm_TEMP, 0);
    analogWrite(salida_pwm_FAN, 0);
  }
}

void ajustes_TEMP_FAN(){
  delay(delay_estados);
    //muestra estado actual de la temperatura
  Serial.println("fixes temp");
  while(!query_state_inputDigital(btn_inSetup)){
    delay(delay_estados);
    if(query_state_inputDigital(btn_UP)){
      stateTEMP = changePWM(true, stateTEMP, rangTEMP_Min, rangTEMP_Max, constIncremetoDecrementoTEMP);
      Serial.println(stateTEMP);
    }else if(query_state_inputDigital(btn_DOWN)){
      stateTEMP = changePWM(false, stateTEMP, rangTEMP_Min, rangTEMP_Max, constIncremetoDecrementoTEMP);
      Serial.println(stateTEMP);
    }
  }
  delay(delay_estados);
    //muestra estado actual de la FAN
  Serial.println("fixes fan");
  while(!query_state_inputDigital(btn_inSetup)){
    delay(delay_estados);
    if(query_state_inputDigital(btn_UP)){
      stateFAN = changePWM(true, stateFAN, rangFAN_Min, rangFAN_Max, constIncremetoDecrementoFAN);
      Serial.println(stateFAN);
    }else if(query_state_inputDigital(btn_DOWN)){
      stateFAN = changePWM(false, stateFAN, rangFAN_Min, rangFAN_Max, constIncremetoDecrementoFAN);
      Serial.println(stateFAN);
    }
  }
  renderizaPanelFrontal();
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