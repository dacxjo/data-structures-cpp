#ifndef LLISTA_H
#define LLISTA_H

#include <iostream>
#include <initializer_list>
#include "NodeLlista.h"
#include "Posicio.h"

template <class Element>
class Llista
{
public:
    Llista();
    Llista(std::initializer_list<Element> elements);
    Llista(const Llista<Element> &origen);
    virtual ~Llista();

    int tamany() const;
    bool esBuida() const;

    Posicio<Element> principi() const;
    Posicio<Element> final() const;

    Posicio<Element> rprincipi() const;
    Posicio<Element> rfinal() const;

    void inserirDespres(Posicio<Element> &position, const Element &element);
    void inserirAbans(Posicio<Element> &position, const Element &element);
    void inserirPrincipi(const Element &element);
    void inserirFinal(const Element &element);
    void elimina(Posicio<Element> &position);
    void printEndavant();
    void printEndarrere();

private:
    NodeLlista<Element> *_cap;
    NodeLlista<Element> *_cua;
    int _tamany;
};

template <typename Element>
Llista<Element>::Llista()
{
    _cap = new NodeLlista<Element>();
    _cua = new NodeLlista<Element>();
    _cap->setNext(_cua);
    _cua->setPrevious(_cap);
    _tamany = 0;
}

template <typename Element>
Llista<Element>::Llista(std::initializer_list<Element> elements)
{
    _cap = new NodeLlista<Element>();
    _cua = new NodeLlista<Element>();
    _cap->setNext(_cua);
    _cua->setPrevious(_cap);
    _tamany = 0;
    for (const Element &element : elements)
    {
        inserirFinal(element);
    }
}

template <typename Element>
Llista<Element>::Llista(const Llista<Element> &origen)
{
    _cap = new NodeLlista<Element>();
    _cua = new NodeLlista<Element>();
    _cap->setNext(_cua);
    _cua->setPrevious(_cap);
    _tamany = 0;
    for (Posicio<Element> itr = origen.principi(); itr.operator!=(origen.final()); itr = itr.operator++())
    {
        inserirFinal(itr.element());
    }
}

template <typename Element>
Llista<Element>::~Llista()
{
}

template <typename Element>
int Llista<Element>::tamany() const
{
    return _tamany;
}

template <typename Element>
bool Llista<Element>::esBuida() const
{
    return _tamany == 0;
}

template <typename Element>
Posicio<Element> Llista<Element>::principi() const
{
    return *new Posicio<Element>(_cap->getNext());
}

template <typename Element>
Posicio<Element> Llista<Element>::final() const
{
    return *new Posicio<Element>(_cua);
}

template <typename Element>
Posicio<Element> Llista<Element>::rprincipi() const
{
    return *new Posicio<Element>(_cua->getPrevious());
}

template <typename Element>
Posicio<Element> Llista<Element>::rfinal() const
{
    return *new Posicio<Element>(_cap);
}

template <typename Element>
void Llista<Element>::inserirDespres(Posicio<Element> &position, const Element &element)
{
    NodeLlista<Element> *newNode = new NodeLlista<Element>(element);
    newNode->setPrevious(new NodeLlista<Element>(position.operator*()));
    newNode->setNext(new NodeLlista<Element>(position.operator++().element()));
    position.operator++().fixarAnterior(newNode);
    position.fixarSeguent(newNode);
    ++_tamany;
}

template <typename Element>
void Llista<Element>::inserirAbans(Posicio<Element> &position, const Element &element)
{
    NodeLlista<Element> *newNode = new NodeLlista<Element>(element);
    newNode->setPrevious(new NodeLlista<Element>(position.operator--().element()));
    newNode->setNext(new NodeLlista<Element>(position.operator*()));
    position.operator--().fixarSeguent(newNode);
    position.fixarAnterior(newNode);
    ++_tamany;
}

template <typename Element>
void Llista<Element>::inserirPrincipi(const Element &element)
{
    NodeLlista<Element> *newNode = new NodeLlista<Element>(element);
    newNode->setPrevious(_cap);
    newNode->setNext(_cap->getNext());
    _cap->getNext()->setPrevious(newNode);
    _cap->setNext(newNode);
    ++_tamany;
}

template <typename Element>
void Llista<Element>::inserirFinal(const Element &element)
{
    NodeLlista<Element> *newNode = new NodeLlista<Element>(element);
    newNode->setPrevious(_cua->getPrevious());
    newNode->setNext(_cua);
    _cua->getPrevious()->setNext(newNode);
    _cua->setPrevious(newNode);
    ++_tamany;
}

template <typename Element>
void Llista<Element>::printEndavant()
{
    for (Posicio<Element> itr = this->principi(); itr.operator!=(this->final()); itr = itr.operator++())
    {
        std::cout << itr.element() << std::endl;
    }
}

template <typename Element>
void Llista<Element>::printEndarrere()
{
    for (Posicio<Element> itr = this->rprincipi(); itr.operator!=(this->rfinal()); itr = itr.operator--())
    {
        std::cout << itr.element() << std::endl;
    }
}

#endif /* LLISTA_H */