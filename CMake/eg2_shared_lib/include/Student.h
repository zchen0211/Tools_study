#pragma once

class Student {
public:
  Student(int id) : id_(id) {}
  void Print();
private:
  int id_;
};
