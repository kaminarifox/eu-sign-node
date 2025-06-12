#include "../include/data_mappers.h"
#include "../include/helpers.h"

#include <iostream>

Napi::Value DataMappers::SignInfo(const Napi::CallbackInfo &info,
                                 EU_SIGN_INFO signInfo) {
  Napi::Env env = info.Env();
  Napi::Object signInfoObj = Napi::Object::New(env);

  signInfoObj.Set(Napi::String::New(env, "filled"),
                  Napi::Boolean::New(info.Env(), (bool)signInfo.bFilled));
  signInfoObj.Set(
      Napi::String::New(env, "issuer"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszIssuer)));
  signInfoObj.Set(
      Napi::String::New(env, "issuerCN"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszIssuerCN)));
  signInfoObj.Set(
      Napi::String::New(env, "serial"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSerial)));
  signInfoObj.Set(
      Napi::String::New(env, "subject"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubject)));
  signInfoObj.Set(
      Napi::String::New(env, "subjCN"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjCN)));
  signInfoObj.Set(
      Napi::String::New(env, "subjOrg"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjOrg)));
  signInfoObj.Set(
      Napi::String::New(env, "subjOrgUnit"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjOrgUnit)));
  signInfoObj.Set(
      Napi::String::New(env, "subjTitle"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjTitle)));
  signInfoObj.Set(
      Napi::String::New(env, "subjState"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjState)));
  signInfoObj.Set(
      Napi::String::New(env, "subjLocality"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjLocality)));
  signInfoObj.Set(
      Napi::String::New(env, "subjFullName"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjFullName)));
  signInfoObj.Set(
      Napi::String::New(env, "subjAddress"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjAddress)));
  signInfoObj.Set(
      Napi::String::New(env, "subjPhone"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjPhone)));
  signInfoObj.Set(
      Napi::String::New(env, "subjEMail"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjEMail)));
  signInfoObj.Set(
      Napi::String::New(env, "subjDNS"),
      Napi::String::New(info.Env(), convertEncoding(signInfo.pszSubjDNS)));
  signInfoObj.Set(Napi::String::New(env, "subjEDRPOUCode"),
                  Napi::String::New(
                      info.Env(), convertEncoding(signInfo.pszSubjEDRPOUCode)));
  signInfoObj.Set(Napi::String::New(env, "subjDRFOCode"),
                  Napi::String::New(info.Env(), signInfo.pszSubjDRFOCode));
  signInfoObj.Set(Napi::String::New(env, "timeAvail"),
                  Napi::Boolean::New(info.Env(), (bool)signInfo.bTimeAvail));
  signInfoObj.Set(Napi::String::New(env, "timeStamp"),
                  Napi::Boolean::New(info.Env(), (bool)signInfo.bTimeStamp));
  signInfoObj.Set(Napi::String::New(env, "time"),
                  systemtymeToTimestamp(&signInfo.Time));

  return signInfoObj;
}
