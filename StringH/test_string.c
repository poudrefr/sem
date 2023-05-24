#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int s21_strlen(const char* str);
//char* s21_strtok(char* str1, const char* str2);
//void* s21_memchr(const void* String, int NumC, size_t NumN);
//int s21_memcmp(const void* StringOne, const void* StringTwo, size_t N);
//char* s21_strpbrk(const char* StringOne, const char* StringTwo);
//char* s21_strncpy(char *Dest, const char *Src, size_t N);
//char* s21_strrchr(const void* String, int Ch);
char *s21_strtok(char *str, const char *delim);

int main() {
char str1[] = "After a few seconds";
char str2[] = "After a few seconds";
//char str3[] = "w";
//char str4[100] = "\0";
//size_t len_n = 8;
//int c = '\0';
//size_t n = 50;
//printf("{%s}\n", strpbrk(str1, str2));
//printf("[%s]\n", s21_strpbrk(str1, str2));
// printf("@@@@@@@@@\n");
//printf("{%s}\n",(char*)memchr(str1, c, n));
//printf("[%s]\n", (char*)s21_memchr(str1, c, n));
//pattern = strtok(NULL, " ");
  //for (int i = 0; i < 3; i++) {
    char* pattern = strtok(str1, " ");
    char* s21_pattern = s21_strtok(str2, " ");
    while (pattern != NULL) {
      printf("{%s}\n", pattern);
      printf("[%s]\n", s21_pattern);
      pattern = strtok(NULL, " ");
      s21_pattern = s21_strtok(NULL, " ");
    }
  //}
}

// char* s21_strrchr(const void* String, int Ch) {
  // size_t vLenght = s21_strlen(String);
  // char* vOut = NULL;
   // char* vString = (char*)&String[vLenght];
     // for (size_t i = 0; i <= vLenght && (vOut == NULL); i++, vString--) {
       // if (*vString == (char)Ch) vOut = vString;
     // }
   // return vOut;
 // }


// char* s21_strtok(char* String, const char* Delim) {
  // char* vStringPointer = String;
  //
  // char vString[strlen(String)];
  // int vCntTok = 0;
  // size_t vJ = 0;
  // size_t vLenght = strlen(Delim);
  // for (int i = 0; String[i] != '\0'; i++) {
    // for (vJ = 0; vJ < vLenght && vStringPointer[i] != Delim[vJ], vJ++)
      // ;
    // if (vJ == vLenght) vStringPointer++;
    //
    // vCntTok++;
        // //if (vStringPointer[i + j] != Delim[j]) vCntTok = 0;
//
  // }
    // vString
    // vStringPointer++;
  // }
  // return String;
// }

// char* s21_strncpy(char* Dest, const char* Src, size_t N) {
  // char* vSrc = (char*)Src;
  // char* vDest = (char*)Dest;
  // while (N > 0 ) {
    // *vDest = *vSrc;
    // N--;
    // vDest++;
    // vSrc++;
  // }
  // return Dest;
// }




// char* s21_strpbrk(const char* StringOne, const char* StringTwo) {
  // int vCntOne = 0;
  // int vCntOut = -1;
  // char* vStringOut = NULL;
    // for (; StringOne[vCntOne] && (vCntOut < 0); vCntOne++ ) {
      // for (int vCntTwo = 0; StringTwo[vCntTwo] && (vCntOut < 0); vCntTwo++) {
        // if (StringOne[vCntOne] == StringTwo[vCntTwo]) vCntOut = vCntOne;
      // }
    // }
    // if (vCntOut >= 0) vStringOut = (char*)StringOne + vCntOut;
  // return vStringOut;
// }

// void* s21_memchr(const void* String, int NumC, size_t NumN) {
  // char* vOut = NULL;
  // char* vString = (char*)String;
    // for (size_t i = 0; vOut == NULL && i < NumN; i++, vString++) {
      // if (*vString == (char)NumC) vOut = vString;
    // }
  // return vOut;
// }

// void* s21_memchr(const void* String, int NumC, size_t NumN) {
  // char* vOut = NULL;
  // char* vString = (char*)String;
  // //if ((char)NumC != '\0') {
    // for (; (vOut == NULL) && (int)NumN > 0; vString++, NumN--) {
      // if (*vString == (char)NumC) vOut = vString;
    // }
  // //} else {
    // //vOut = "";
  // //}
  // return vOut;
// }




int s21_strlen(const char* str) {
  int len = 0;
  for (; *(str + len); len++)
    ;
  return len;
}




char *s21_strtok(char *str, const char *delim) {
  static char *result = NULL;
  if (str) {
    result = str;
    while (*result && strchr(delim, *result))
      *result++ = '\0';
  }
  if (result != NULL) {
    if (*result != '\0') {
      str = result;
      while (*result && !strchr(delim, *result))
        ++result;
      while (*result && strchr(delim, *result))
        *result++ = '\0';
      } else {
        str = NULL;
      }
    } else {
    str = NULL;
  }
  return str;
}
