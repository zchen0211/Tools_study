#include <stdio.h>
#include <iostream>
#include "gather.cu.h"

int main() {
  // 3 by 4
  float p_src[12];
  for (int i = 0; i < 12; ++i) p_src[i] = float(i);

  int p_index[2] = {1, 2};
  
  float p_out[8];

  // implemented by function
  // specialization at runtime
  // Gather<float>(p_src, p_index, p_out, 4, 2, true);

  Gather2<float, true> g_functor1;
  g_functor1(p_src, p_index, p_out, 4, 2);

  printf("CPU gather result\n");
  for (int i = 0; i < 8; ++i)
    printf("%f\n", p_out[i]);
  printf("\n");

  // Try on GPU
  float* d_src = NULL;
  int* d_index = NULL;
  float* d_out = NULL;
  cudaMalloc((void**)&d_src, 12 * sizeof(float));
  cudaMalloc((void**)&d_index, 2 * sizeof(int));
  cudaMalloc((void**)&d_out, 8 * sizeof(float));

  cudaMemcpy(d_src, p_src, 12 * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_index, p_index, 2 * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_out, p_out, 8 * sizeof(float), cudaMemcpyHostToDevice);
  
  cudaMemcpy(d_src, p_src, 12 * sizeof(float), cudaMemcpyDeviceToHost);
  cudaMemcpy(d_index, p_index, 2 * sizeof(int), cudaMemcpyDeviceToHost);
  cudaMemcpy(d_out, p_out, 8 * sizeof(float), cudaMemcpyDeviceToHost);
  
  printf("Source:\n");
  for (int i = 0; i < 12; ++i)
    printf("%f\n", p_src[i]);
  printf("\n");
  printf("Index:\n");
  for (int i = 0; i < 2; ++i)
    printf("%d\n", p_index[i]);
  printf("\n");
  printf("Output:\n");
  for (int i = 0; i < 8; ++i)
    printf("%f\n", p_out[i]);
  printf("\n");

  // Gather<float>(d_src, d_index, d_out, 4, 2, false);

  Gather2<float, true> g_functor2;
  g_functor2(p_src, p_index, p_out, 4, 2);
  
  float g_src[12];
  int g_index[2];
  float g_out[8];
  cudaMemcpy(g_src, d_src, 12 * sizeof(float), cudaMemcpyDeviceToHost);
  cudaMemcpy(g_index, d_index, 2 * sizeof(int), cudaMemcpyDeviceToHost);
  cudaMemcpy(g_out, d_out, 8 * sizeof(float), cudaMemcpyDeviceToHost);

  printf("Source:\n");
  for (int i = 0; i < 12; ++i)
    printf("%f\n", g_src[i]);
  printf("Index:\n");
  for (int i = 0; i < 2; ++i)
    printf("%d\n", g_index[i]);
  printf("Output:\n");
  for (int i = 0; i < 8; ++i)
    printf("%f\n", g_out[i]);

  return 0;
}
