#include "../../include/eu_sign_node.h"

char *EuSignNode::GetErrorMessage(unsigned long errorCode) {
  if (g_pIface == NULL)
    return "Library not loaded";

  return g_pIface->GetErrorLangDesc(errorCode, EU_EN_LANG);
}