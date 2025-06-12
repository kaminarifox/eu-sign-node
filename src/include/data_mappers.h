#ifndef DATA_MAPPER_H
#define DATA_MAPPER_H

#include <napi.h>

#include "../vendor/EUSignCP.h"

class DataMappers {
public:
  static Napi::Value SignInfo(const Napi::CallbackInfo &info,
                              EU_SIGN_INFO signInfo);
};

#endif