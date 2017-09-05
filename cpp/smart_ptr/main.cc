#include <iostream>
#include <memory>
#include <string>
#include "test_class.h"

using namespace std;

unique_ptr<Test> fun() {
    return unique_ptr<Test>(new Test("789"));
}

int main() {
  unique_ptr<Test> ptest(new Test("123"));
  unique_ptr<Test> ptest2(new Test("456"));
    
  ptest->print();
  ptest2 = std::move(ptest);
    
  if (ptest == NULL)
    std::cout << "ptest = NULL\n";
    
  Test* p = ptest2.release();
  p->print();
  ptest.reset(p);
  ptest->print();
    
  ptest2 = fun();
  ptest2->print();
    
  return 0;
}
