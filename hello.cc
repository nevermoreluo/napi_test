#include <napi.h>
#include <test_include.h>


Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object Test(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Array b = info[0].As<Array>();

    double arg0 = info[0].As<Napi::Number>().DoubleValue();




    Napi::Object obj = Napi::Object::New(env);



}



Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init)