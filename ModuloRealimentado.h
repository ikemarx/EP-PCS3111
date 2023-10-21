#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Piloto.h"

class ModuloRealimentado {
private:
    Piloto piloto;
    Sinal* sinalIN = nullptr;
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;
    int vInicial = 0;

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif