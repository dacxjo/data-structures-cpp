/*
 * Estructura de datos
 * Definiciones de la clase "Client"
 * @author: David de Jesus Blandon Torrez
 */

#include <string.h>
#include <vector>
#include "Mascota.h"

class Client
{
private:
    std::string nom;
    std::string adreca;
    std::string poblacio;
    std::string telefon;
    std::string dni;
    int edat;
    std::vector<Mascota> mascotes;
    void checkMascotaNom(std::string);
    bool checkMascotaExists(std::string);

public:
    Client(std::string, std::string, std::string, std::string, std::string, int);
    std::string getAdreca();
    std::string getPoblacio();
    std::string getNom();
    std::string getTelefon();
    std::string getDNI();
    int getEdat();
    void print();
    void afegeixMascota(std::string, std::string, std::string, char, std::string, int);
    void eliminaMascota(std::string);
    void mostraMascotes();
};