#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>

struct variabila
{
    std::string tip;
    std::string nume;
    std::string valoare;
};

class Memory;

struct functie
{
    std::string returnType;
    std::string nume;
    std::vector<variabila> parametrii;

    Memory* memorieFunctie;
};

class Memory
{
public:
    Memory();

    bool Declarare(functie f);
    bool Declarare(variabila v);

    bool Exista(functie f, int &pos);
    bool Exista(variabila v, int &pos);

    bool Scoate(functie f);
    bool Scoate(variabila v);

    bool Modifica(variabila v);

    bool PrintTable();
    
    std::vector<variabila>  variabile;
    std::vector<functie>    functii; 
};