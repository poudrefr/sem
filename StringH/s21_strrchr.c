#include "s21_string.h"

char* s21_strrchr(const void* String, int Ch) {
  size_t vLenght = s21_strlen(String);
  char* vOut = NULL;
   char* vString = (char*)&String[vLenght];
     for (size_t i = 0; i <= vLenght && vOut == NULL; i++, vString--) {
       if (*vString == (char)Ch) vOut = vString;
     }
   return vOut;
 }