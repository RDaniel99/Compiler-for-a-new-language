#pragma once

#include "StackMemory.h"
#include <string>

void SetIsInFunction(bool b);
bool GetIsInFunction();

void SetIsInClass(bool b);
bool GetIsInClass();

void SetCurrentClassName(char* name);
char* GetCurrentClassName();

void SetCurrentFunctionName(char* fName);
char* GetCurrentFunctionName();

void SetMemory(StackMemory memory_);
StackMemory getMemory();

bool adaugaVar(variabila v);
bool adaugaFunc(functie f);
bool adaugaClasa(clasa c);
bool appendToClass(clasa c, variabila v);
bool existaClasa(clasa& c);
bool existaVar(variabila& v);
bool existaFunc(functie& f);

bool modifica(variabila& v);
bool printTable();

bool adaugaMem();
bool scoateMem();
bool adaugaParams(functie &f, std::string params);
bool checkParams(functie &f, std::string params);
