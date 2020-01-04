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

        fout << "Total variabile: " << stck[i].variabile.size() << '\n';

        for(auto x: stck[i].variabile)
            fout << "--Tip variabila: " << x.tip << " , nume variabila: " << x.nume << " valoare variabila: " << x.valoare << '\n';

        fout << '\n' << '\n';

        fout << "Total functii: " << stck[i].functii.size() << '\n';

        for(auto x: stck[i].functii)
        {
            fout << "--ReturnType: " << x.returnType << " , Nume fct: " << x.nume << " , total params: " << x.parametrii.size() << '\n';

            for(auto y: x.parametrii)
                fout << "----tip param: " << y.tip << " nume param: " << y.nume << " valoare param: " << y.valoare << '\n';

            fout << '\n';
        }

        fout << '\n' << '\n';

        fout << "Total clase: " << stck[i].clase.size() << '\n';

        for(auto x: stck[i].clase)
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
    }

    fout.close();

    return true;
}
