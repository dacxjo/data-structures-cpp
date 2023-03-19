#include <iostream>
#include <initializer_list>
#include "PilaEstatica.h"

// Tamany Constructor
PilaEstatica::PilaEstatica(int tamany_maxim)
{
    this->_capacitat = tamany_maxim;
    this->_dades = new int[this->_capacitat];
    this->_front = -1;
}

// Copy Constructor
PilaEstatica::PilaEstatica(const PilaEstatica &origen)
{
    _capacitat = origen._capacitat;
    _dades = new int[_capacitat];
    *_dades = *(origen._dades);
    _front = origen._front;
}

// Initializer Constructor
PilaEstatica::PilaEstatica(initializer_list<int> elements)
{
    this->_capacitat = elements.size();
    this->_dades = new int[this->_capacitat];
    this->_front = -1;
    for (int element : elements)
    {
        this->_front++;
        this->_dades[this->_front] = element;
    }
}

PilaEstatica::~PilaEstatica()
{
    delete[] _dades;
}

int PilaEstatica::tamany() const
{
    return this->_front + 1;
}
bool PilaEstatica::esBuida() const
{
    return this->tamany() == 0;
}

bool PilaEstatica::esPlena() const
{
    return this->tamany() == this->_capacitat;
}

void PilaEstatica::imprimeix() const
{
    if (this->esBuida())
    {
        throw std::out_of_range("La pila esta vacia, no tiene elementos");
    }
    for (int i = _front; i >= 0; i--)
    {
        cout << _dades[i] << endl;
    }
}

int PilaEstatica::elementFront() const
{
    if (this->esBuida())
    {
        throw std::out_of_range("La lista esta vacia");
    }
    return this->_dades[_front];
}

void PilaEstatica::afegirElement(int e)
{
    if (this->esPlena())
    {
        throw out_of_range("La lista esta llena");
    }
    this->_front++;
    this->_dades[this->_front] = e;
}

void PilaEstatica::treureElement()
{
    if (this->esBuida())
    {
        throw out_of_range("La lista esta vacia");
    }
    this->_front--;
}
