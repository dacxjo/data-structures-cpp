#include <string>
class Estudiant
{
private:
    std::string nom;
    int any;
    int nombreAsignatures;

public:
    Estudiant();
    Estudiant(std::string nom, int anyNaixement, int numAssignatures);
    int getEdad();
    void print();
};