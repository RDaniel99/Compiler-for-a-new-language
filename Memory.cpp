#include "Memory.h"

using namespace std;

Memory::Memory()
{
    variabile.clear();
    functii.clear();
}

bool Memory::Declarare(clasa c)
{
    int tmp;
    if(Exista(c, tmp))
        return false;

    clase.push_back(c);

    return true;
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
    for(int i = 0; i < functii.size(); i++)
    {
        functie x;
        x.nume = functii[i].nume;
        x.parametrii = functii[i].parametrii;
        x.returnType = functii[i].returnType;

        if(x.nume == f.nume && ((f.returnType.size() && x.returnType == f.returnType) || f.returnType.size() == 0))
        {
            bool ok = x.parametrii.size() == f.parametrii.size();
            for(unsigned int j = 0; ok && j < x.parametrii.size(); j++)
                if(x.parametrii[j].tip != f.parametrii[j].tip)
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

bool Memory::Exista(clasa c, int &pos)
{
    pos = -1;

    for(unsigned int i = 0; i < clase.size(); i++)
    {
        if(clase[i].nume == c.nume)
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

bool Memory::Scoate(clasa c)
{
    return true;
}

bool Memory::Modifica(variabila v)
{
    int poz;
    if(!Exista(v, poz))
        return false;

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

    for(auto x: clase)
    {
        fout << x.nume << '\n';

        for(auto f: x.functii)
        {
            fout << f.returnType << ' ' << f.nume << ' ' << f.parametrii.size() << '\n';

            for(auto p: f.parametrii)
                fout << p.tip << ' ' << p.nume << ' ' << p.valoare << '\n';

            fout << '\n';
        }
    }

    return true;
}