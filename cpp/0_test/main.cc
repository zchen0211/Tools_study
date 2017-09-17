#include <iostream>
#include <vector>
#include <inttypes.h>
#include <stdexcept>

using namespace std;

class MyClass {
 public:
  MyClass(int v = 0) : val_(v) {}
  int GetVal() { return val_; }
 
  MyClass(const MyClass&) = delete;
  MyClass& operator=(const MyClass&) = delete;

 private:
  int val_;
};

class MyClass2 {
 public:
  MyClass2(int val) : val_(val) {}
  // const function assume everything as const
  void func(int& i) const { val_ = 2; }
 private:
  // mutable override const and make val_ modifiable in func()
  mutable int val_;
};

int main() {
  // Vector
  std::vector<std::vector<int> > a;
  a.push_back(std::vector<int>());
  a.push_back(std::vector<int>());

  a[0].clear();
  a[1].clear();
  int real = 2;
  int& ref = real;
  a[0].push_back(ref);
  a[1].push_back(1);

  for (int i = 0; i < 2; ++i)
    a.push_back(vector<int>());
  cout << a.size() << endl;

  // Class with deleted functions
  MyClass b(1);
  cout << b.GetVal() << endl;

  // Conversion
  int y = int{1} << 2;
  cout << y << endl;

  const int c1 = 10;
  constexpr int c2 = 10;
  char tmp1[c1];
  char tmp2[c2];

  return 0;
}
