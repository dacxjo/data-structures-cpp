/*
 * Estructura de datos
 * Definición de la clase "Mascota"
 * @author: David de Jesus Blandon Torrez
 */

#include <string>

class Mascota
{
private:
    std::string nom;
    std::string tipus;
    std::string raca;
    char genere;
    std::string color;
    int edad;

public:
    Mascota(std::string nom, std::string tipus, std::string raca, char genere, std::string color, int edad);
    std::string getNom();
    std::string getTipus();
    std::string getRaca();
    char getGenere();
    std::string getColor();
    int getEdad();
    void print();
};