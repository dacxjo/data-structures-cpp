#include <iostream>
#include "Professor.h"
#include <ctime>
#include <stdexcept>
using namespace std;

Professor::Professor()
{
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    this->anyActual = (tPtr->tm_year) + 1900;
}

Professor::Professor(string nom, int anyNaixement)
{
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    this->anyActual = (tPtr->tm_year) + 1900;
    if (anyNaixement > this->anyActual || anyNaixement < 0 || anyNaixement == 0)
    {
        throw invalid_argument("Any de naixement incorrecte");
    }
    this->nom = nom;
    this->anyNaixement = anyNaixement;
}

int Professor::getEdad()
{
    return this->anyActual - this->anyNaixement;
}

void Professor::print()
{
    cout << "Professor(Nom ==> " << this->nom << ", Naixement ==> " << this->anyNaixement << ")" << endl;
    cout << "Edat del nou Professor: " << this->getEdad() << endl;
    cout << endl;
};