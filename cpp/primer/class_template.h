//
// Created by ZhuoYuan Chen on 6/29/17.
//

#ifndef HELLO_WORLD_CLASS_TEMPLATE_H
#define HELLO_WORLD_CLASS_TEMPLATE_H

typedef unsigned long Item;

template <class Type>
class Stack {
private:
    enum {MAX = 10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty();
    bool isfull();
    // push() returns false if stack already is full, true otherwise
    bool push(const Type & item); // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Type & item); // pop top into item
};


template <class Type>
Stack<Type>::Stack() {
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty() {
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() {
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type & item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else
        return false;
}


#endif //HELLO_WORLD_CLASS_TEMPLATE_H
