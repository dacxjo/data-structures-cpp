#ifndef PILAESTATICA_H
#define PILAESTATICA_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>
using namespace std;

class PilaEstatica
{
public:
    PilaEstatica(int tamany_maxim = TAMANY_MAXIM); // constructor
    PilaEstatica(const PilaEstatica &origen);      // copy constructor
    PilaEstatica(initializer_list<int> elements);  // init the stack from list
    virtual ~PilaEstatica();                       // destructor
    int tamany() const;                            // return the size
    bool esBuida() const;                          // True if the stack is empty
    bool esPlena() const;                          // True if the stack is full
    int elementFront() const;                      // return top element
    void afegirElement(int e);                     // add element to the stack, exception if not possible
    void treureElement();                          // remove top element from stack, exception if not possible
    void imprimeix() const;                        // print all the stack on terminal

private:
    enum
    {
        TAMANY_MAXIM = 10
    };
    int _capacitat;
    int _front;
    int *_dades;
};

#endif /* PILAESTATICA_H */