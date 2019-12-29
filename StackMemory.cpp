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
    for(unsigned int i = stck.size() - 1; i >= 0; --i)
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
    for(unsigned int i = stck.size() - 1; i >= 0; --i)
        if(stck[i].Exista(v, poz))
        {
            rez = stck[i].variabile[poz];
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

bool StackMemory::PrintTable()
{
    ofstream fout("symbol_table.txt");

    for(unsigned int i = stck.size() - 1; i >= 0; i--)
    {
        fout << i << '\n';

        fout << stck[i].variabile.size() << '\n';

        for(auto x: stck[i].variabile)
            fout << x.tip << ' ' << x.nume << ' ' << x.valoare << '\n';

        fout << '\n' << '\n';

        fout << stck[i].functii.size() << '\n';

        for(auto x: stck[i].functii)
        {
            fout << x.returnType << ' ' << x.nume << ' ' << x.parametrii.size() << '\n';

            for(auto y: x.parametrii)
                fout << y.tip << ' ' << y.nume << ' ' << y.valoare << '\n';

            fout << '\n';
        }

        fout << '\n';
    }

    return true;
}
