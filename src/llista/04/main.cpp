#include <iostream>
using namespace std;

int main()
{
    int base = 40000, antiguedad, total = 0;

    cout << "Ingrese la antiguedad: " << endl;
    cin >> antiguedad;
    if (antiguedad >= 10)
    {
        total = base + (base * 0.1);
    }
    else if (antiguedad > 5 && antiguedad < 10)
    {
        total = base + (base * 0.07);
    }
    else if (antiguedad > 3 && antiguedad < 5)
    {
        total = base + (base * 0.05);
    }
    else
    {
        total = base + (base * 0.03);
    }

    cout << "El salario total es de: " << total << endl;

    return 0;
}
