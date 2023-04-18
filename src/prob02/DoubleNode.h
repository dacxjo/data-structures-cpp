template <class Element>
class DoubleNode
{
public:
    DoubleNode();
    DoubleNode(Element element);
    ~DoubleNode();
    DoubleNode<Element> *getNext() const;
    void setNext(DoubleNode<Element> *node);
    DoubleNode<Element> *getPrev() const;
    void setPrev(DoubleNode<Element> *node);

private:
    Element _element;
    DoubleNode<Element> *_ next;
    DoubleNode<Element> *_ prev;
};

template <class Element>
DoubleNode<Element>::DoubleNode()
{
    _next = nullptr;
    _prev = nullptr;
}

template <class Element>
DoubleNode<Element>::DoubleNode(Element element)
{
    _next = nullptr;
    _element = element;
    _prev = nullptr;
}

template <class Element>
DoubleNode<Element>::~DoubleNode()
{
    // delete _next;
    // delete _prev;
}

template <class Element>
DoubleNode<Element> *DoubleNode<Element>::getNext() const
{
    return _next;
}

template <class Element>
void DoubleNode<Element>::setNext(DoubleNode<Element> *node)
{
    _next = node;
}

template <class Element>
DoubleNode<Element> *DoubleNode<Element>::getPrev() const
{
    return _prev;
}

template <class Element>
void DoubleNode<Element>::setPrev(DoubleNode<Element> *node)
{
    _prev = node;
}
