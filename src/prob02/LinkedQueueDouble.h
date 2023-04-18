#include "DoubleNode.h"

template <class Element>
class LinkedQueueDouble
{
public:
    LinkedQueueDouble();
    virtual ~LinkedQueueDouble();
    void addBeginTwoElements(Element primer, Element segon);

private:
    DoubleNode<Element> *first;
    DoubleNode<Element> *last;
    int num_elements;
};

template <class Element>
LinkedQueueDouble<Element>::LinkedQueueDouble()
{
    first = nullptr;
    last = nullptr;
    num_elements = 0;
}

template <class Element>
LinkedQueueDouble<Element>::~LinkedQueueDouble()
{
    // delete first;
    // delete last;
}

// Add two elements to the begin of the LinkedQueueDouble implementation checking if is empty or not
template <class Element>
void LinkedQueueDouble<Element>::addBeginTwoElements(Element primer, Element segon)
{
    DoubleNode<Element> *node = new DoubleNode<Element>(primer);
    DoubleNode<Element> *node2 = new DoubleNode<Element>(segon);
    if (first == nullptr)
    {
        node->setNext(node2);
        node2->setPrev(node);
        first = node;
        last = node2;
        num_elements += 2;
    }
    else
    {
        node2->setNext(first);
        node2->setPrev(node);
        node->setNext(node2);
        node->setPrev(nullptr);
        first = node;
        num_elements += 2;
    }
}