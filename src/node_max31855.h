#ifndef NODE_MAX31855_H
#define NODE_MAX31855_H

#include <node.h>
#include <nan.h>

class NodeMAX31855 : public node::ObjectWrap {
public:
  NodeMAX31855(int sckPin, int csPin, int soPin);
  ~NodeMAX31855();

  static NAN_METHOD(Create);
  static NAN_METHOD(New);
  static NAN_METHOD(ReadCelsius);

private:
  MAX31855 *max31855;
};

#endif
