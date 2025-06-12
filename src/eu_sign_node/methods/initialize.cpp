#include <iostream>

#include "../../include/eu_sign_node.h"

Napi::Value EuSignNode::Initialize(const Napi::CallbackInfo &info) {
  unsigned long errorCode;

  g_pIface->SetUIMode(0);

  errorCode = g_pIface->Initialize();
  if (errorCode != EU_ERROR_NONE) {
    std::cout << GetErrorMessage(errorCode) << std::endl;
    return Napi::Number::New(info.Env(), errorCode);
  }

  g_pIface->SetUIMode(0);

  if (info.Length() > 0 && info[0].IsString()) {
    std::string settingsDirPath = info[0].As<Napi::String>().Utf8Value();
    g_pIface->SetSettingsFilePath(const_cast<char *>(settingsDirPath.data()));
  }

  return Napi::Number::New(info.Env(), EU_ERROR_NONE);
}
