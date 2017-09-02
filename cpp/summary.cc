// If a method in a base class will be redefined in a derived class, you should make it virtual.
// If the method should not be redefined, you should make it nonvirtual.

// The difference between private and protected comes into play only within classes derived from the base class. 
// Members of a derived class can access protected members of a base class directly, but they can- not directly access private members of the base class.

auto a= 3;

// std::function, create a function
template< class R, class... Args >
class function<R(Args...)>;
// example in Paddle:
// typedef std::function<BaseClass*(CreateArgs...)> ClassCreator;
// ClassCreator creator; return creator(args...);
// Return an instance of the given class

std::call_once

std::iota

// std::enable_if
template< bool B, class T = void >
struct enable_if;

// type check
//std::is_fundamental
std::cout << std::is_fundamental<int>::value << '\n'; // print true
std::cout << std::is_fundamental<int&>::value << '\n'; // print false
// Similarly, we also have:
// std::is_trivially_constructible<T,Args&&...>::value
// std::is_copy_assignable<T>::value

std::tie
std::swap(a, b);
std::forward();

std::memcpy();
std::numeric_limits<size_t>::max();

//std::move is used to indicate that an object t may be "moved from", i.e. allowing the efficient transfer of resources from t to another object.
std::move();
// std::string str = "Hello";
// std::vector<std::string> v;
// v.push_back(str); // str is still "Hello", a deep copy
// v.push_back(std::move(str)); // str is now "", moved here
// Always combined with unique_ptr

std::copy();

std::sort();
std::min();
std::max();
std::equal();
std::complex;
std::tuple<int, int>;
std::find();

std::get<0> lrs;
std::normal_distribution<double>
int32 dim = std::uniform_int_distribution<int32>;
std::uniform_int_distribution<int> random_int(1, 5);
std::bernoulli_distribution random_bool;
std::shuffle();
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

std::vector<int> a;
// append an element to a container
std::vector::push_back();
std::vector::emplace_back();
std::pair;
std::make_pair;
std::unordered_set<string> a;
// std::unordered_map<string, int> a;
template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator< std::pair<const Key, T> >
> class unordered_map;
// defined in #inlucde <unordered_map>
std::map
std::array
std::deque<int> a;
std::hash;


std::initializer_list<TF_Operation*>

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

/* OS: threads */
// std::lock_guard
template< class Mutex >
class lock_guard;
// std::lock_guard<std::mutex> lock(g_i_mutex);
// used inside a function is to lock_guard to make it thread-safe

// std::mutex
class mutex;
// The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

