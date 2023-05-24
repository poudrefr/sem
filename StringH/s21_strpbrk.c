#include "s21_string.h"

char* s21_strpbrk(const char* StringOne, const char* StringTwo) {
  int vCntOne = 0;
  int vCntOut = -1;
  char* vStringOut = NULL;
    for (; StringOne[vCntOne] && (vCntOut < 0); vCntOne++ ) {
      for (int vCntTwo = 0; StringTwo[vCntTwo] && (vCntOut < 0); vCntTwo++) {
        if (StringOne[vCntOne] == StringTwo[vCntTwo]) vCntOut = vCntOne;
      }
    }
    if (vCntOut >= 0) vStringOut = (char*)StringOne + vCntOut;
  return vStringOut;
}