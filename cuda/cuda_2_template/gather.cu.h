#include <stdio.h>
#include <cuda_runtime.h>

#define CUDA_1D_KERNEL_LOOP(i, n)                              \
  for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < (n); \
       i += blockDim.x * gridDim.x)

template <typename T>
__global__ void GatherCUDAKernel(const T* params, const int* indices,
                                 T* output,
                                 size_t index_size,
                                 size_t slice_size) {
  CUDA_1D_KERNEL_LOOP(i, index_size * slice_size) {
    int indices_i = i / slice_size;
    int slice_i = i - indices_i * slice_size;  // offset inside the slice
    int gather_i = indices[indices_i];
    int params_i = gather_i * slice_size + slice_i;
    printf("out, offset, number: %d, %d, %f\n", i, params_i, params[params_i]);
    *(output+i) = *(params + params_i);
  }
}


template <typename T>
struct GPUGather {
  // GPUGather() {}
  void operator()(const T* src, const int* index, T* output,
                  const int slice_size,
                  const int index_size) {
    int block = 512;
    int n = slice_size * index_size;
    int grid = (n + block - 1) / block;
    printf("grid, block: %d %d\n", grid, block);
    GatherCUDAKernel<T><<<grid, block>>>(src, index, output, index_size, slice_size);
  }
};

template <typename T>
struct CPUGather {
  // CPUGather() {}
  void operator()(const T* src, const int* index, T* output,
                  const int slice_size,
                  const int index_size) {
    const size_t slice_bytes = slice_size * sizeof(T);

    for (int i = 0; i < index_size; ++i) {
      int index_ = index[i];
      memcpy(output + i * slice_size, src + index_ * slice_size, slice_bytes);
    }
  }
};

template <typename T>
void Gather(const T* src, const int* index, T* output,
            const int slice_size,
            const int index_size,
            bool cpu_flag) {
  if (cpu_flag) {
    CPUGather<T> tmp1;
    tmp1(src, index, output, slice_size, index_size);
  } else {
    GPUGather<T> tmp2;
    tmp2(src, index, output, slice_size, index_size);
  }
}

template <typename T, bool>
struct Gather2 {
  void operator()(const T* src, const int* index, T* output,
                  const int slice_size,
                  const int index_size);
};

template <typename T>
struct Gather2<T, false> {
  void operator()(const T* src, const int* index, T* output,
                  const int slice_size,
                  const int index_size) {
    GPUGather<T> tmp2;
    tmp2(src, index, output, slice_size, index_size);
  }
};

template <typename T>
struct Gather2<T, true> {
  void operator()(const T* src, const int* index, T* output,
                  const int slice_size,
                  const int index_size) {
    CPUGather<T> tmp;
    tmp(src, index, output, slice_size, index_size);
  }
};
