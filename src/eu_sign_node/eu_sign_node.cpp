#include "../include/data_mappers.h"
#include "../include/eu_sign_node.h"
#include "../vendor/EUError.h"
#include "../vendor/EUSignCP.h"

#define MAX_INPUT_BUFFER_SIZE 2048

#define CA_DEFAULT_SERVER_ADDRESS "ca.iit.com.ua"
#define CA_DEFAULT_SERVER_PORT "80"

// Register API calls for client JS code
Napi::Object EuSignNode::Init(Napi::Env env, Napi::Object exports) {

  Napi::Function func = DefineClass(
      env, "EuSignNode",
      {InstanceMethod("Initialize", &EuSignNode::Initialize),
       InstanceMethod("SetSettings", &EuSignNode::SetSettings),
       InstanceMethod("VerifyDataInternal", &EuSignNode::VerifyDataInternal)});

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("EuSignNode", func);
  return exports;
}

EuSignNode::EuSignNode(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<EuSignNode>(info) {

  setlocale(LC_ALL, "Ukrainian");

  if (!EULoad()) {
    Napi::Error::New(info.Env(), GetErrorMessage(EU_ERROR_LIBRARY_LOAD))
        .ThrowAsJavaScriptException();
  }

  g_pIface = EUGetInterface();
}




