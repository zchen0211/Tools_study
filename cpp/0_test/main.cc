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

int main() {
  // Vector
  vector<vector<int> > a;

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
