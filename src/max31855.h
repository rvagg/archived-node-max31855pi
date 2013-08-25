#ifndef MAX31855_H
#define MAX31855_H

#include "bcm2835.h"

#define MAX31855_DEFAULT_SCKPIN RPI_GPIO_P1_23
#define MAX31855_DEFAULT_CSPIN  RPI_GPIO_P1_15
#define MAX31855_DEFAULT_SOPIN  RPI_GPIO_P1_21

class MAX31855 {
public:
  MAX31855 (int sckPin, int csPin, int soPin);
  ~MAX31855 ();

  double ReadCelsius ();

private:
  int sckPin;
  int csPin;
  int soPin;
};

#endif
