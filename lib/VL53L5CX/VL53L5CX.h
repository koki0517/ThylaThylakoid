class VL53L5CX{
public:
  VL53L5CX(int8_t x_shut, SparkFun_VL53L5CX *myImager, VL53L5CX_ResultsData *measurementData);
  bool init(int8_t i2c_address);
  int get();
};