
#include <napi.h>
#include "C.interface.h"
#include <stdlib.h>

// uint32_t *lockId = nullptr;

Napi::Value DisableScreenSleep(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }
  Napi::String reason = info[0].As<Napi::String>();
  uint32_t id = 0;
  bool ok = disableScreenSleep(reason.Utf8Value().c_str(), &id);
  if (ok) {
    return Napi::Number::New(env, id);
  } else {
    return env.Null();
  }
}

Napi::Value EnableScreenSleep(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return Napi::Boolean::New(env, false);
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return Napi::Boolean::New(env, false);
  }
  uint32_t id = info[0].ToNumber().Uint32Value();
  bool ok = enableScreenSleep(id);
  return Napi::Boolean::New(env, ok);
}


Napi::Value OpenUrl(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }
  Napi::String url = info[0].As<Napi::String>();
  bool ok = openUrl(url.Utf8Value().c_str());
  return Napi::Boolean::New(env, ok);
}

// void CleanupHook (void* arg) {
//   printf("cleanup(%d)\n", *static_cast<uint32_t*>(arg));
//   free(arg);
// }

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // lockId = (uint32_t*)malloc(sizeof(uint32_t));
  exports.Set(Napi::String::New(env, "disableScreenSleep"),
    Napi::Function::New(env, DisableScreenSleep));
  exports.Set(Napi::String::New(env, "enableScreenSleep"),
    Napi::Function::New(env, EnableScreenSleep));
  exports.Set(Napi::String::New(env, "openUrl"),
    Napi::Function::New(env, OpenUrl));
  // napi_add_env_cleanup_hook(env, CleanupHook, lockId);         
  return exports;
}

NODE_API_MODULE(awake, Init)
