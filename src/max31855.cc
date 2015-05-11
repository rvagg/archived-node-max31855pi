#include "bcm2835.h"
#include "max31855.h"

MAX31855::MAX31855 (int sckPin, int csPin, int soPin)
    : sckPin(sckPin), csPin(csPin), soPin(soPin) {

  if (!bcm2835_init())
    throw "Error initialising bcm2835";

  bcm2835_gpio_fsel(csPin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(sckPin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(soPin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_write(csPin, HIGH);
  bcm2835_delay(1);
}

MAX31855::~MAX31855 () {
  bcm2835_close();
}

double MAX31855::ReadCelsius () {
  uint32_t temp = 0;
  int i;

  bcm2835_gpio_write(sckPin, LOW);
  bcm2835_delayMicroseconds(100);
  bcm2835_gpio_write(csPin, LOW);
  bcm2835_delayMicroseconds(100);

  for (i = 15; i >= 0; i--) {
    bcm2835_gpio_write(sckPin, LOW);
    bcm2835_delayMicroseconds(100);

    if (bcm2835_gpio_lev(soPin) == HIGH)
      temp |= (1 << i);

    bcm2835_gpio_write(sckPin, HIGH);
    bcm2835_delayMicroseconds(100);
  }

  bcm2835_gpio_write(csPin, HIGH);
  bcm2835_delayMicroseconds(100);

  temp &= 0xfffc;
  return temp / 16.0;
}
