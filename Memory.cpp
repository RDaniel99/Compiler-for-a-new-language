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
            bool ok = (x.parametrii.size() == f.parametrii.size());
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

bool Memory::PrintTable(ofstream& fout)
{
    fout << "Total variabile: " << variabile.size() << '\n';
    for(auto x: variabile)
        fout << "--Tip variabila: " << x.tip << " , nume variabila: " << x.nume << " valoare variabila: " << x.valoare << '\n';
    fout << '\n' << '\n';
    fout << "Total functii: " << functii.size() << '\n';
    for(auto x: functii)
    {
        fout << "--ReturnType: " << x.returnType << " , Nume fct: " << x.nume << " , total params: " << x.parametrii.size() << '\n';
        for(auto y: x.parametrii)
            fout << "----tip param: " << y.tip << " nume param: " << y.nume << " valoare param: " << y.valoare << '\n';
        fout << '\n';
    }
    fout << '\n' << '\n';
    fout << "Total clase: " << clase.size() << '\n';
    for(auto x: clase)
    {
        fout << "--Nume clasa: " << x.nume << " total membrii: " << x.membrii.size() << " total fct: " << x.functii.size() << '\n';
        for(auto y: x.membrii)
            fout << "----tip membru: " << y.tip << " nume membru: " << y.nume << " valoare membru: " << y.valoare << '\n';
        for(auto y: x.functii)
        {
            fout << "----ReturnType: " << y.returnType << " , Nume fct: " << y.nume << " , total params: " << y.parametrii.size() << '\n';
            for(auto z: y.parametrii)
                fout << "------tip param: " << z.tip << " nume param: " << z.nume << " valoare param: " << z.valoare << '\n';
        }
    }

    return true;
}