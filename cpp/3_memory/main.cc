#include <iostream>
#include <memory>
#include <cstring>

int main() {
  int a[8];
  int b[8];
  for (int i = 0; i < 8; ++i) {
    a[i] = 0;
    b[i] = i;
  }

  void* a_alias = a; 
  void* b_alias = b; 

  int offset = sizeof(int) / sizeof(void);

  memcpy(a_alias, b_alias+4*offset, 4*sizeof(int));
  memcpy(a_alias+4*offset, b_alias, 4*sizeof(int));

  for (int i = 0; i < 8; ++i)
    std::cout << a[i] << std::endl;

  return 0;
}
