#pragma once

#include "StackMemory.h"

void SetIsInFunction(bool b);
bool GetIsInFunction();

void SetCurrentFunctionName(char* fName);
char* GetCurrentFunctionName();

void SetMemory(StackMemory memory_);
StackMemory getMemory();