#include <nan.h>

using namespace v8;

NAN_METHOD(getCPUID) {
  NanScope();

 Local<Array> obj = NanNew<Array>();
 int i, val;

 for (i = 0; i < 5; i++){
   __asm__("cpuid;"
           :"=a"(val)
           :"0"(i)
           :"%ebx","%ecx","%edx");
   obj->Set(i, NanNew<Number>(val));
 }
  NanReturnValue(obj);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  module->Set(NanNew("exports"),
      NanNew<FunctionTemplate>(getCPUID)->GetFunction());
}

NODE_MODULE(addon, Init)
