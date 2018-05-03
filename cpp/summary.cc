// If a method in a base class will be redefined in a derived class, you should make it virtual.
// If the method should not be redefined, you should make it nonvirtual.

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
std::deque<int> a;
std::hash;

std::initializer_list<TF_Operation*>

