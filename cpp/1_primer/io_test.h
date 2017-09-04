//
// Created by ZhuoYuan Chen on 7/2/17.
//

#ifndef HELLO_WORLD_IO_TEST_H
#define HELLO_WORLD_IO_TEST_H

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

void io_test1() {
    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";
    int len = std::strlen(state2);
    cout << "Increasing loop index:\n";
    int i;
    for (i = 1; i <= len; i++) {
        cout.write(state2,i);
        cout << endl;
    }
    // concatenate output
    cout << "Decreasing loop index:\n";
    for (i = len; i > 0; i--)
        cout.write(state2,i) << endl;

    // exceed string length
    cout << "Exceeding string length:\n";
    cout.write(state2, len + 5) << endl;
};

void io_test2() {
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;
    cout << "n    n*n\n";
    cout << n << "     " << n * n << " (decimal)\n";
    // set to hex mode
    cout << hex;
    cout << n << "     ";
    cout << n * n << " (hexadecimal)\n";
    // set to octal mode
    cout << oct << n << " " << n * n << " (octal)\n";
    // alternative way to call a manipulator
    dec(cout);
    cout << n << " " << n * n << " (decimal)\n";
}

#endif //HELLO_WORLD_IO_TEST_H
