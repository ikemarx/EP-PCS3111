#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Modulo.h"

class ModuloRealimentado : public Modulo {
protected:

public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();

    Sinal *processar(Sinal *sinalIN);
};

#endif