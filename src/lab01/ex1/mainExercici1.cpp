/*
 * Estructura de datos
 * Main File del ejercicio numero 1 - Laboratorio 1
 * @author: David de Jesus Blandon Torrez
 */

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string name;
    int option;
    string arr_options[] = {"Sortir", "Benvinguda"};
    cout << "Hola com et dius? ";
    cin >> name;
    do
    {
        cout << "Hola " << name << ", que vols fer ?" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << i + 1 << "." << arr_options[i] << endl;
        }
        cin >> option;
        if (option == 1)
        {
            cout << "Fins a la propera " << name << endl;
        }
        else
        {
            cout << "Benvinguda a l'asignatura d'estructures de dades " << name << endl;
        }

    } while (option != 1);

    return 0;
}
