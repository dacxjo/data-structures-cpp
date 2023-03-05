#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Estudiant.h"
#include "Professor.h"
using namespace std;

void add_person(int &comptadorEstudiants, int &comptadorProfessors, char choice)
{
    if (choice == 'e' || choice == 'E')
    {
        string nom;
        int anyNaixement, nombreAsignatures = 0;
        cout << "Estudiant " << comptadorEstudiants << endl;
        cout << "Nom?: ";
        cin >> nom;
        cout << "Any naixement?: ";
        cin >> anyNaixement;
        cout << "Asignatures: ";
        cin >> nombreAsignatures;
        Estudiant es = Estudiant(nom, anyNaixement, nombreAsignatures);
        comptadorEstudiants++;
        es.print();
    }
    else if (choice == 'p' || choice == 'P')
    {
        string nom;
        int anyNaixement = 0;
        cout << "Professor " << comptadorProfessors << endl;
        cout << "Nom?: ";
        cin >> nom;
        cout << "Any naixement?: ";
        cin >> anyNaixement;
        Professor p = Professor(nom, anyNaixement);
        comptadorProfessors++;
        p.print();
    }
};

void show_resume(int comptadorEstudiants, int comptadorProfessors)
{
    cout << "Estudiants creats: " << comptadorEstudiants << ", Professor creats: " << comptadorProfessors << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<string> options{"Sortir", "Afegir persona", "Resum persones"};
    int option;
    int comptadorEstudiants = 0, comptadorProfessors = 0;
    char choice;
    do
    {
        cout << "Hola, que vols fer?" << endl;
        for (int i = 0; i < options.size(); i++)
        {
            cout << i + 1 << "." << options[i] << endl;
        }
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Fins a la propera!" << endl;
            break;
        case 2:
            cout << "Prem 'E' per crear un estudiant o 'P' per crear un professor" << endl;
            cin >> choice;
            try
            {
                add_person(comptadorEstudiants, comptadorProfessors, choice);
            }
            catch (const invalid_argument &ex)
            {
                cerr << ex.what() << endl;
                cout << endl;
            };
            break;
        case 3:
            show_resume(comptadorEstudiants, comptadorProfessors);
            break;
        }
    } while (option != 1);

    return 0;
}
