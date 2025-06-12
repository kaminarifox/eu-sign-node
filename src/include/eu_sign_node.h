#ifndef EU_SIGN_NODE_H
#define EU_SIGN_NODE_H

#include <napi.h>

#include "../vendor/EUSignCP.h"

class EuSignNode : public Napi::ObjectWrap<EuSignNode> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  EuSignNode(const Napi::CallbackInfo &info);

private:
  PEU_INTERFACE g_pIface;

  Napi::Value Initialize(const Napi::CallbackInfo &info);
  Napi::Value SetSettings(const Napi::CallbackInfo &info);
  Napi::Value VerifyDataInternal(const Napi::CallbackInfo &info);

  char *GetErrorMessage(unsigned long dwError);
};

#endif