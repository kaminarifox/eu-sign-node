#include <napi.h>

#include "include/eu_sign_node.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return EuSignNode::Init(env, exports);
}

NODE_API_MODULE(eu_sign_node, InitAll)