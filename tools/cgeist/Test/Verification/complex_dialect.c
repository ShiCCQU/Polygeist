// RUN: cgeist %s --function='*' -S | FileCheck %s

float _Complex make_complex() { return 1.0f + 2.0fi; }

float _Complex ops(float _Complex a, float _Complex b) {
  float _Complex c = 1.0f + 2.0fi;
  c = a + b;
  c = c - a;
  c = c * b;
  c = c / b;
  c += a;
  return c;
}

void fir_kernel(float _Complex *in, float _Complex *coefficients,
                float _Complex *out) {
  out[0] += coefficients[0] * in[0];
}

// CHECK-LABEL:   func.func @make_complex() -> complex<f32>
// CHECK:           complex.create
// CHECK:           return {{.*}} : complex<f32>

// CHECK-LABEL:   func.func @ops(
// CHECK-SAME:      complex<f32>
// CHECK-SAME:      complex<f32>
// CHECK-SAME:      -> complex<f32>
// CHECK:           complex.add
// CHECK:           complex.sub
// CHECK:           complex.mul
// CHECK:           complex.div
// CHECK:           complex.add
// CHECK:           return {{.*}} : complex<f32>

// CHECK-LABEL:   func.func @fir_kernel(
// CHECK-SAME:      memref<?xcomplex<f32>>
// CHECK-SAME:      memref<?xcomplex<f32>>
// CHECK-SAME:      memref<?xcomplex<f32>>
// CHECK:           affine.load {{.*}} : memref<?xcomplex<f32>>
// CHECK:           affine.load {{.*}} : memref<?xcomplex<f32>>
// CHECK:           complex.mul
// CHECK:           affine.load {{.*}} : memref<?xcomplex<f32>>
// CHECK:           complex.add
// CHECK:           affine.store {{.*}} : memref<?xcomplex<f32>>
