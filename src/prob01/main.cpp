#include <iostream>
#include "Rectangle.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int width, height;
    cout << "Calcular el area de un rectangulo" << endl;
    cout << "Ancho: ";
    cin >> width;
    cout << "Alto: ";
    cin >> height;
    Rectangle rec(width,height);
    cout  << "El area del rectangulo es: " << rec.area() << endl;
    return 0;
}
