/*
 * Estructura de datos
 * Implementación de la clase "Mascota"
 * @author: David de Jesus Blandon Torrez
 */

#include <iostream>
#include "Mascota.h"
using namespace std;

Mascota::Mascota(string nom, string tipus, string raca, char genere, string color, int edad)
{
    this->nom = nom;
    this->tipus = tipus;
    this->raca = raca;
    this->genere = genere;
    this->color = color;
    this->edad = edad;
}

string Mascota::getNom()
{
    return this->nom;
}

string Mascota::getTipus()
{
    return this->tipus;
}

string Mascota::getRaca()
{
    return this->raca;
}

char Mascota::getGenere()
{
    return this->genere;
}

string Mascota::getColor()
{
    return this->color;
}

int Mascota::getEdad()
{
    return this->edad;
}

void Mascota::print()
{
    cout << "Mascota(Nom ==> " << this->nom << ", Tipus ==> " << this->tipus << ", Raça ==> " << this->raca << ", Genere ==> " << this->genere << ", Color ==> " << this->color << ", Edad ==> " << this->edad << ")" << endl;
}