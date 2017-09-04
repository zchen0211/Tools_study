//
// Created by ZhuoYuan Chen on 7/25/17.
//

#ifndef HELLO_WORLD_MACO_TEST_H
#define HELLO_WORLD_MACO_TEST_H

#include <stdarg.h>
#include <stdio.h>

#define glue(a, b) a##b
#define REGISTER_FUNC(__type_name, __func_name) \
  func_map[__type_name] = __func_name;

#define WARN_IF(EXP) \
{ if (EXP) \
        fprintf (stderr, "Warning: " #EXP "\n"); }
//while (0)

#define xstr(s) str(s)
#define str(s) #s
#define foo 4

/* About __VA_ARGS__
#define showlist(...) puts(#__VA_ARGS__)
showlist();            // expands to puts("")
showlist(1, "x", int); // expands to puts("1, \"x\", int")
##__VA_ARGS__: does nothing when __VA_ARGS__ is not empty;
 otherwise, remove the comma
 */
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

// another try of __VA_ARGS__
#define REGISTER_TEST(integer, ...) \
  register_test(integer, #__VA_ARGS__)

void register_test(int integer, char* _va_args_) {
    std::cout << "Register Test: " << integer << " " << _va_args_ << endl;
}

// This is also correct
//unordered_map<std::string, std::function<void()>> func_map;
static unordered_map<std::string, void(*)(int)> func_map;

// variadic arguments
// study of va_list, va_start, va_arg, va_end
int FindMax (int n, ...)
{
    int i, val, largest;
    va_list vl;
    va_start(vl,n);
    largest=va_arg(vl,int);
    for (i=1;i<n;i++)
    {
        val = va_arg(vl,int);
        largest = (largest>val) ? largest : val;
    }
    va_end(vl);
    return largest;
}

#endif //HELLO_WORLD_MACO_TEST_H
