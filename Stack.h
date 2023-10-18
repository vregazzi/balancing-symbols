#include <iostream>
#include <stdexcept>

#include "DoublyLinkedList.h"

template <typename T>
class Stack
{
private:
    DoublyLinkedList<T> backing;

public:
    int size()
    {
        return backing.size();
    };

    void push(T val)
    {
        backing.push_head(val);
    };

    T pop()
    {
        return backing.pop_head();
    }

    T top()
    {
        return backing.get(0);
    }
};
