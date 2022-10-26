#include "Queue.hpp"
#pragma once

Queue::Queue() : head(NULL), end(NULL), mSize(0)
{
    std::cout << "Enter zone: ";
    std::cin >> zone;

    std::cout << "Enter section: ";
    std::cin >> section;
}

Queue::~Queue() {}

bool Queue::empty()
{
    return head == NULL;
}

unsigned int Queue::size() const
{
    return mSize;
}

Element &Queue::front()
{
    return head->element;
}

Element &Queue::last()
{
    return end->element;
}

void Queue::push(Element element)
{
    Node *newNode = new Node;
    newNode->element = element;

    if (empty())
    {
        head = newNode;
        head->next = NULL;
        mSize++;
        return;
    }

    Node *temp = head;
    Node *prev = temp;

    while (temp)
    {
        if (temp->element.priority >= element.priority)
        {
            prev = temp;
            temp = temp->next;
            continue;
        }
        break;
    }

    if (temp == head)
    {
        head = newNode;
        newNode->next = temp;
        mSize++;
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
    mSize++;

    if (newNode->next == NULL)
    {
        end = newNode;
    }
}

Element Queue::pop()
{
    Node *temp = head;
    head = head->next;
    Element element = temp->element;
    delete temp;
    return element;
}