// RUN: cgeist %s --struct-abi=0 --function='*' -S | FileCheck %s

void foo() {
    __complex__ float a;
}
__complex__ float *bar() {
    auto a = new __complex__ float;
    return a;
}
float access_imag(__complex__ float a) {
    return __imag__ a;
}
float access_real(__complex__ float a) {
    return __real__ a;
}
float ref_imag(__complex__ float a) {
    __imag__ a = 2.0f;
    return __imag__ a;
}
float ref_real(__complex__ float a) {
    __real__ a = 3.0f;
    return __real__ a;
}
double cast(__complex__ float a) {
    __complex__ double b = a;
    return __real__ b + __imag__ b;
}

float imag_literal() {
    __complex__ float b = 10.0f + 3.0fi;
    return __imag__ b + __real__ b;
}
float imag_literal2() {
    __complex__ float b = 3.0fi;
    return __imag__ b + __real__ b;
}
float add() {
    __complex__ float a = 10.0f + 5.0fi;
    __complex__ float b = 30.0f + 2.0fi;
    __complex__ float c = a + b;
    return __imag__ c + __real__ c;
}
float addassign() {
    __complex__ float a = 10.0f + 5.0fi;
    __complex__ float c = 30.0f + 2.0fi;
    c += a;
    return __imag__ c + __real__ c;
}
// CHECK-LABEL: func.func @_Z3barv() -> memref<?xcomplex<f32>>

// CHECK-LABEL: func.func @_Z11access_imagCf(
// CHECK-SAME:    complex<f32>
// CHECK:         complex.im

// CHECK-LABEL: func.func @_Z11access_realCf(
// CHECK-SAME:    complex<f32>
// CHECK:         complex.re

// CHECK-LABEL: func.func @_Z8ref_imagCf(
// CHECK-SAME:    complex<f32>
// CHECK:         arith.constant 2.000000e+00
// CHECK:         return

// CHECK-LABEL: func.func @_Z8ref_realCf(
// CHECK-SAME:    complex<f32>
// CHECK:         arith.constant 3.000000e+00
// CHECK:         return

// CHECK-LABEL: func.func @_Z4castCf(
// CHECK-SAME:    complex<f32>
// CHECK:         complex.re
// CHECK:         arith.extf
// CHECK:         complex.im
// CHECK:         arith.extf

// CHECK-LABEL: func.func @_Z12imag_literalv()
// CHECK:         complex.create

// CHECK-LABEL: func.func @_Z3addv()
// CHECK:         complex.add

// CHECK-LABEL: func.func @_Z9addassignv()
// CHECK:         complex.add
