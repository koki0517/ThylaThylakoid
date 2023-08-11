#include <Arduino.h>
#include "HardwareSerial.h"
#include <Wire.h>
#include <SparkFun_VL53L5CX_Library.h>
#include "VL53L5CX.h"

SparkFun_VL53L5CX myImager_left;
VL53L5CX_ResultsData measurementData_left; // Result data class structure, 1356 byes of RAM

SparkFun_VL53L5CX myImager_right;
VL53L5CX_ResultsData measurementData_right; // Result data class structure, 1356 byes of RAM

VL53L5CX tof_left(0x10, null, myImager_left, measurementData_left);
VL53L5CX tof_right(0x11, null, myImager_right, measurementData_right);

void setup(){
  Serial.begin(1115200);
  Wire.begin(); // This resets I2C bus to 100kHz
  Wire.setClock(1000000); //Sensor has max I2C freq of 1MHz
}
void loop(){}

// void setup1(){}
// void loop1(){}