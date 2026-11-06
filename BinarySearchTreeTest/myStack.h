
#ifndef H_MyStack
#define H_MyStack

#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;

template <class Type>
class stackType : public stackADT<Type>
{
private:
    int maxStackSize;
    int stackTop;
    Type* list;

public:
    stackType(int stackSize = 100)
    {
        if (stackSize <= 0)
            maxStackSize = 100;
        else
            maxStackSize = stackSize;

        stackTop = 0;
        list = new Type[maxStackSize];
    }

    ~stackType()
    {
        delete[] list;
    }

    void initializeStack()
    {
        stackTop = 0;
    }

    bool isEmptyStack() const
    {
        return (stackTop == 0);
    }

    bool isFullStack() const
    {
        return (stackTop == maxStackSize);
    }

    void push(const Type& newItem)
    {
        if (!isFullStack())
        {
            list[stackTop] = newItem;
            stackTop++;
        }
        else
        {
            cout << "Cannot add to a full stack." << endl;
        }
    }

    Type top() const
    {
        assert(!isEmptyStack());
        return list[stackTop - 1];
    }

    void pop()
    {
        if (!isEmptyStack())
        {
            stackTop--;
        }
        else
        {
            cout << "Cannot remove from an empty stack." << endl;
        }
    }
};

#endif
