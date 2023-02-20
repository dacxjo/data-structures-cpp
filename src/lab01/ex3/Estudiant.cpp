#include <iostream>
#include "Estudiant.h"
using namespace std;

Estudiant::Estudiant() {}
Estudiant::Estudiant(string nom, int anyNaixement, int numAssignatures)
{
    this->nom = nom;
    this->any = anyNaixement;
    this->nombreAsignatures = numAssignatures;
}
int Estudiant::getEdad()
{
    return 2023 - this->any;
}
void Estudiant::print()
{
    cout << "Estudiant(Nom ==> " << this->nom << ", Naixement ==> " << this->any << ", Assignatures ==> " << this->nombreAsignatures << ")" << endl;
    cout << "Edat del estudiant: " << this->getEdad() << endl;
};