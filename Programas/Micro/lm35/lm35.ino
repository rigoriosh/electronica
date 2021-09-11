int SENSOR_TEMP;
const int countPromedio = 2000;
float TEMP_GRADOS_CELCIUS;
float SUMA;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < countPromedio; i++){
    SUMA = SUMA + analogRead(A0);
//    delay(5);
  }
  SENSOR_TEMP = SUMA / 2000.0;
  TEMP_GRADOS_CELCIUS = ((SENSOR_TEMP * 5000.0)/1023)/10; // resultado en °C
  Serial.println(TEMP_GRADOS_CELCIUS); // imprime solo una fracción decimal
  SUMA = 0;
//  delay(500);
    

}
