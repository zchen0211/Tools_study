#include <iostream>
#include <initializer_list>
#include <typeinfo>

using namespace std;

int main() {
  // int a[] = {1,2,3};
  auto a = {1,2,3};
  // cout << &a[2] - &a[0] << endl;
  cout << typeid(a).name() <<endl;

  return 0;
}
