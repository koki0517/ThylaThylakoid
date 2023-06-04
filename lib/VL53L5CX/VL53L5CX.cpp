#include <Arduino.h>
#include <SparkFun_VL53L5CX_Library.h>
#include <Wire.h>
#include "VL53L5CX.h"

int imageResolution = 0; // Used to pretty print output
int imageWidth = 0;      // Used to pretty print output

long measurements = 0;         // Used to calculate actual output rate
long measurementStartTime = 0; // Used to calculate actual output rate

VL53L5CX::VL53L5CX(int8_t i2c_address,int8_t x_shut_pin, SparkFun_VL53L5CX *myImager, VL53L5CX_ResultsData *measurementData){
  myImagerPtr = myImager;
  measurementDataPtr = measurementData;
  int8_t address = i2c_address;
  int8_t x_shut = x_shut_pin;
  pinMode(x_shut,OUTPUT);
  digitalWrite(x_shut,HIGH);
}

bool VL53L5CX::init(){
  digitalWrite(x_shut,LOW);
  bool result = true;
  if (myImagerPtr->begin() == false){
    result = false;
  }

  if (myImagerPtr->setAddress(i2c_address) == false){
    result = false;
  }
  myImagerPtr->setResolution(8 * 8);
  imageResolution = myImagerPtr->getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth = sqrt(imageResolution); //Calculate printing width
  myImagerPtr->setRangingFrequency(15);
  myImagerPtr->startRanging();

  return result;
}

int VL53L5CX::get(){
  
}

bool reset(){
  digitalWrite(x_shut,HIGH);
  delay(100);
  digitalWrite(x_shut,LOW);
  bool result = true;
  if (myImagerPtr->begin() == false){
    result = false;
  }

  if (myImagerPtr->setAddress(i2c_address) == false){
    result = false;
  }
  myImagerPtr->setResolution(8 * 8);
  imageResolution = myImagerPtr->getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth = sqrt(imageResolution); //Calculate printing width
  myImagerPtr->setRangingFrequency(15);
  myImagerPtr->startRanging();
}