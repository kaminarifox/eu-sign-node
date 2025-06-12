#include <cstring>
#include <ctime>
#include <iconv.h>

#include "../include/helpers.h"

char *convertEncoding(char *inputString) {
  iconv_t iconv_d = iconv_open("UTF-8", "WINDOWS-1251");

  size_t windows1251Length = strlen(inputString);

  size_t utf8BufferSize = windows1251Length * 4;

  char *utf8Text = new char[utf8BufferSize];

  char *inptr = const_cast<char *>(inputString);
  char *outptr = utf8Text;
  size_t inbytesleft = windows1251Length;
  size_t outbytesleft = utf8BufferSize;

  iconv(iconv_d, &inptr, &inbytesleft, &outptr, &outbytesleft);

  utf8Text[utf8BufferSize - outbytesleft] = '\0';

  iconv_close(iconv_d);

  return utf8Text;
}

unsigned long long systemtymeToTimestamp(SYSTEMTIME *st) {
  struct tm time_struct;

  time_struct.tm_year = st->wYear - 1900;
  time_struct.tm_mon = st->wMonth - 1;
  time_struct.tm_mday = st->wDay;
  time_struct.tm_hour = st->wHour;
  time_struct.tm_min = st->wMinute;
  time_struct.tm_sec = st->wSecond;
  time_struct.tm_isdst = -1;

  return mktime(&time_struct);
}