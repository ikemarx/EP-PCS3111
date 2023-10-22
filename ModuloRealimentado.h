#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Piloto.h"
#include "Somador.h"

class ModuloRealimentado {
protected:
    double ganho;
public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif