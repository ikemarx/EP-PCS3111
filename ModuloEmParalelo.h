#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include "Somador.h"

class ModuloEmParalelo : public Modulo
{
private:
    
public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();

    Sinal* processar(Sinal* sinalIN);
};

#endif