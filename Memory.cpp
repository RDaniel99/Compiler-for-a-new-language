#include "Memory.h"

using namespace std;

bool Memory::Declarare(functie f)
{
    if(Exista(f))
        return false;

    functii.push_back(f);

    return true;
}

bool Memory::Declarare(variabila v)
{
    if(Exista(v))
        return false;

    variabile.push_back(v);
}

bool Memory::Exista(functie f)
{
    if(std::find(functii.begin(), functii.end(), f) != functii.end())
        return true;
    
    return false;
}

bool Memory::Exista(variabila v)
{
    for(auto x: variabile)
        if(x.nume == v.nume)
            return true;
    
    return false;
}

bool Memory::Scoate(functie f)
{
    return true;
}

bool Memory::Scoate(variabila v)
{
    return true;
}

bool Memory::Modifica(variabila v)
{
    if(!Exista(v))
        return false;

    for(auto x: variabile)
        if(x.nume == v.nume)
        {
            x = v;
            return true;
        }

    return false;
}