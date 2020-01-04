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

    return true;
}

bool Memory::Exista(functie f, int &pos)
{
    pos = -1;
    for(unsigned int i = 0; i < functii.size(); i++)
    {
        functie x;
        x.nume = functii[i].nume;
        x.parametrii = functii[i].parametrii;
        x.returnType = functii[i].returnType;

        if(x.nume == f.nume && x.returnType == f.returnType)
        {
            bool ok = x.parametrii.size() == f.parametrii.size();
            for(unsigned int j = 0; ok && j < x.parametrii.size(); j++)
                if(x.parametrii[j].tip != f.parametrii[j].tip ||
                    x.parametrii[j].nume != f.parametrii[j].nume)
                    ok = false;

            if(ok)
            {
                pos = i;
                return true;
            }
        }
    
    }
    return false;
}

bool Memory::Exista(variabila v, int &pos)
{
    pos = -1;

    for(unsigned int i = 0; i < variabile.size(); i++)
    {
        if(variabile[i].nume == v.nume)
        {
            pos = i;
            return true;
        }
    
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

    variabile[poz].nume = v.nume;
    variabile[poz].tip = v.tip;
    variabile[poz].valoare = v.valoare;

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