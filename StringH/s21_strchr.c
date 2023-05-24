#include "s21_string.h"

char* s21_strchr(const void* String, int Ch) {
  char* vOut = NULL;
  char* vString = (char*)String;
  if ((char)Ch != '\0') {
    for (; *vString && (vOut == NULL); vString++) {
      if (*vString == (char)Ch) vOut = vString;
    }
  } else {
    vOut = "";
  }
  return vOut;
}