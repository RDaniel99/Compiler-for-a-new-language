#include "Memory.h"

using namespace std;

Memory::Memory()
{
    variabile.clear();
    functii.clear();
}

bool Memory::Declarare(functie f)
{
    int tmp;
    if(Exista(f, tmp))
        return false;

    functii.push_back(f);

    return true;
}

bool Memory::Declarare(variabila v)
{
    int tmp;
    if(Exista(v, tmp))
        return false;

    variabile.push_back(v);
}

bool Memory::Exista(functie f, int &pos)
{
    if(std::find(functii.begin(), functii.end(), f) != functii.end())
        return true;
    
    return false;
}

bool Memory::Exista(variabila v, int &pos)
{
    for(auto x: variabile)
        if(x.nume == v.nume)
        {
            v = x;
            return true;
        }
    
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
    int poz;
    if(!Exista(v, poz))
        return false;

    variabile[poz] = v;

    return false;
}

bool Memory::PrintTable()
{
    ofstream fout("symbol_table.txt");

    fout << variabile.size() << '\n';

    for(auto x: variabile)
        fout << x.tip << ' ' << x.nume << ' ' << x.valoare << '\n';

    fout << '\n' << '\n';

    fout << functii.size() << '\n';

    for(auto x: functii)
    {
        fout << x.returnType << ' ' << x.nume << ' ' << x.parametrii.size() << '\n';

        for(auto y: x.parametrii)
            fout << y.tip << ' ' << y.nume << ' ' << y.valoare << '\n';

        fout << '\n';
    }

    return true;
}