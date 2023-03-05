/*
 * Estructura de datos
 * Definiciones de la clase  "Estudiant"
 * @author: David de Jesus Blandon Torrez
 */

#include <string>
class Estudiant
{
private:
    std::string nom;
    int any;
    int nombreAsignatures;
    int anyActual;

public:
    Estudiant();
    Estudiant(std::string nom, int anyNaixement, int numAssignatures);
    int getEdad();
    void print();
};