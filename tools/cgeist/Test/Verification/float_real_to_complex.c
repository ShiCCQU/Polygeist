// RUN: cgeist %s --struct-abi=0 --function='*' -S | FileCheck %s

__complex__ float complextest()
{
  __complex__ float  z=8.0;
  return z;

}

// CHECK-LABEL:   func.func @complextest() -> complex<f32>
// CHECK:           %[[ZERO:.*]] = arith.constant 0.000000e+00 : f32
// CHECK:           %[[REAL:.*]] = arith.constant 8.000000e+00 : f32
// CHECK:           %[[Z:.*]] = complex.create %[[REAL]], %[[ZERO]] : complex<f32>
// CHECK:           return %[[Z]] : complex<f32>
