//
// Created by ZhuoYuan Chen on 6/28/17.
//
#include <iostream>
#include "review1.h"

using namespace std;

namespace basic_test {
    int test() {
        int a;
        cin >> a;

        return a;
    }

    void hexoct() {
        int a = 42;
        int b = 0x42;
        int c = 042;
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
    }

    void compound() {
        int a[] = {1, 2, 3}; // cout << a will directly print address
        char b[] = "abc";
        string c("def");
        cout << a << " " << b << " " << c << endl;
        string d = c; // deep copy
        c = "fff";
        cout << d << endl;
    }

    int add(int a, int b) {
        return a + b;
    }

}

void namespace_test() {
    int bunny;

    cout << "Hello, World!" << endl;
    cout << "Input an integer: " << endl;
    bunny = basic_test::test();
    cout << "input: " << bunny << endl;
    cout << "Integer is of " << sizeof(bunny) << "bytes" << endl;
    double x = sqrt(6.25);
    cout << x << endl;
    cout << "Double is of " << sizeof(x) << "bytes" << endl;

    basic_test::hexoct();
    basic_test::compound();

    basic_test::inflatable bouquet = {"Sunflower", 1.5, 20.};
    cout << bouquet.name << endl;

    basic_test::one4all union_test;
    union_test.int_val = 10;
    cout << union_test.float_val << endl;
    basic_test::color enum_test = basic_test::yellow;
    cout << enum_test << endl;

    // test of a pointer to a function
    int (*func)(int, int);
    func = basic_test::add;
    cout << func(2,3) << endl;

    int rabbit = 6;
    basic_test::Swap(bunny, rabbit);
    cout << bunny << " " << rabbit << endl;
}
