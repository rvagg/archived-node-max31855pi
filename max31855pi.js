const max31855     = require('bindings')('max31855pi.node')
    , EventEmitter = require('events').EventEmitter

    , DEFAULT_FREQUENCY = 500

var ee
function init (options) {
  if (ee)
    return ee

  if (!options)
    options = {}
  ee = new EventEmitter()
  var driver = max31855(options.sck, options.cs, options.so)
  ee.start = function (frequency) {
    this._max31855Interval = setInterval(function () {
      ee.emit('temperature', driver.readCelsius())
    }, frequency || DEFAULT_FREQUENCY)
  }
  ee.stop = function () {
    clearInterval(this._max31855Interval)
  }
  return ee
}

module.exports = init