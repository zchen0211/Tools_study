// The explicit specifier specifies that a constructor or conversion function (since C++11) doesn't allow implicit conversions or copy-initialization. It may only appear within the decl-specifier-seq of the declaration of such a function within its class definition.
explicit

// Assert something as immutable
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


