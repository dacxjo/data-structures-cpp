/*
 * Estructura de datos
 * Main File del ejercicio numero 2 - Laboratorio 1
 * @author: David de Jesus Blandon Torrez
 */

#include <iostream>
#include <vector>
using namespace std;

void show_menu(int &option, vector<string> options)
{
    for (int i = 0; i < options.size(); i++)
    {
        cout << i + 1 << "." << options[i] << endl;
    }
    cin >> option;
}
void get_name(string &name)
{
    cout << "Hola com et dius? ";
    cin >> name;
}
int main(int argc, char const *argv[])
{
    string name;
    int option;
    vector<string> arr_options{"Sortir", "Benvinguda", "Redefinir nom"};
    get_name(name);
    do
    {
        cout << "Hola " << name << ", que vols fer ?" << endl;
        show_menu(option, arr_options);
        switch (option)
        {
        case 1:
            cout << "Fins a la propera " << name << endl;
            break;
        case 2:
            cout << "Benvinguda a l'asignatura d'estructures de dades " << name << endl;
            break;
        case 3:
            get_name(name);
            break;
        }

    } while (option != 1);

    return 0;
}
