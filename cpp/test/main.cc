#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Vector
  vector<vector<int> > a;

  for (int i = 0; i < 2; ++i)
    a.push_back(vector<int>());
  cout << a.size() << endl;

  return 0;
}
