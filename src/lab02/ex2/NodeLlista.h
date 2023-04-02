#ifndef NODELLISTA_H
#define NODELLISTA_H

template <class Element>
class NodeLlista
{
public:
    NodeLlista();
    NodeLlista(Element element);
    virtual ~NodeLlista();
    const Element &getElement() const;
    NodeLlista<Element> *getNext() const;
    void setNext(NodeLlista<Element> *node);
    NodeLlista<Element> *getPrevious() const;
    void setPrevious(NodeLlista<Element> *node);

private:
    Element _element;
    NodeLlista<Element> *_next;
    NodeLlista<Element> *_previous;
};

template <class Element>
NodeLlista<Element>::NodeLlista()
{
    _next = nullptr;
    _previous = nullptr;
}

template <class Element>
NodeLlista<Element>::NodeLlista(Element element)
{
    _element = element;
    _next = nullptr;
    _previous = nullptr;
}

template <class Element>
NodeLlista<Element>::~NodeLlista()
{
}

template <class Element>
const Element &NodeLlista<Element>::getElement() const
{
    return this->_element;
}

template <class Element>
NodeLlista<Element> *NodeLlista<Element>::getNext() const
{
    return _next;
}

template <class Element>
void NodeLlista<Element>::setNext(NodeLlista<Element> *node)
{
    _next = node;
}

template <class Element>
NodeLlista<Element> *NodeLlista<Element>::getPrevious() const
{
    return _previous;
}

template <class Element>
void NodeLlista<Element>::setPrevious(NodeLlista<Element> *node)
{
    _previous = node;
}

#endif /* NODELLISTA_H */