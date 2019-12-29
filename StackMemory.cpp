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
