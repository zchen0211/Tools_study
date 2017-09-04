//
// Created by ZhuoYuan Chen on 6/28/17.
//

#ifndef HELLO_WORLD_REVIEW2_H
#define HELLO_WORLD_REVIEW2_H

// beginning of stocks.cpp file #include <iostream>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

const int STKS = 4;

class Stock { // class declaration
private:
    char company[30];
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    // constructor definition
    Stock(); // default constructor
    Stock(const char * co, int n, double pr);
    // destructor
    ~Stock();

    // Copy constructor
    Stock(const Stock & s); // used like Stock a(b);

    // Assignment operator
    Stock & operator=(const Stock & s);

    // friend bool operators
    friend bool operator<(const Stock &st, const Stock &st2);
    friend bool operator>(const Stock &st1, const Stock &st2);
    friend bool operator==(const Stock &st, const Stock &st2);
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
    friend std::istream & operator>>(std::istream & is, Stock & st);

    void acquire(const char * co, int n, double pr);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show();
};
// note semicolon at the end

class JustTesting {
private:
    std::string words;
    int number; public:
    JustTesting(const std::string & s = "Just Testing", int n = 0) {
        words = s;
        number = n;
        std::cout << words << " constructed\n";
    }
    ~JustTesting() { std::cout << words << " destroyed\n";}
    void Show() const {
        std::cout << words << ", " << number << std::endl;
    }
};

void test_class1();
void test_class2();

#endif //HELLO_WORLD_REVIEW2_H
