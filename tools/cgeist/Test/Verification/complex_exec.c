// RUN: cgeist %s -o %t && %t

#include <complex.h>

int main() {
  float complex a = 1.0f + 2.0fi;
  float complex b = a * a + a;
  return __real__ b == -2.0f ? 0 : 1;
}
