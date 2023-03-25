#include <iostream>
#include <vector>
#include "PilaEstatica.h"
using namespace std;

void print_err(string err)
{
    cerr << "\033[1;31m"
         << "Error: " << err << "\033[0m"
         << endl;
}

void casProva1()
{
    PilaEstatica p(3);
    p.afegirElement(10);
    p.afegirElement(11);
    cout << "Front:" << p.elementFront() << endl;
    p.afegirElement(12);
    try
    {
        p.afegirElement(13);
    }
    catch (const out_of_range &ex)
    {
        print_err(ex.what());
    }
    p.imprimeix();
    cout << "Front:" << p.elementFront() << endl;
    p.treureElement();
    p.afegirElement(14);
    p.imprimeix();
    cout << "Front:" << p.elementFront() << endl;
    p.treureElement();
    p.treureElement();
    p.treureElement();
    try
    {
        p.treureElement();
    }
    catch (const out_of_range &ex)
    {
        print_err(ex.what());
    }
}
int main(int argc, char const *argv[])
{
    int option;
    vector<string> arr_options = {"Inserir element a la pila", "Treure element de la pila", "Consultar el top de la pila", "Imprimir tot el contingut de la PilaEstatica", "Imprimir la posició del top de la pila", "Sortir"};
    casProva1();
    cout << "============" << endl;
    PilaEstatica pilaMenu;
    do
    {
        for (int i = 0; i < arr_options.size(); i++)
        {
            cout << i + 1 << "." << arr_options[i] << endl;
        }

        try
        {
            cin >> option;
            switch (option)
            {
            case 1:
                int nouElement;
                cout << "Ingrese el element: " << endl;
                cin >> nouElement;
                pilaMenu.afegirElement(nouElement);
                break;
            case 2:
                pilaMenu.treureElement();
                break;
            case 3:
                if (pilaMenu.esBuida())
                {
                    throw out_of_range("EXCEPTION: L'estructura està buida");
                }
                cout << "Top: " << pilaMenu.elementFront() << endl;
                break;
            case 4:
                pilaMenu.imprimeix();
                break;
            case 5:
                if (pilaMenu.esBuida())
                {
                    throw out_of_range("EXCEPTION: L'estructura està buida");
                }
                cout << "Posicio del top: " << pilaMenu.tamany() - 1 << endl;
                break;
            }
        }
        catch (const out_of_range &ex)
        {
            print_err(ex.what());
        }

    } while (option != 6);

    return 0;
}
