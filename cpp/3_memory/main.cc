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

  bool* a_alias = a; 
  bool* b_alias = b; 

  std::cout << "bool: " << sizeof(bool) << std::endl;
  std::cout << "int: " << sizeof(int) << std::endl;
  int offset = sizeof(int) / sizeof(bool);

  memcpy(a_alias, b_alias+4*offset, 4*sizeof(int));
  memcpy(a_alias+4*offset, b_alias, 4*sizeof(int));

  for (int i = 0; i < 8; ++i)
    std::cout << a[i] << std::endl;

  return 0;
}
