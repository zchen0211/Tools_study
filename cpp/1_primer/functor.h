//
// Created by ZhuoYuan Chen on 6/30/17.
//

#ifndef HELLO_WORLD_FUNCTOR_H
#define HELLO_WORLD_FUNCTOR_H

#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

template<class T> // functor class defines operator()()
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void test_functor() {
    TooBig<int> f100(100); // limit = 100
    list<int> yadayada;
    list<int> etcetera;
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    yadayada.insert(yadayada.begin(), vals, vals + 10);
    etcetera.insert(etcetera.begin(), vals, vals + 10);
    std::ostream_iterator<int, char> out(cout, " " );
    cout << "Original lists:\n";
    copy(yadayada.begin(), yadayada.end(), out);
    cout << endl;
    copy(etcetera.begin(), etcetera.end(), out);
    cout << endl;
    yadayada.remove_if(f100); // use a named function object
    etcetera.remove_if(TooBig<int>(200)); // construct a function object
    cout <<"Trimmed lists:\n";
    copy(yadayada.begin(), yadayada.end(), out);
    cout << endl;
    copy(etcetera.begin(), etcetera.end(), out);
    cout << endl;
}

#endif //HELLO_WORLD_FUNCTOR_H
