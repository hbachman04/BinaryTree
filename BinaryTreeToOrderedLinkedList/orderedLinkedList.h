#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

class orderedLinkedList
{
private:
    struct nodeType
    {
        int info;
        nodeType* link;
    };

    nodeType* first;
    nodeType* last;
    int count;

public:
    orderedLinkedList();
    ~orderedLinkedList();

    void initializeList();
    void insert(int value);
    void print() const;
    bool isEmpty() const;
};

#endif