#ifndef Queue_H
#define Queue_H

#include <iostream>
#include <string>

typedef struct Element
{
    std::string name;
    int priority = 0;
};

typedef struct Node
{
    Element element;
    Node *next;
};

class Queue
{
private:
    Node *head;
    Node *end;
    unsigned int mSize;

    int zone;
    int section;

public:
    Queue();
    ~Queue();

    int getZone() const { return zone; };
    int getSection() const { return section; };

    bool empty();
    unsigned int size() const;
    Element &front();
    Element &last();
    void push(Element element);
    Element pop();
};

#endif