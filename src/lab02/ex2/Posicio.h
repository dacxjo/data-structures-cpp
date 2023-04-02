#ifndef POSICIO_H
#define POSICIO_H

#include "NodeLlista.h"

template <class Element>
class Posicio
{
public:
    Posicio(NodeLlista<Element> *node); // inicialitza la classe Posicio amb el node que rep com a paràmetre.
    Posicio(const Posicio &origen);
    virtual ~Posicio();
    Posicio<Element> next() const;     // retorna la següent posició a l’actual
                                       // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
    Posicio<Element> anterior() const; // retorna l’anterior posició
    const Element &element() const;    // retorna el contingut de l’actual posició
    NodeLlista<Element> *elimina();
    void fixarAnterior(NodeLlista<Element> *node); // assigna l’adreça de l’anterior node
    void fixarSeguent(NodeLlista<Element> *node);  // assigna l’adreça del següent node
    Posicio<Element> operator++() const;           // sobrecarrega operador ++
    Posicio<Element> operator--() const;           // sobrecarrega operador --
    bool operator==(const Posicio &other) const;   // sobrecarrega operador ==
    bool operator!=(const Posicio &other) const;   // sobrecarrega operador !=
    const Element &operator*() const;              // sobrecarrega operador contingut
private:
    NodeLlista<Element> *_node;
};

template <typename Element>
Posicio<Element>::Posicio(NodeLlista<Element> *node)
{
    this->_node = node;
}

template <typename Element>
Posicio<Element>::Posicio(const Posicio &origen)
{
    this->_node = origen._node;
}

template <typename Element>
Posicio<Element>::~Posicio()
{
}

template <typename Element>
Posicio<Element> Posicio<Element>::next() const
{
    if (this->_node->getNext())
    {
        return Posicio<Element>(_node->getNext());
    }
    throw std::invalid_argument("No hi ha següent posició");
}

template <typename Element>
Posicio<Element> Posicio<Element>::anterior() const
{
    if (this->_node->getPrevious())
    {
        return Posicio<Element>(_node->getPrevious());
    }
    throw std::invalid_argument("No hi ha anterior posició");
}

template <typename Element>
const Element &Posicio<Element>::element() const
{
    return this->_node->getElement();
}

template <typename Element>
NodeLlista<Element> *Posicio<Element>::elimina()
{
    NodeLlista<Element> *seguent = _node->getNext();
    NodeLlista<Element> *anterior = _node->getPrevious();
    if (seguent != nullptr)
    {
        seguent->setPrevious(anterior);
    }
    if (anterior != nullptr)
    {
        anterior->setNext(seguent);
    }
    delete _node;
    return seguent;
}

template <typename Element>
void Posicio<Element>::fixarAnterior(NodeLlista<Element> *node)
{
    this->_node->setPrevious(node);
}

template <typename Element>
void Posicio<Element>::fixarSeguent(NodeLlista<Element> *node)
{
    this->_node->setNext(node);
}

template <typename Element>
Posicio<Element> Posicio<Element>::operator++() const
{
    return this->next();
}

template <typename Element>
Posicio<Element> Posicio<Element>::operator--() const
{
    return this->anterior();
}

template <typename Element>
bool Posicio<Element>::operator==(const Posicio &other) const
{
    return this->_node == other._node;
}

template <typename Element>
bool Posicio<Element>::operator!=(const Posicio &other) const
{
    return !(*this == other);
}

template <typename Element>
const Element &Posicio<Element>::operator*() const
{
    return this->_node->getElement();
}

#endif /* POSICIO_H */