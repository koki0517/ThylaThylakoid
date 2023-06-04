#include <Arduino.h>
#include "HardwareSerial.h"
#include <Wire.h>
#include <SparkFun_VL53L5CX_Library.h>

void setup(){
  Serial.begin(1115200);
  Wire.begin(); // This resets I2C bus to 100kHz
  Wire.setClock(1000000); //Sensor has max I2C freq of 1MHz
}
void loop(){}

// void setup1(){}
// void loop1(){}