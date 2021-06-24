/*
 * EEPROM Read
 *
 * Reads the value of each byte of the EEPROM and prints it
 * to the computer.
 * This example code is in the public domain.
 */

#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
int value;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  EEPROM.write(0, 0);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // read a byte from the current address of the EEPROM
  value = EEPROM.read(0);

  
Serial.print(address);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();

  

//  if(value < 200){
//    
//    value = value + 1;
//    EEPROM.write(0, value);
//  }else{
//    digitalWrite(LED_BUILTIN, HIGH);
//  }
  delay(500);
}
