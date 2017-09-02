// rtti: runtime type info
#include <typeinfo>
int i;
typeid(i).name();
// typeid() is an operator

// rtype reference &&
class Blob {
  public:
    Blob(Blob&& other) noexcept {
    }
};
