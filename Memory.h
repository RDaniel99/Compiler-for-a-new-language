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

struct clasa
{
    std::string nume;
    std::vector<variabila> membrii;
    std::vector<functie> functii;
};

class Memory
{
public:
    Memory();

    bool Declarare(functie f);
    bool Declarare(variabila v);
    bool Declarare(clasa c);

    bool Exista(functie f, int &pos);
    bool Exista(variabila v, int &pos);
    bool Exista(clasa c, int &pos);

    bool Scoate(functie f);
    bool Scoate(variabila v);
    bool Scoate(clasa c);

    bool Modifica(variabila v);

    bool PrintTable();
    
    std::vector<variabila>  variabile;
    std::vector<functie>    functii; 
    std::vector<clasa>      clase;
};