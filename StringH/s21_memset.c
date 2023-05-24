#include "s21_string.h"

void* s21_memset(void* Dest, int NumC, size_t NumN) {
  char* vDest = (char*)Dest;
  while (NumN > 0 ) {
    *vDest = NumC;
    NumN--;
    vDest++;
  }
  return Dest;
}