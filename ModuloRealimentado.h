#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Piloto.h"

class ModuloRealimentado {
private:
    Piloto piloto;
    Sinal* sinalIN;
    Sinal* diferenca;
    Sinal* saida;
    Sinal* saidaInvertida;
    int vInicial = 0;

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif