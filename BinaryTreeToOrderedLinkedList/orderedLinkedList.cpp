#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

orderedLinkedList::orderedLinkedList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

orderedLinkedList::~orderedLinkedList()
{
    initializeList();
}

void orderedLinkedList::initializeList()
{
    nodeType* current;

    while (first != nullptr)
    {
        current = first;
        first = first->link;
        delete current;
    }

    last = nullptr;
    count = 0;
}

bool orderedLinkedList::isEmpty() const
{
    return first == nullptr;
}

void orderedLinkedList::insert(int value)
{
    nodeType* newNode = new nodeType;
    newNode->info = value;
    newNode->link = nullptr;

    if (first == nullptr)
    {
        first = newNode;
        last = newNode;
    }
    else if (value < first->info)
    {
        newNode->link = first;
        first = newNode;
    }
    else
    {
        nodeType* current = first;

        while (current->link != nullptr &&
            current->link->info <= value)
        {
            current = current->link;
        }

        newNode->link = current->link;
        current->link = newNode;

        if (newNode->link == nullptr)
        {
            last = newNode;
        }
    }

    count++;
}

void orderedLinkedList::print() const
{
    nodeType* current = first;

    while (current != nullptr)
    {
        cout << current->info;

        if (current->link != nullptr)
        {
            cout << " -> ";
        }

        current = current->link;
    }

    cout << endl;
}