#include <iostream>
#include "NodeLlista.h"
#include "Posicio.h"
#include "Llista.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Llista<string> list;
    int numParaules;
    cout << "Introdueix quantes paraules vols inserir: ";
    cin >> numParaules;
    for (int i = 0; i < numParaules; i++)
    {
        string paraula;
        char inserirPrincipi, inserirFinal, inserirAbansPosicio;
        int posicio;
        cout << "Introdueix una paraula: ";
        cin >> paraula;
        cout << "Inserir al principi? (s/n) ";
        cin >> inserirPrincipi;
        if (inserirPrincipi == 's')
        {
            list.inserirPrincipi(paraula);
        }
        else
        {
            cout << "Inserir al final? (s/n) ";
            cin >> inserirFinal;
            if (inserirFinal == 's')
            {
                list.inserirFinal(paraula);
            }
            else
            {
                cout << "A quina posició vols inserir? ";
                cin >> posicio;
                Posicio<string> pos(nullptr);
                // No pude  hacer esta parte
                for (int i = 0; i < posicio; i++)
                {
                    if (i == 0)
                    {
                        pos = list.principi();
                        break;
                    }
                    pos = list.principi().operator++();
                }
                cout << "Inserir abans de la posició? (s/n) ";
                cin >> inserirAbansPosicio;
                if (inserirAbansPosicio == 's')
                {
                    list.inserirAbans(pos, paraula);
                }
                else
                {
                    list.inserirDespres(pos, paraula);
                }
            }
        }
    }
    cout << "Iteració (amb position) endavant: " << endl;
    list.printEndavant();
    cout << "Iteració (amb position) endarrere: " << endl;
    list.printEndarrere();
    return 0;
}
