//
// Created by ZhuoYuan Chen on 6/30/17.
//

#ifndef HELLO_WORLD_NESTING_TEMPLATE_H
#define HELLO_WORLD_NESTING_TEMPLATE_H

#include <iostream>
#include <string>

template <class Item>
class QueueTP {
private:
    enum {
        Q_SIZE = 10
    };

    // Node is a nested class Node
    class Node {
    public:
        Item item;
        Node *next;
        Node(const Item & i):item(i), next(0){ }
    };

    Node *front; // front of queue
    Node *rear; // rear of queue
    int items;
    const int qsize;

    QueueTP(const QueueTP &q) : qsize(0) {}

    QueueTP &operator=(const QueueTP &q) { return *this; }
public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const
    {
        return items == 0;
    }
    bool isfull() const {
        return items == qsize;
    }
    int queuecount() const {
        return items;
    }
    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item &item); // remove item from front
};

// QueueTP methods
template <class Item> QueueTP<Item>::QueueTP(int qs) : qsize(qs) {
    front = rear = 0;
    items = 0;
}

template <class Item> QueueTP<Item>::~QueueTP() {
    Node * temp;
    while (front != 0) {    // while queue is not yet empty
        temp = front;
        front = front->next;
        delete temp;
    }
}

// Add item to queue
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item) {
    if (isfull())
        return false;
    Node * add = new Node(item); // create node
    if (add == NULL)
        return false;
    items++;
    if (front == 0)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

// Place front item into item variable and remove from queue
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front == 0)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = 0;
    return true;
}

void test_nesting() {
    QueueTP<std::string> cs(5);
    std::string temp;
    while(!cs.isfull()) {
        cout << "Please enter your name. You will be "
                "served in the order of arrival.\n"
                " name: ";
        getline(std::cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!\n";

    while (!cs.isempty()) {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
};
#endif //HELLO_WORLD_NESTING_TEMPLATE_H
