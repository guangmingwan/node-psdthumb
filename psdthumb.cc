#include <nan.h>
extern "C" {
  #include "lib_psdthumb.h"
}

void psdthumb(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  if (info.Length() < 3) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

//   if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
//     Nan::ThrowTypeError("Wrong arguments");
//     return;
//   }
  v8::Local<v8::Function> cb = info[2].As<v8::Function>();

  std::string psdPath = *v8::String::Utf8Value(info[0]->ToString());
  std::string thumbPath = *v8::String::Utf8Value(info[1]->ToString());
  psd2thumb(psdPath.c_str(),thumbPath.c_str());
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { Nan::New(thumbPath.c_str()).ToLocalChecked() };

  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
//   double arg0 = info[0]->NumberValue();
//   double arg1 = info[1]->NumberValue();

//   v8::Local<v8::Number> num = Nan::New(arg0 + arg1);

//   info.GetReturnValue().Set(num);
}
void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    // 设置返回值
    info.GetReturnValue().Set(Nan::New("hello world").ToLocalChecked());
}
// 必须有一个Init函数
void Init(v8::Local<v8::Object> exports) {
    // 为exports追加hello方法  > 类似 nodejs中 exports.hello = xxxx;
    exports->Set(Nan::New("psdthumb").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(psdthumb)->GetFunction());
}

// 固定写法
NODE_MODULE(psdthumb, Init)
