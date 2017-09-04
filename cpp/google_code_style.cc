// https://google.github.io/styleguide/cppguide.html

// Header Files
// Every .cc should have .h, except test and main()

#ifndef PROJECT_PATH_FILE_H_
#define PROJECT_PATH_FILE_H_

#endif

// Forward Declarations
// Avoid using forward declarations where possible. Just #include the headers you need.

// Inline Functions
// Define functions inline only when they are small, say, 10 lines or fewer.

// Names and Order of Includes
// dir2/foo2.h.
// C system files.
// C++ system files.
// Other libraries' .h files.
// Your project's .h files.

// Unnamed Namespaces and Static Variables
// When definitions in a .cc file do not need to be referenced outside that file, place them in an unnamed namespace or declare them static. Do not use either of these constructs in .h files.

namespace {
...
}  // namespace

// Classes
// Implicit Conversions

// Copyable and Movable Types
// Support copying and/or moving if these operations are clear and meaningful for your type. Otherwise, disable the implicitly generated special functions that perform copies and moves.
// Pros: Objects of copyable and movable types can be passed and returned by value, which makes APIs simpler, safer, and more general.
// Cons: Some types do not need to be copyable, and providing copy operations for such types can be confusing, nonsensical, or outright incorrect.

// Structs vs. Classes
// Use a struct only for passive objects that carry data; everything else is a class.

// Inheritance
// Composition is often more appropriate than inheritance. When using inheritance, make it public.

// Multiple Inheritance
// Only very rarely is multiple implementation inheritance actually useful. We allow multiple inheritance only when at most one of the base classes has an implementation; all other base classes must be pure interface classes tagged with the Interface suffix.

// Interfaces Definition
// It has only public pure virtual ("= 0") methods and static methods (but see below for destructor).
// It may not have non-static data members.
// It need not have any constructors defined. If a constructor is provided, it must take no arguments and it must be protected.
// If it is a subclass, it may only be derived from classes that satisfy these conditions and are tagged with the Interfa

// Operator Overloading
// Overload operators judiciously. Do not create user-defined literals.

// Do not overload &&, ||, , (comma), or unary &. Do not overload operator"", i.e. do not introduce user-defined literals.
// Make data members private, unless they are 
static const

// Functions
// Parameter Ordering
// When defining a function, parameter order is: inputs, then outputs.
// Reference Arguments

// Google-Specific Magic

// Smart pointers

// cpplint
// use cpplint.py to detect style errors

// Rvalue References
// Use rvalue references only to define move constructors and move assignment operators, or for perfect forwarding.
void f(string&& s);

// Friends

// Exceptions
// We do not use C++ exceptions.

// Run-Time Type Information (RTTI)
// Avoid using Run Time Type Information (RTTI).
// Decision trees based on type are a strong indication that your code is on the wrong track.
if (typeid(*data) == typeid(D1)) {
  ...
} else if (typeid(*data) == typeid(D2)) {
  ...
} else if (typeid(*data) == typeid(D3)) {
...

// Casting
// Use C++-style casts like 
static_cast<float>(double_value)
// Do not use cast formats like 
int y = (int)x or int y = int(x)
// Use static_cast as the equivalent of a C-style cast that does value conversion, when you need to explicitly up-cast a pointer from a class to its superclass, or when you need to explicitly cast a pointer from a superclass to a subclass. In this last case, you must be sure your object is actually an instance of the subclass.
// Use const_cast to remove the const qualifier (see const).
// Use reinterpret_cast to do unsafe conversions of pointer types to and from integer and other pointer types. Use this only if you know what you are doing and you understand the aliasing issues.
static_cast
const_cast
reinterpret_cast
dynamic_cast

// Streams
// Use streams where appropriate, and stick to "simple" usages.

// Preincrement and Predecrement
// Use prefix form (++i) of the increment and decrement operators with iterators and other template objects.

// Use of const
// Use const whenever it makes sense. With C++11, constexpr is a better choice for some uses of const.
const     double PI1 = 3.141592653589793;
constexpr double PI2 = 3.141592653589793; // compile time constant
// Both PI1 and PI2 are constant, meaning you can not modify them. However only PI2 is a compile-time constant. It shall be initialized at compiled time.  PI1 may be initialized at compile time or run time. Furthermore, only PI2 can be used in a context that requires a compile-time constant. For example:
constexpr double PI3 = PI1;  // error
constexpr double PI3 = PI2;  // ok
// and
static_assert(PI1 == 3.141592653589793, "");  // error
static_assert(PI2 == 3.141592653589793, "");  // ok

// Integer Types
#include <stdint.h> // contains following
int16_t, uint32_t, int64_t
// Following codes will never terminate!
for (unsigned int i = foo.Length()-1; i >= 0; --i) ...

// 0 and nullptr/NULL
0 // integers
nullptr NULL // for pointers
'\0' // chars

// sizeof
Prefer sizeof(varname) to sizeof(type)

// auto
// Use auto to avoid type names that are noisy, obvious, or unimportant - cases where the type doesn't aid in clarity for the reader. Continue to use manifest type declarations when it helps readability.

// Braced Initializer List
std::vector<string> v{"foo", "bar"};
// Basically the same, ignoring some small technicalities.
// You may choose to use either form.
std::vector<string> v = {"foo", "bar"};
// Usable with 'new' expressions.
auto p = new vector<string>{"foo", "bar"};
// A map can take a list of pairs. Nested braced-init-lists work.
std::map<int, string> m = {{1, "one"}, {2, "2"}};
// A braced-init-list can be implicitly converted to a return type.
std::vector<int> test_function() { return {1, 2, 3}; }
// Iterate over a braced-init-list.
for (int i : {-1, -2, -3}) {}
// Call a function using a braced-init-list.
void TestFunction2(std::vector<int> v) {}
TestFunction2({1, 2, 3});
// Never assign a braced-init-list to an auto local variable. In the single element case, what this means can be confusing.
auto d = {1.23};        // Bad: d is a std::initializer_list<double>
auto d = double{1.23};  // Good -- d is a double, not a std::initializer_list.

// Lambda Expressions
// Passing function as arguments
std::sort(v.begin(), v.end(), [](int x, int y) {
  return Weight(x) < Weight(y);
});
// Some by value, some by reference
int weight = 3;
int sum = 0;
// Captures `weight` by value and `sum` by reference.
std::for_each(v.begin(), v.end(), [weight, &sum](int x) {
  sum += weight * x;
});

// Boost
// Use only approved libraries from the Boost library collection.

// std::hash
// Do not define specializations of std::hash.

// Aliases
typedef Foo Bar;
using Bar = Foo;
using other_namespace::Foo;

// Naming
// Good:
int price_count_reader;    // No abbreviation.
int num_errors;            // "num" is a widespread convention.
int num_dns_connections;   // Most people know what "DNS" stands for.
// Bad:
int n;                     // Meaningless.
int nerr;                  // Ambiguous abbreviation.
int n_comp_conns;          // Ambiguous abbreviation.
int wgc_connections;       // Only your group knows what this stands for.
int pc_reader;             // Lots of things can be abbreviated "pc".
int cstmr_id;              // Deletes internal letters.

// File Names
// my_useful_class.cc
// my-useful-class.cc
// myusefulclass.cc
// myusefulclass_test.cc // _unittest and _regtest are deprecated.

// Type Names
// no underscores
// classes and structs
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...
// typedefs
typedef hash_map<UrlTableProperties *, string> PropertiesMap;
// using aliases
using PropertiesMap = hash_map<UrlTableProperties *, string>;
// enums
enum UrlTableErrors { ...

// Variable Names
string table_name;  // OK - uses underscore.
string tablename;   // OK - all lowercase.
string tableName;   // Bad - mixed case.

// Constant Names
const int kDaysInAWeek = 7;

// Function Names
AddTableEntry()
DeleteUrl()
OpenFileOrDie()

// Macro Names
#define ROUND(x) ...
#define PI_ROUNDED 3.0

// Comment Style
// v.s. /* */

// Lambda Expressions
int x = 0;
auto x_plus_n = [&x](int n) -> int { return x + n; }

std::set<int> blacklist = {7, 8, 9};
std::vector<int> digits = {3, 9, 1, 8, 4, 7, 1};
digits.erase(std::remove_if(digits.begin(), digits.end(), [&blacklist](int i) {
               return blacklist.find(i) != blacklist.end();
             }),
             digits.end());

// Conditionals
if (condition) {  // no spaces inside parentheses
  ...  // 2 space indent.
} else if (...) {  // The else goes on the same line as the closing brace.
  ...
} else {
  ...
}

if(condition) {   // Bad - space missing after IF.
if (condition){   // Bad - space missing before {.
if(condition){    // Doubly bad.

// Loops and Switch Statements
switch (var) {
  case 0: {  // 2 space indent
    ...      // 4 space indent
    break;
  }
  case 1: {
    ...
    break;
  }
  default: {
    assert(false);
  }
}

while (condition) {
  // Repeat test until it returns false.
}
// Empty loop bodies should use an empty pair of braces or continue, but not a single semicolon.
for (int i = 0; i < kSomeNumber; ++i) {}  // Good - one newline is also OK.
while (condition) continue;  // Good - continue indicates no logic.

// Boolean
if (this_one_thing > this_other_thing &&
    a_third_thing == a_fourth_thing &&
    yet_another && last_one) {
  ...
}

// Return Values

// Namespace Formatting
namespace {

void foo() {  // Correct.  No extra indentation within namespace.
  ...
}

}  // namespace

// Horizontal Whitespace
void f(bool b) {  // Open braces should always have a space before them.
  ...
int i = 0;  // Semicolons usually have no space before them.
// Spaces inside braces for braced-init-list are optional.  If you use them,
// put them on both sides!
int x[] = { 0 };
int x[] = {0};

// Spaces around the colon in inheritance and initializer lists.
class Foo : public Bar {
 public:
  // For inline function implementations, put spaces between the braces
  // and the implementation itself.
  Foo(int b) : Bar(), baz_(b) {}  // No spaces inside empty braces.
  void Reset() { baz_ = 0; }  // Spaces separating braces from implementation.
  ...

// Loop and Conditions
if (b) {          // Space after the keyword in conditions and loops.
} else {          // Spaces around else.
}
while (test) {}   // There is usually no space inside parentheses.
switch (i) {
for (int i = 0; i < 5; ++i) {
// Loops and conditions may have spaces inside parentheses, but this
// is rare.  Be consistent.
switch ( i ) {
if ( test ) {
for ( int i = 0; i < 5; ++i ) {
// For loops always have a space after the semicolon.  They may have a space
// before the semicolon, but this is rare.
for ( ; i < 5 ; ++i) {
  ...

// Range-based for loops always have a space before and after the colon.
for (auto x : counts) {
  ...
}
switch (i) {
  case 1:         // No space before colon in a switch case.
    ...
  case 2: break;  // Use a space after a colon if there's code after it.

// Operators
// Assignment operators always have spaces around them.
x = 0;

// Other binary operators usually have spaces around them, but it's
// OK to remove spaces around factors.  Parentheses should have no
// internal padding.
v = w * x + y / z;
v = w*x + y/z;
v = w * (x + z);

// No spaces separating unary operators and their arguments.
x = -5;
++x;
if (x && !y)
  ...

// Template and Casts
// No spaces inside the angle brackets (< and >), before
// <, or between >( in a cast
std::vector<string> x;
y = static_cast<char*>(x);

// Spaces between type and pointer are OK, but be consistent.
std::vector<char *> x;
