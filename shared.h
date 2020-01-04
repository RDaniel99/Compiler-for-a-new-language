#pragma once

#include "StackMemory.h"

void SetIsInFunction(bool b);
bool GetIsInFunction();

void SetIsInClass(bool b);
bool GetIsInClass();

void SetCurrentClassName(char* name);
void GetCurrentClassName();

void SetCurrentFunctionName(char* fName);
char* GetCurrentFunctionName();

void SetMemory(StackMemory memory_);
StackMemory getMemory();

bool adaugaVar(variabila v);
bool adaugaFunc(functie f);

bool adaugaMem();
bool scoateMem();

