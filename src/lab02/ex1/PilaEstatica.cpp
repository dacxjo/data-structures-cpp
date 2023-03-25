#include <iostream>
#include <initializer_list>
#include "PilaEstatica.h"

// Tamany Constructor
PilaEstatica::PilaEstatica(int tamany_maxim)
{
    this->_capacitat = tamany_maxim;
    this->_dades = new int[this->_capacitat];
    this->_front = -1;
    cout << "Estructura creada" << endl;
}

// Copy Constructor
PilaEstatica::PilaEstatica(const PilaEstatica &origen)
{
    _capacitat = origen._capacitat;
    _dades = new int[_capacitat];
    *_dades = *(origen._dades);
    _front = origen._front;
    cout << "Estructura creada" << endl;
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
    cout << "Estructura creada" << endl;
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
        throw std::out_of_range("EXCEPTION: L'estructura està buida");
    }
    cout << "[";
    for (int i = 0; i <= this->_front; i++)
    {
        cout << _dades[i];
        if (i != this->_front)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int PilaEstatica::elementFront() const
{
    if (this->esBuida())
    {
        throw std::out_of_range("EXCEPTION: L'estructura està buida");
    }
    return this->_dades[_front];
}

void PilaEstatica::afegirElement(int e)
{
    if (this->esPlena())
    {
        throw out_of_range("EXCEPTION: L'estructura està plena");
    }
    this->_front++;
    this->_dades[this->_front] = e;
    cout << "Element " << e << " agregat" << endl;
}

void PilaEstatica::treureElement()
{
    if (this->esBuida())
    {
        throw out_of_range("EXCEPTION: L'estructura està buida");
    }
    cout << "Element " << this->elementFront() << " eliminat" << endl;
    this->_front--;
}
