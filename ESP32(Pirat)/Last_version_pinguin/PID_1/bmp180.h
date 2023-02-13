#ifndef BMP180_H
#define BMP180_H
/*#include "Wire.h"*/
#include "I2Cdev.h"

#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
#define SDA_2 32
#define SCL_2 33

TwoWire I2Ctwo = TwoWire(1);
bool init_bmp(){
  I2Ctwo.begin(SDA_2, SCL_2, 100000);
  return bmp.begin(0, &I2Ctwo);
}

float alt()
{
  return bmp.readAltitude();
}

#endif
