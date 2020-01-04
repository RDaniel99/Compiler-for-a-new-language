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