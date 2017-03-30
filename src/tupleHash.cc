#include <node.h>
#include <nan.h>

extern "C" {
  #include "libkeccak/KeccakSponge.h"
  #include "libkeccak/SP800-185.h"
}

/** Tuple hash function TupleHash128, as defined in NIST's Special Publication 800-185,
  * published December 2016.
  * @param  tuple            An array of tuple elements (X) as Buffers.
  * @param  outputByteLength The desired number of output bytes (L).
  * @param  customization    The customization string (S) as a Buffer.
  * @return output Buffer if successful, null otherwise.
  */
static NAN_METHOD(TupleHash128Wrapper) {
  v8::Local<v8::Array> jsArray = v8::Local<v8::Array>::Cast(info[0]);
  size_t outputByteLength = info[1]->IntegerValue();
  Nan::Utf8String customization(info[2].As<v8::Object>());

  TupleElement * tuple = new TupleElement[jsArray->Length()];
  for (unsigned int i = 0; i < jsArray->Length(); i++) {
    v8::Local<v8::Object> tupleBuffer = jsArray->Get(i).As<v8::Object>();
    tuple[i].input = (unsigned char *) node::Buffer::Data(tupleBuffer);
    tuple[i].inputBitLen = node::Buffer::Length(tupleBuffer) * 8;
  }

  v8::Local<v8::Object> outputBuffer = Nan::NewBuffer(outputByteLength).ToLocalChecked();
  unsigned char *outputData = (unsigned char *) node::Buffer::Data(outputBuffer);
  int result = TupleHash128(tuple, jsArray->Length(), outputData, outputByteLength * 8, (unsigned char *) *customization, customization.length() * 8);
  delete[] tuple;
  if (result == 0) {
    info.GetReturnValue().Set(outputBuffer);
  } else {
    info.GetReturnValue().Set(Nan::Null());
  }
}

/** Tuple hash function TupleHash256, as defined in NIST's Special Publication 800-185,
  * published December 2016.
  * @param  tuple            An array of tuple elements (X) as Buffers.
  * @param  outputByteLength The desired number of output bytes (L).
  * @param  customization    The customization string (S) as a Buffer.
  * @return output Buffer if successful, null otherwise.
  */
static NAN_METHOD(TupleHash256Wrapper) {
  v8::Local<v8::Array> jsArray = v8::Local<v8::Array>::Cast(info[0]);
  size_t outputByteLength = info[1]->IntegerValue();
  Nan::Utf8String customization(info[2].As<v8::Object>());

  TupleElement * tuple = new TupleElement[jsArray->Length()];
  for (unsigned int i = 0; i < jsArray->Length(); i++) {
    v8::Local<v8::Object> tupleBuffer = jsArray->Get(i).As<v8::Object>();
    tuple[i].input = (unsigned char *) node::Buffer::Data(tupleBuffer);
    tuple[i].inputBitLen = node::Buffer::Length(tupleBuffer) * 8;
  }

  v8::Local<v8::Object> outputBuffer = Nan::NewBuffer(outputByteLength).ToLocalChecked();
  unsigned char *outputData = (unsigned char *) node::Buffer::Data(outputBuffer);
  int result = TupleHash256(tuple, jsArray->Length(), outputData, outputByteLength * 8, (unsigned char *) *customization, customization.length() * 8);
  delete[] tuple;
  if (result == 0) {
    info.GetReturnValue().Set(outputBuffer);
  } else {
    info.GetReturnValue().Set(Nan::Null());
  }
}

void Init(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE exports, Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE module) {
  Nan::SetMethod(exports, "tupleHash128", TupleHash128Wrapper);
  Nan::SetMethod(exports, "tupleHash256", TupleHash256Wrapper);
}

NODE_MODULE(tupleHash, Init)
