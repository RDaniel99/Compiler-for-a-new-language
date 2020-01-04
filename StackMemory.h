#ifndef H_STACKMEMORY
#define H_STACKMEMORY

#include "Memory.h"

class StackMemory {
public:
    StackMemory();

    bool Exista(variabila v, variabila& rez);
    bool Exista(functie f, functie& rez);

    bool AdaugaMemorie();
    bool EliminaMemorie();

    bool AdaugaVariabila(variabila v);
    bool AdaugaFunctie(functie f);

    bool PrintTable();

    std::vector<Memory> stck;
};

#endif //H_STACKMEMORY