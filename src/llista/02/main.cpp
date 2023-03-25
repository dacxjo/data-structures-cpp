#include <iostream>
using namespace std;

float toPounds(float kg)
{
    return kg * 2.2;
}

int main()
{
    float weight, pounds;
    cout << "Ingresa tu peso en KG: " << endl;
    cin >> weight;
    cout << "Tu peso en libras es: " << toPounds(weight) << endl;
    return 0;
}
