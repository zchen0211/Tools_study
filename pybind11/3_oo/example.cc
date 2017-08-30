/* Good examples available at
http://pybind11.readthedocs.io/en/stable/classes.html
*/

#include <pybind11/pybind11.h>

namespace py = pybind11;

class Pet {
public:
    Pet(const std::string &name, const std::string &species)
       : m_name(name), m_species(species) {}
    std::string name() const { return m_name; }
    void setName(const std::string &name_) { m_name = name_;}
    std::string species() const { return m_species; }
private:
    std::string m_name;
    std::string m_species;
};

class Dog : public Pet {
public:
    Dog(const std::string &name) : Pet(name, "dog") {}
    std::string bark() const { return "Woof!"; }
};

class Rabbit : public Pet {
public:
    Rabbit(const std::string &name) : Pet(name, "parrot") {}
};

/*
class Pet {
public:
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
private:
    std::string name;
};

*/

PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

    py::class_<Pet> pet_class(m, "Pet", py::dynamic_attr());
    pet_class
        .def(py::init<std::string, std::string>())
        .def("name", &Pet::name)
        .def("species", &Pet::species)
        .def("setName", &Pet::setName);
    
    py::class_<Dog>(m, "Dog", pet_class, py::dynamic_attr())
        .def(py::init<std::string>());

    m.def("dog_bark", [](const Dog &dog) { return dog.bark(); });

    py::class_<Rabbit, Pet>(m, "Rabbit")
        .def(py::init<std::string>());

    /*
    py::class_<Pet> pet_class(m, "Pet", py::dynamic_attr())
        .def(py::init<const std::string &>())
        // to use member functions to access private member .name
        .def_property("name", &Pet::getName, &Pet::setName)
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        // use __repr__ to print info
        .def("__repr__", [](const Pet &a) {
            return "<example.Pet named '" + a.getName() + "'>";
            }
        );

    */
    return m.ptr();
}
