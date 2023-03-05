/*
 * Estructura de datos
 * Main File del ejercicio numero 6 - Laboratorio 1
 * @author: David de Jesus Blandon Torrez
 */
#include <iostream>
#include <stdexcept>
#include "Client.h"

using namespace std;

bool clientExist(string dni, vector<Client> &clients)
{
    for (Client client : clients)
    {
        if (client.getDNI() == dni)
        {
            return true;
        }
    }
    return false;
}
void addPetToClient(Client &c)
{
    string nom, tipus, raca, color;
    char genere;
    int edad;
    cout << "Nom mascota?: ";
    cin >> nom;
    cout << "Tipus?: ";
    cin >> tipus;
    cout << "Raça?: ";
    cin >> raca;
    cout << "Genere?: ";
    cin >> genere;
    cout << "Color?: ";
    cin >> color;
    cout << "Edat?: ";
    cin >> edad;
    c.afegeixMascota(nom, tipus, raca, genere, color, edad);
    cout << "Mascota agregada!" << endl;
}
void addPetToClientByMenu(string dni, vector<Client> &clients)
{
    if (clients.size() == 0)
    {
        cout << "0 clients registrats" << endl;
    }
    else if (!clientExist(dni, clients))
    {
        cout << "El client no existeix" << endl;
    }
    else
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getDNI() == dni)
            {
                addPetToClient(clients[i]);
            }
        }
    }
    cout << endl;
}
void removeClientPet(string dni, string nom, vector<Client> &clients)
{
    if (clients.size() == 0)
    {
        cout << "0 clients registrats" << endl;
    }
    else if (!clientExist(dni, clients))
    {
        cout << "El client no existeix" << endl;
    }
    else
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getDNI() == dni)
            {
                clients[i].eliminaMascota(nom);
            }
        }
    }
    cout << endl;
}
void addClient(vector<Client> &clients)
{
    string nom, adreca, poblacio, telefon, dni;
    int edat;
    cout << "Nom?: ";
    cin >> nom;
    cout << "Adreça?: ";
    cin >> adreca;
    cout << "Poblacio?: ";
    cin >> poblacio;
    cout << "Telefon?: ";
    cin >> telefon;
    cout << "DNI?: ";
    cin >> dni;
    cout << "Edat?: ";
    cin >> edat;
    try
    {
        if (clientExist(dni, clients))
        {
            throw invalid_argument("Client already registered");
        }
        else
        {
            Client c(nom, adreca, poblacio, telefon, dni, edat);
            int afegirMascota;
            cout << "Vols afegir una mascota al client?: " << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cin >> afegirMascota;
            if (afegirMascota == 1)
            {
                addPetToClient(c);
            }
            clients.push_back(c);
            cout << "Client afegit! " << endl;
        }
    }
    catch (const invalid_argument &ex)
    {
        cerr << ex.what() << endl;
    }
    cout << endl;
}
void listClients(vector<Client> &clients)
{
    if (clients.size() == 0)
    {
        cout << "0 clients registrats" << endl;
    }
    else
    {
        for (Client client : clients)
        {
            client.print();
        }
    }
    cout << endl;
}
void listClientPets(string dni, vector<Client> &clients)
{
    if (clients.size() == 0)
    {
        cout << "0 clients registrats" << endl;
    }
    else if (!clientExist(dni, clients))
    {
        cout << "El client no existeix" << endl;
    }
    else
    {
        for (Client client : clients)
        {
            if (client.getDNI() == dni)
            {
                client.mostraMascotes();
            }
        }
    }
    cout << endl;
}
void removeClient(string dni, vector<Client> &clients)
{
    if (clients.size() == 0)
    {
        cout << "0 clients registrats" << endl;
    }
    else if (!clientExist(dni, clients))
    {
        cout << "El client no existeix" << endl;
    }
    else
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getDNI() == dni)
            {
                clients.erase(clients.begin() + i);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<string> options{"Afegir client", "Eliminar client", "Afegir mascota a un client", "Eliminar mascota d'un client", "Imprimir clients clinica", "Imprimir les mascotes d'un client"};
    vector<Client> clients;
    int option;
    string dni, nomMascota;
    cout << "Benvingut a la clinica" << endl;
    do
    {
        for (int i = 0; i < options.size(); i++)
        {
            cout << i + 1 << "." << options[i] << endl;
        }
        cout << 0 << "."
             << "Sortir" << endl;
        cout << endl;
        cout << "Que vols fer?: ";
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "Fins a la propera!" << endl;
            break;
        case 1:
            addClient(clients);
            break;
        case 2:
            cout << "Ingresa el DNI del client: " << endl;
            cin >> dni;
            removeClient(dni, clients);
            break;
        case 3:
            cout << "Ingresa el DNI del client: " << endl;
            cin >> dni;
            addPetToClientByMenu(dni, clients);
            break;
        case 4:
            cout << "Ingresa el DNI del client: " << endl;
            cin >> dni;
            cout << "Ingresa el nom de la mascota: " << endl;
            cin >> nomMascota;
            removeClientPet(dni, nomMascota, clients);
            break;
        case 5:
            listClients(clients);
            break;
        case 6:
            cout << "Ingresa el DNI del client: " << endl;
            cin >> dni;
            listClientPets(dni, clients);
            break;
        }
    } while (option != 0);
    return 0;
}
