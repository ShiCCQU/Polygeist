/*
 * @Author: shichen shichen@cqu.edu.cn
 * @Date: 2025-10-04 20:46:58
 * @LastEditors: Shi Chen shichen@cqu.edu.cn
 * @LastEditTime: 2026-06-23 15:41:18
 * @FilePath: /Polygeist/cpp/fir.c
 * @Description:
 *
 * Copyright (c) 2025 by shichen, All Rights Reserved.
 */

// #include "fir.h"

#include <stdio.h>
#include <complex.h>
// here to define the data type
// #define DATA_TYPE std::complex<float>
#define DATA_TYPE float complex

// #define COE_NUM 33
// #define INPUT_DATA_NUM 1250

void fir() {

  DATA_TYPE in[1250];
  DATA_TYPE coefficients[33];
  DATA_TYPE out[1250];
  for (int i = 33; i < 1250; i++) {
    for (int j = 0; j < 33; j++) {
      out[i - 33] += coefficients[j] * in[i - 1 - j];
    }
  }
}
