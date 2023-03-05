/*
 * Estructura de datos
 * Implementacion de la clase  "Estudiant"
 * @author: David de Jesus Blandon Torrez
 */

#include <iostream>
#include "Estudiant.h"
#include <ctime>
#include <stdexcept>
using namespace std;

Estudiant::Estudiant()
{
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    this->anyActual = (tPtr->tm_year) + 1900;
}
Estudiant::Estudiant(string nom, int anyNaixement, int numAssignatures)
{
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    this->anyActual = (tPtr->tm_year) + 1900;
    if (anyNaixement > this->anyActual || anyNaixement < 0 || anyNaixement == 0)
    {
        throw invalid_argument("Any de naixement incorrecte");
    }
    this->nom = nom;
    this->any = anyNaixement;
    this->nombreAsignatures = numAssignatures;
}
int Estudiant::getEdad()
{

    return this->anyActual - this->any;
}
void Estudiant::print()
{
    cout << "Estudiant(Nom ==> " << this->nom << ", Naixement ==> " << this->any << ", Assignatures ==> " << this->nombreAsignatures << ")" << endl;
    cout << "Edat del estudiant: " << this->getEdad() << endl;
};