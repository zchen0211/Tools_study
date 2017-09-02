// main.cpp
// to carefully study and review how to write c++

#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include <cxxabi.h>

#include "review1.h"
#include "review2.h"
#include "review3.h"
#include "dma.h"
#include "class_template.h"
#include "friends.h"
#include "nesting_template.h"
#include "functor.h"
#include "cast.h"
#include "io_test.h"
#include "os_test.h"
#include "maco_test.h"

using namespace std;

int test() {
    cout << "global namespace print" << endl;
    return 1;
}
void hello(int cnt) {
    cout << "Hello World!" << cnt << endl;
}

//unordered_map<std::string, std::function<void()>> func_map;
//unordered_map<std::string, void(*)()> func_map;

int main() {
    cout << std::is_fundamental<std::string>::value << endl;
    // rtti: a test of typeid()
    // int i = 10;
    int status = 0;
    string final_type;
    auto demangled = ::abi::__cxa_demangle(typeid(string).name(), nullptr, nullptr, &status);
    if (demangled) {
        final_type = string(demangled);
    } else
        final_type = typeid(string).name();
    // return name;

    cout << "final type: " << final_type << endl;
    cout << typeid(float).name() << endl;
    cout << typeid(double).name() << endl;
    cout << typeid(char).name() << endl;

    // a test of ## macro
    glue(c, out) << "Hello World!" << endl;
    REGISTER_FUNC("PangTu", hello);
    func_map["PangTu"](__COUNTER__); // global variable from maco_test.h
    func_map["PangTu"](__COUNTER__); // global variable from maco_test.h
    WARN_IF(3);
    cout << str(foo) << endl; // "foo"
    cout << xstr(foo) << endl; // "4"
    eprintf("abc\n");
    auto m = FindMax(7,702,422,631,834,892,104,772);
    cout << m << endl;
    REGISTER_TEST(10, integer);

    /* mutex and lock_guard test */
    lock_test();

    // test of namespace
    namespace_test();
    // global namespace
    ::test();

    // class study
    test_class1();
    test_class2();

    /*
    // Derived class study
    test_derived1();
    test_derived2();
    //polymorphic (due to virtual)
    test_derived3();

    test_friend();

    // setting class private stuff with friends classes
    test_friend_class();

    // test defining a class inside another class
    test_nesting();

    // functors study
    test_functor();

    // test type cast
    test_cast();*/

    //io_test1();
    //io_test2();

    return 0;
}

