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

char* GetCurrentClassName()
{
    return currentClassName;
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

bool adaugaClasa(clasa c)
{
    return memory.AdaugaClasa(c);
}

bool adaugaMem()
{
    return memory.AdaugaMemorie();
}

bool scoateMem()
{
    return memory.EliminaMemorie();
}

bool existaClasa(clasa& c)
{
    clasa rez;
    bool ok = memory.Exista(c, rez);

    if(ok)
        c = rez;
    
    return ok;
}

bool existaVar(variabila& v)
{
    variabila rez;
    bool ok = memory.Exista(v, rez);

    if(ok)
        v = rez;
    
    return ok;
}

bool existaFunc(functie& f)
{
    functie rez;
    bool ok = memory.Exista(f, rez);

    if(ok)
        f = rez;
    
    return ok;
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

bool checkParams(functie &f, std::string params)
{
    variabila p;
    p.nume = "";
    params += ',';
    for(int i = 0; i < params.size(); i++)
    {
        if(params[i] == ',')
        {
            if(existaVar(p))
            {   
                f.parametrii.push_back(p);
            }
            else
            {
                return false;
            }

            p.nume = "";   
        }
        else
        {
            p.nume += params[i];
        }
        
    }

    return true;
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

bool modifica(variabila& v)
{
    memory.Modifica(v);
}

bool appendToClass(clasa c, variabila v)
{
    for(int i = memory.stck.size() - 1; i >= 0; --i)
    {
        int poz = -1;
        if(memory.stck[i].Exista(c, poz))
        {
            memory.stck[i].clase[poz].membrii.push_back(v);
            return true;
        }
    }

    return false;
}