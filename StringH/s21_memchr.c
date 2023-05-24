#include "s21_string.h"

void* s21_memchr(const void* String, int NumC, s21_size_t NumN) {
  char* vOut = NULL;
  char* vString = (char*)String;
  size_t vLenght = strlen(String);
    for (size_t i = 0; vOut == NULL && i < NumN; i++, vString++) {
      if (*vString == (char)NumC) vOut = vString;
    }
  return vOut;
}