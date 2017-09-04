//
// Created by ZhuoYuan Chen on 6/28/17.
//

#ifndef HELLO_WORLD_REVIEW1_H
#define HELLO_WORLD_REVIEW1_H

#include <string>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

namespace basic_test {
    int test();

    void hexoct();

    void compound();

    struct inflatable {
        std::string name;
        float volume;
        double price;
    };
    union one4all {
        int int_val;
        float float_val;
    };
    enum color {
        red, orange, yellow
    };

    int add(int a, int b);

// Study of template in functions
// Should only be put here
    template<class T>
    void Swap(T &a, T &b) {
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
}

void namespace_test();

#endif //HELLO_WORLD_REVIEW1_H
