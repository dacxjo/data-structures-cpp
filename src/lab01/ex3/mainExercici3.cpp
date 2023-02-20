#include <iostream>
#include <vector>
#include <string>
#include "Estudiant.h"
using namespace std;
void get_info(int &comptador)
{
    comptador++;
    string nom;
    int anyNaixement, nombreAsignatures = 0;
    cout << "Estudiant " << comptador << endl;
    cout << "Nom?: ";
    cin >> nom;
    cout << "Any naixement?: ";
    cin >> anyNaixement;
    cout << "Asignatures: ";
    cin >> nombreAsignatures;
    Estudiant es = Estudiant(nom, anyNaixement, nombreAsignatures);
    es.print();
};
int main(int argc, char const *argv[])
{
    vector<string> options{"Sortir", "Informar Estudiant"};
    int option;
    int comptador = 0;
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
            get_info(comptador);
            break;
        }
    } while (option != 1);

    return 0;
}
