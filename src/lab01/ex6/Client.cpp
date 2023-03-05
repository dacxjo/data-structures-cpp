/*
 * Estructura de datos
 * Implementación de la clase "Client"
 * Agregue un metodo mas "checkMascotaExist" para comprobar
 * si una mascota existe en el registro del cliente o no.
 * @author: David de Jesus Blandon Torrez
 */

#include <iostream>
#include <stdexcept>
#include "Client.h"
using namespace std;

Client::Client(string nom, string adreca, string poblacio, string telefon, string dni, int edad)
{
    this->nom = nom;
    this->adreca = adreca;
    this->poblacio = poblacio;
    this->telefon = telefon;
    this->dni = dni;
    this->edat = edad;
}
string Client::getAdreca()
{
    return this->adreca;
}
string Client::getPoblacio()
{
    return this->poblacio;
}
string Client::getNom()
{
    return this->nom;
}
string Client::getTelefon()
{
    return this->telefon;
}
string Client::getDNI()
{
    return this->dni;
}
int Client::getEdat()
{
    return this->edat;
}
void Client::print()
{
    cout << "Client(Nom ==> " << this->nom << ", Adreça ==> " << this->adreca << ", Poblacio ==> " << this->poblacio << ", Telefon ==> " << this->telefon << ", DNI ==> " << this->dni << ", Edad ==> " << this->edat << ")" << endl;
}
void Client::checkMascotaNom(string nom)
{
    for (Mascota mascota : this->mascotes)
    {
        if (mascota.getNom() == nom)
        {
            throw invalid_argument("Nom already defined");
        }
    }
}
void Client::afegeixMascota(string nom, string tipus, string raca, char genere, string color, int edat)
{
    try
    {
        this->checkMascotaNom(nom);
        Mascota m(nom, tipus, raca, genere, color, edat);
        this->mascotes.push_back(m);
    }
    catch (const invalid_argument &ex)
    {
        cerr << ex.what() << endl;
    }
}
bool Client::checkMascotaExists(string nom)
{
    for (int i = 0; i < this->mascotes.size(); i++)
    {
        if (this->mascotes[i].getNom() == nom)
        {
            return true;
        }
    }
    return false;
}
void Client::eliminaMascota(string nom)
{
    if (this->mascotes.size() == 0)
    {
        cout << "No hi ha mascotes" << endl;
    }
    else if (!this->checkMascotaExists(nom))
    {
        cout << "La mascota no esta registrada" << endl;
    }
    else
    {
        for (int i = 0; i < this->mascotes.size(); i++)
        {
            if (this->mascotes[i].getNom() == nom)
            {
                this->mascotes.erase(this->mascotes.begin() + i);
                cout << "Registro de mascota eliminado" << endl;
            }
        }
    }
};
void Client::mostraMascotes()
{
    if (this->mascotes.size() == 0)
    {
        cout << "Aquest client no té mascotes" << endl;
    }
    else
    {
        for (Mascota mascota : this->mascotes)
        {
            mascota.print();
        }
    }
};