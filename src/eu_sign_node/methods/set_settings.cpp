#include <iostream>

#include "../../include/eu_sign_node.h"

Napi::Value EuSignNode::SetSettings(const Napi::CallbackInfo &info) {

  unsigned long errorCode;

  if (!g_pIface->DoesNeedSetSettings()) {
    return Napi::Number::New(info.Env(), EU_ERROR_NONE);
  }
  std::cout << "DONE";

  int nSaveSettings = EU_SETTINGS_ID_NONE;

  errorCode =
      g_pIface->SetRuntimeParameter(EU_SAVE_SETTINGS_PARAMETER, &nSaveSettings,
                                    EU_SAVE_SETTINGS_PARAMETER_LENGTH);
  if (errorCode != EU_ERROR_NONE)
    return Napi::Number::New(info.Env(), errorCode);

  int bOffline = 0;
  errorCode = g_pIface->SetModeSettings(bOffline);
  if (errorCode != EU_ERROR_NONE)
    return Napi::Number::New(info.Env(), errorCode);

  Napi::Object settingsData = info[0].As<Napi::Object>();

  // Setup of FileStorageSettings
  Napi::Object fileStorageSettings =
      settingsData.Get('fileStorageSettings').As<Napi::Object>();

  char *pszPath = (char *)fileStorageSettings.Get('path')
                      .As<Napi::String>()
                      .Utf8Value()
                      .data();
  int bCheckCRLs = fileStorageSettings.Get('checkCRLs').As<Napi::Number>();
  int bAutoRefresh = fileStorageSettings.Get('autoRefresh').As<Napi::Number>();
  int bOwnCRLsOnly = fileStorageSettings.Get('ownCRLsOnly').As<Napi::Number>();
  int bFullAndDeltaCRLs =
      fileStorageSettings.Get('fullAndDeltaCRLs').As<Napi::Number>();
  int bAutoDownloadCRLs =
      fileStorageSettings.Get('autoDownloadCRLs').As<Napi::Number>();
  int bSaveLoadedCerts =
      fileStorageSettings.Get('saveLoadedCerts').As<Napi::Number>();
  unsigned long dwExpireTime =
      fileStorageSettings.Get('expireTime').As<Napi::Number>().Uint32Value();

  errorCode = g_pIface->SetFileStoreSettings(
      pszPath, bCheckCRLs, bAutoRefresh, bOwnCRLsOnly, bFullAndDeltaCRLs,
      bAutoDownloadCRLs, bSaveLoadedCerts, dwExpireTime);
}