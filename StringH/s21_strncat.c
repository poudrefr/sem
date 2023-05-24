#include "s21_string.h"

char* s21_strncat(char* Dest, const char* Src, s21_size_t N) {
  s21_size_t vLenDest = 0;
  s21_size_t vLenSrc = 0;
  for (; *(Dest + vLenDest); vLenDest++)
    ;
  for (; vLenSrc < N; vLenSrc++) {
    Dest[vLenDest + vLenSrc] = Src[vLenSrc];
  }
  Dest[vLenDest + vLenSrc] = '\0';
  return Dest;
}