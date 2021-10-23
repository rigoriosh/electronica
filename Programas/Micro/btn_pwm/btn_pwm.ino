const int out_led_Logo = 2;
const int out_led_band = 3;
const int btn_TRIGGER = 4;
const int out_pwm_FAN = 5;
const int out_pwm_TEMP = 6;
const int btn_UP = 7;
const int btn_inSetup = 8;
const int btn_DOWN = 12;
const int input_TEMP = A0;
const int input_sens_container = A1;

void setup() {

  pinMode(btn_inSetup, INPUT_PULLUP);
  pinMode(btn_UP, INPUT_PULLUP);
  pinMode(btn_DOWN, INPUT_PULLUP);
  pinMode(btn_TRIGGER, INPUT_PULLUP);
  pinMode(out_led_Logo,  OUTPUT);
  pinMode(out_pwm_TEMP, OUTPUT);
  pinMode(out_pwm_FAN, OUTPUT);
  pinMode(out_led_band, OUTPUT);
}

void loop() {
  
  if(digitalRead(btn_TRIGGER)==LOW){
    analogWrite(out_pwm_TEMP, 255);
    analogWrite(out_pwm_FAN, 255);
    digitalWrite(out_led_Logo, HIGH);
    digitalWrite(out_led_band, HIGH);
  }else{
    analogWrite(out_pwm_TEMP, 0);
    analogWrite(out_pwm_FAN, 0);
    digitalWrite(out_led_Logo, LOW);
    digitalWrite(out_led_band, LOW);
  }


}
