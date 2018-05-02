#include <algorithm>

/* smart pointers */

// std::shared_ptr, return a std::shared_ptr of instance type T
// defined in header <memory> as
// template<class T, class... Args>
// shared_ptr<T> make_shared(Args&&... args);
// recommends this than shtd::shared_ptr<T>(new T(args))
auto sp = std::make_shared<int>(12);
std::shared_ptr<int> spp = std::make_shared<int>(10);
// Member functions
// std::shared_ptr::reset, 4 ways
void reset() noexcept;

template< class Y >
void reset( Y* ptr );

template< class Y, class Deleter >
void reset( Y* ptr, Deleter d );

template< class Y, class Deleter, class Alloc >
void reset( Y* ptr, Deleter d, Alloc alloc );
// Member functions
T* get() const noexcept;
// will be called like data_.get();
