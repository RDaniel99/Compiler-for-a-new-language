#include "shared.h"

StackMemory memory;
bool        isInFunction;
char*       currentFunctionName;

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