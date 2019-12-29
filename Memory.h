#include <vector>
#include <string>
#include <algorithm>

struct variabila
{
    std::string tip;
    std::string nume;
    std::string valoare;
};

struct functie
{
    std::string returnType;
    std::string nume;
    std::vector<variabila> parametrii;
};

class Memory
{
public:
    bool Declarare(functie f);
    bool Declarare(variabila v);

    bool Exista(functie f);
    bool Exista(variabila v);

    bool Scoate(functie f);
    bool Scoate(variabila v);

    bool Modifica(variabila v);
    
    std::vector<variabila>  variabile;
    std::vector<functie>    functii; 
};