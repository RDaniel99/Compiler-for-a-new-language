#include "shared.h"

StackMemory memory;
bool        isInFunction;
bool        isInClass;
char*       currentFunctionName;
char*       currentClassName;
void SetIsInFunction(bool b)
{
    isInFunction = b;
}

bool GetIsInFunction()
{
    return isInFunction;
}

void SetCurrentFunctionName(char* fName)
{
    if(fName==nullptr)
        currentFunctionName=nullptr;
    else
        currentFunctionName=strdup(fName);
}

char* GetCurrentFunctionName()
{
    return currentFunctionName;
}

void SetMemory(StackMemory memory_)
{
    memory=memory_;
}
StackMemory getMemory()
{
    return memory;
}

bool adaugaVar(variabila v)
{
    return memory.AdaugaVariabila(v);
}

bool adaugaFunc(functie f)
{
    return memory.AdaugaFunctie(f);
}

bool adaugaMem()
{
    return memory.AdaugaMemorie();
}

bool scoateMem()
{
    return memory.EliminaMemorie();
}
void SetCurrentClassName(char* name)
{
    if(name==nullptr)
        currentClassName=0;
    else
        currentClassName=strdup(name);
}
void SetIsInClass(bool b)
{
    isInClass=b;
}
bool GetIsInClass()
{
    return isInClass;
}
bool adaugaParams(functie &f, std::string params)
{
    variabila p;
    p.nume = "";
    p.tip = "";
    p.valoare = "";
    int ord = 0;
    params += ',';
    for(int i = 0; i < params.size(); i++)
    {
        if(params[i] == ':')
        {
            ord = 1;
            continue;
        }

        if(params[i] == ',')
        {
            ord = 0;
            f.parametrii.push_back(p);
            p.nume = "";
            p.tip = "";
            continue;
        }

        if(ord == 0)
        {
            p.nume += params[i];
        }
        else
        {
            p.tip += params[i];
        }
    }

    return true;
}