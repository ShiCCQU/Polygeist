/*
 * @Author: Shi Chen shichen@cqu.edu.cn
 * @Date: 2026-06-23 22:32:33
 * @LastEditors: Shi Chen shichen@cqu.edu.cn
 * @LastEditTime: 2026-06-23 22:36:09
 * @FilePath: /Polygeist/cpp/fir_gnu_complex.cpp
 * @Description:
 *
 * Copyright (c) 2026 by Shi Chen, All Rights Reserved.
 */
#define complex_f32 __complex__ float

static complex_f32 make_complex(float real, float imag) {
  complex_f32 z;
  __real__ z = real;
  __imag__ z = imag;
  return z;
}

void fir_gnu_complex(complex_f32 *in, complex_f32 *coefficients,
                     complex_f32 *out) {
  for (int i = 33; i < 1250; i++) {
    for (int j = 0; j < 33; j++) {
      out[i - 33] = out[i - 33] + coefficients[j] * in[i - 1 - j];
    }
  }
}

float demo_complex_muladd_real() {
  complex_f32 a = make_complex(1.0f, 2.0f);
  complex_f32 b = make_complex(3.0f, 4.0f);
  complex_f32 c = a * b + a;
  return __real__ c;
}
