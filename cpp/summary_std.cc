#include <algorithm>

// sort
vector<int> a; //...
std::sort(a.begin(), a.end());
std::sort(a.begin(), a.begin()+4);

/* smart pointers */
// added benefit over using raw pointers is automatic memory management of dynamically allocated resources, so that you don't have to make explicit calls to delete.
//Use a unique_ptr when an object claims ownership of a resource. That is, the object is responsible for managing the memory of the resource, deleting it when it's own destructor is called. Also, note that the assignment operator of a unique_ptr only accepts rvalues, which should be provided by std::move semantics.
std::unique_ptr<int> v1 = std::make_unique<int>(3);

//Use a shared_ptr when you heap-allocate a resource that needs to be shared among multiple objects. It maintains a reference count internally and only deletes the resource when the reference count goes to zero.
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
