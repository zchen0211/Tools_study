#include <initializer_list>
#include <iostream>

template<typename T>
class my_vector {
public:
  typedef T* iterator;

public:
  my_vector() : begin_(nullptr), end_(nullptr) {}
  my_vector(std::initializer_list<T> data) : my_vector() {
    for(auto& v : data)
      push_back(v);
  }

private:
  iterator begin_;
  iterator end_;
};

