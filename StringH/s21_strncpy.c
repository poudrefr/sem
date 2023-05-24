#include "s21_string.h"

char* s21_strncpy(char* Dest, const char* Src, size_t N) {
  char* vSrc = (char*)Src;
  char* vDest = (char*)Dest;
  while (N > 0 ) {
    *vDest = *vSrc;
    N--;
    vDest++;
    vSrc++;
  }
  return Dest;
}