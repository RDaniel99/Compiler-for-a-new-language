#include "Memory.h"

class StackMemory {
public:
    StackMemory();

    bool Exista(variabila v, variabila& rez);
    bool Exista(functie f, functie& rez);

    bool AdaugaMemorie();
    bool EliminaMemorie();

    std::vector<Memory> stck;
};