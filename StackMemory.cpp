#include "StackMemory.h"
#include <cstring>

using namespace std;

StackMemory::StackMemory()
{
    stck.clear();
}

bool StackMemory::Exista(functie f, functie& rez)
{
    int tmp;
    for(int i = stck.size() - 1; i >= 0; --i)
        if(stck[i].Exista(f, tmp))
        {
            rez = f;
            return true;
        }

    return false;
}

bool StackMemory::Exista(variabila v, variabila& rez)
{
    int poz;
    for(int i = stck.size() - 1; i >= 0; --i)
        if(stck[i].Exista(v, poz))
        {
            rez = stck[i].variabile[poz];
            return true;
        }

    return false;
}

bool StackMemory::Exista(clasa c, clasa& rez)
{
    int poz;
    for(int i = stck.size() - 1; i >= 0; --i)
        if(stck[i].Exista(c, poz))
        {
            rez = stck[i].clase[poz];
            return true;
        }

    return false;
}

bool StackMemory::AdaugaMemorie()
{
    Memory nou;
    stck.push_back(nou);

    return true;
}

bool StackMemory::EliminaMemorie()
{
    stck.pop_back();

    return true;
}

bool StackMemory::AdaugaVariabila(variabila v)
{
    if(stck.size() == 0)
        return false;

    return stck[stck.size() - 1].Declarare(v);
}

bool StackMemory::AdaugaFunctie(functie f)
{
    if(stck.size() == 0)
        return false;

    return stck[stck.size() - 1].Declarare(f);
}

bool StackMemory::AdaugaClasa(clasa c)
{
    if(stck.size() == 0)
        return false;

    return stck[stck.size() - 1].Declarare(c);
}

bool StackMemory::Modifica(variabila& v)
{
    for(int i = stck.size() - 1; i >= 0; --i)
    {
        int tmp = -1;
        if(stck[i].Exista(v, tmp))
        {
            stck[i].variabile[tmp] = v;
            return true;
        }
    }

    return false;
}

bool StackMemory::PrintTable()
{
    ofstream fout("symbol_table.txt");

    for(int i = stck.size() - 1; i >= 0; i--)
    {
        fout << "Memoria numaru' " << i << '\n';

        stck[i].PrintTable(fout);

        fout << '\n' << '\n';
    }

    fout.close();

    return true;
}
