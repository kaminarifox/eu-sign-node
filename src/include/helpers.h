#ifndef HELPERS_H
#define HELPERS_H

#include "../vendor/EUSignCP.h"

char *convertEncoding(char *inputString);
unsigned long long systemtymeToTimestamp(SYSTEMTIME *st);

#endif /* HELPERS_H */