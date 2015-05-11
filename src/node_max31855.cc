#include <node.h>
#include <nan.h>

#include "max31855.h"
#include "node_max31855.h"

static v8::Persistent<v8::FunctionTemplate> nodeMAX31855Constructor;

NodeMAX31855::NodeMAX31855 (int sckPin, int csPin, int soPin) {
  max31855 = new MAX31855(sckPin, csPin, soPin);
};

NodeMAX31855::~NodeMAX31855 () {
  delete max31855;
};

NAN_METHOD(NodeMAX31855::New) {
  NanScope();

  int sckPin = args[0]->Uint32Value();
  int csPin  = args[1]->Uint32Value();
  int soPin  = args[2]->Uint32Value();

  NodeMAX31855* obj = new NodeMAX31855(sckPin, csPin, soPin);
  obj->Wrap(args.This());

  NanReturnValue(args.This());
}

NAN_METHOD(NodeMAX31855::ReadCelsius) {
  NanScope();

  NodeMAX31855 *nodeMAX31855 =
      node::ObjectWrap::Unwrap<NodeMAX31855>(args.This());

  double temp = nodeMAX31855->max31855->ReadCelsius();

  NanReturnValue(NanNew<v8::Number>(temp));
}

NAN_METHOD(NodeMAX31855::Create) {
  NanScope();

  v8::Local<v8::Integer> sckPin;
  v8::Local<v8::Integer> csPin;
  v8::Local<v8::Integer> soPin;

  if (args.Length() > 0 && args[0]->IsNumber())
    sckPin = v8::Local<v8::Integer>::Cast(args[0]);
  else
    sckPin = NanNew<v8::Integer>(MAX31855_DEFAULT_SCKPIN);

  if (args.Length() > 1 && args[1]->IsNumber())
    csPin = v8::Local<v8::Integer>::Cast(args[1]);
  else
    csPin = NanNew<v8::Integer>(MAX31855_DEFAULT_CSPIN);

  if (args.Length() > 2 && args[2]->IsNumber())
    soPin = v8::Local<v8::Integer>::Cast(args[1]);
  else
    soPin = NanNew<v8::Integer>(MAX31855_DEFAULT_SOPIN);

  v8::Local<v8::FunctionTemplate> constructorHandle =
      NanNew(nodeMAX31855Constructor);

  v8::Handle<v8::Value> argv[] = { sckPin, csPin, soPin };

  v8::Local<v8::Object> instance =
    constructorHandle->GetFunction()->NewInstance(3, argv);

  NanReturnValue(instance);
}

void Init (v8::Handle<v8::Object> exports, v8::Handle<v8::Object> module) {
  v8::Local<v8::FunctionTemplate> tpl = NanNew<v8::FunctionTemplate>(NodeMAX31855::New);
  NanAssignPersistent(nodeMAX31855Constructor, tpl);
  tpl->SetClassName(NanNew("NodeMAX31855"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  NODE_SET_PROTOTYPE_METHOD(tpl, "readCelsius", NodeMAX31855::ReadCelsius);

  v8::Local<v8::Function> create =
      NanNew<v8::FunctionTemplate>(NodeMAX31855::Create)->GetFunction();
  module->Set(NanNew("exports"), create);
}

NODE_MODULE(max31855pi, Init)
