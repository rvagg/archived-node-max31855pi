# node-max31855pi

**Raspberry Pi driver for the [MAX31855 thermocouple amplifier](http://www.adafruit.com/products/269)**

[![NPM](https://nodei.co/npm/max31855pi.png)](https://nodei.co/npm/max31855pi/)

Uses the [bcm2835 C library](http://www.airspayce.com/mikem/bcm2835/) to talk to the GPIO. If you don't use Node, you're welcome to steal the code in [max31855.cc](src/max31855.cc) which is not Node-specific.

## Usage

```js
var max31855pi = require('max31855pi')
var listener = max31855pi()

listener.on('temperature', function (temp) {
  console.log('Current temp =', temp, 'C')
})

listener.start()
```

There is also a `listener.stop()` to stop the listener.

By default, the CS pin is bound to GPIO P1-15 (22) pin, the SO pin is bound to GPIO P1-21 (9) pin and the SCK pin is bound to the GPIO P1-23 (11) pin. You can change this by supplying an `options` object and overriding the one you want: `max31855pi({ cs: 22, so: 9, sck: 11 })`.

The default temperature-check frequency is 500ms, supply a new frequency value to `listener.start()` if this isn't suitable.

## License

**node-max31855pi** is Copyright (c) 2013 Rod Vagg [@rvagg](https://twitter.com/rvagg) and licenced under the MIT licence. All rights not explicitly granted in the MIT license are reserved. See the included LICENSE file for more details.