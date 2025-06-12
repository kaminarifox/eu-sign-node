#include "../../include/eu_sign_node.h"

#include "../../include/data_mappers.h"


Napi::Value EuSignNode::VerifyDataInternal(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  Napi::Buffer<unsigned char> signedDataBuf =
      info[0].As<Napi::Buffer<unsigned char>>();
  unsigned char *signedData = signedDataBuf.Data();

  EU_SIGN_INFO signInfo;
  unsigned char *verifiedData;
  unsigned long verifiedDataSize;

  g_pIface->SetModeSettings(1); // Offline mode enabled

  auto errorCode = g_pIface->VerifyDataInternal(
      NULL, signedData, signedDataBuf.ElementLength(), &verifiedData,
      &verifiedDataSize, &signInfo);

  if (errorCode != 0)
    Napi::Error::New(env, GetErrorMessage(errorCode))
        .ThrowAsJavaScriptException();

  Napi::Buffer<unsigned char> buffer =
      Napi::Buffer<unsigned char>::New(env, verifiedData, verifiedDataSize);

  Napi::Object returnObject = Napi::Object::New(env);
  returnObject.Set(Napi::String::New(env, "signInfo"),
                   DataMappers::SignInfo(info, signInfo));
  returnObject.Set(Napi::String::New(env, "internalData"), buffer);

  return returnObject;
}