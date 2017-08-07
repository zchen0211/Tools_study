/**
 * Copyright 1993-2015 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

/**
 * Vector addition: C = A + B.
 *
 * This sample is a very basic sample that implements element by element
 * vector addition. It is the same as the sample illustrating Chapter 2
 * of the programming guide with some additions like error checking.
 */

#include <stdio.h>

// For the CUDA runtime routines (prefixed with "cuda_")
#include <cuda_runtime.h>

//#include <helper_cuda.h>
/**
 * CUDA Kernel Device code
 *
 * Computes the vector addition of A and B into C. The 3 vectors have the same
 * number of elements numElements.
 */

#define CUDA_1D_KERNEL_LOOP(i, n)                                              \
  for (int i = blockIdx.x * blockDim.x + threadIdx.x;                          \
       i < (n);                                                                \
       i += blockDim.x * gridDim.x)


__global__ void
print_kernel(const int N)
{
  // int i = blockDim.x * blockIdx.x + threadIdx.x;
  CUDA_1D_KERNEL_LOOP(i, N) { 
    printf("Hello %d from gridDim %d, blockDim %d, blockId %d, thread %d\n", i, gridDim.x, blockDim.x, blockIdx.x, threadIdx.x);
  }
}

/**
 * Host main routine
 */
int main(void)
{
  print_kernel<<<5, 10>>>(50);

  cudaDeviceSynchronize();

  return 0;
}

