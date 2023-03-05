/*
 * Estructura de datos
 * Definiciones de la clase  "Professor"
 * @author: David de Jesus Blandon Torrez
 */

#include <string>
class Professor
{
private:
    std::string nom;
    int anyNaixement;
    int anyActual;

public:
    Professor();
    Professor(std::string nom, int anyNaixement);
    int getEdad();
    void print();
};