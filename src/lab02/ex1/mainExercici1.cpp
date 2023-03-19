#include <iostream>
#include <vector>
#include "PilaEstatica.h"
using namespace std;

void print_err(string err)
{
    cerr << "\033[1;31m"
         << "Error: " << err << "\033[0m\n"
         << endl;
}
int main(int argc, char const *argv[])
{
    int option;
    vector<string> arr_options = {"Inserir element a la pila", "Treure element de la pila", "Consultar el top de la pila", "Imprimir tot el contingut de la PilaEstatica", "Imprimir la posició del top de la pila", "Sortir"};
    PilaEstatica pila(10);
    PilaEstatica pila2 = pila;
    PilaEstatica pila3({2, 3, 1, 23, 32});
    try
    {
        pila.afegirElement(5);
        pila.afegirElement(1);
        pila.afegirElement(3);
        pila.imprimeix();
        pila.treureElement();
        cout << "----" << endl;
        pila.imprimeix();
        pila.afegirElement(112);
        cout << "----" << endl;
        pila.imprimeix();
    }
    catch (const out_of_range &ex)
    {
        print_err(ex.what());
    }

    /* do
    {
        for (int i = 0; i < arr_options.size(); i++)
        {
            cout << i + 1 << "." << arr_options[i] << endl;
        }
        cin >> option;

    } while (option != 6); */
    return 0;
}
