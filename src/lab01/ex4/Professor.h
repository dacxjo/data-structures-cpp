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