module attributes {dlti.dl_spec = #dlti.dl_spec<#dlti.dl_entry<i1, dense<8> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr, dense<64> : vector<4xi32>>, #dlti.dl_entry<i32, dense<32> : vector<2xi32>>, #dlti.dl_entry<i16, dense<16> : vector<2xi32>>, #dlti.dl_entry<i8, dense<8> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<271>, dense<32> : vector<4xi32>>, #dlti.dl_entry<!llvm.ptr<270>, dense<32> : vector<4xi32>>, #dlti.dl_entry<f128, dense<128> : vector<2xi32>>, #dlti.dl_entry<f64, dense<64> : vector<2xi32>>, #dlti.dl_entry<f16, dense<16> : vector<2xi32>>, #dlti.dl_entry<f80, dense<128> : vector<2xi32>>, #dlti.dl_entry<i64, dense<64> : vector<2xi32>>, #dlti.dl_entry<!llvm.ptr<272>, dense<64> : vector<4xi32>>, #dlti.dl_entry<"dlti.stack_alignment", 128 : i32>, #dlti.dl_entry<"dlti.endianness", "little">>, llvm.data_layout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128", llvm.target_triple = "x86_64-unknown-linux-gnu", "polygeist.target-cpu" = "x86-64", "polygeist.target-features" = "+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87", "polygeist.tune-cpu" = "generic"} {
  func.func @fir() attributes {llvm.linkage = #llvm.linkage<external>} {
    %c1250 = arith.constant 1250 : index
    %c33 = arith.constant 33 : index
    %c1 = arith.constant 1 : index
    %c0 = arith.constant 0 : index
    %c-33_i32 = arith.constant -33 : i32
    %c-1_i32 = arith.constant -1 : i32
    %alloca = memref.alloca() : memref<1250xcomplex<f32>>
    %alloca_0 = memref.alloca() : memref<33xcomplex<f32>>
    %alloca_1 = memref.alloca() : memref<1250xcomplex<f32>>
    scf.for %arg0 = %c33 to %c1250 step %c1 {
      %0 = arith.index_cast %arg0 : index to i32
      %1 = arith.addi %0, %c-33_i32 : i32
      %2 = arith.index_cast %1 : i32 to index
      %3 = arith.addi %0, %c-1_i32 : i32
      scf.for %arg1 = %c0 to %c33 step %c1 {
        %4 = arith.index_cast %arg1 : index to i32
        %5 = memref.load %alloca_0[%arg1] : memref<33xcomplex<f32>>
        %6 = arith.subi %3, %4 : i32
        %7 = arith.index_cast %6 : i32 to index
        %8 = memref.load %alloca_1[%7] : memref<1250xcomplex<f32>>
        %9 = complex.mul %5, %8 : complex<f32>
        %10 = memref.load %alloca[%2] : memref<1250xcomplex<f32>>
        %11 = complex.add %10, %9 : complex<f32>
        memref.store %11, %alloca[%2] : memref<1250xcomplex<f32>>
      }
    }
    return
  }
}
