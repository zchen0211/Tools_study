// If a method in a base class will be redefined in a derived class, you should make it virtual.
// If the method should not be redefined, you should make it nonvirtual.

// The difference between private and protected comes into play only within classes derived from the base class. 
// Members of a derived class can access protected members of a base class directly, but they can- not directly access private members of the base class.

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

std::numeric_limits<size_t>::max();

std::copy();

std::equal();
std::complex;
std::tuple<int, int>;
std::find();

std::get<0> lrs;


std::unordered_set<string> a;
template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator< std::pair<const Key, T> >
> class unordered_map;
// defined in #inlucde <unordered_map>
std::map
std::deque<int> a;
std::hash;


std::initializer_list<TF_Operation*>

/* OS: threads */
// std::lock_guard
template< class Mutex >
class lock_guard;
// std::lock_guard<std::mutex> lock(g_i_mutex);
// used inside a function is to lock_guard to make it thread-safe

// std::mutex
class mutex;
// The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

