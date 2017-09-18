// The explicit specifier specifies that a constructor or conversion function (since C++11) doesn't allow implicit conversions or copy-initialization. It may only appear within the decl-specifier-seq of the declaration of such a function within its class definition.
explicit
struct A
{
    A(int) { }
    explicit A(int, int) {}
};
A a1 = 1; // OK
A a2 = {1, 2}; // error

// Assert something as immutable in a class (put const at the end)
const
class A {
  A() {}
  void some_func() const {
    // everything in const can't be modified
  }
}

mutable

volatile

typedef

constexpr

// One member function overide another
override
struct A {
  virtual void foo(); // must be virtual to be overriden
  void bar();
}
struct B : A {
  void foo() const override; // Error: B::foo does not override A::foo
                               // (signature mismatch)
  void foo() override; // OK: B::foo overrides A::foo
  void bar() override; // Error: A::bar is not virtual
};

static_cast

friend

public

protected

private


