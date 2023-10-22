#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Piloto.h"
#include "Somador.h"

class ModuloRealimentado {
protected:
    Amplificador* inversor;
    Somador* somador;
    Piloto* piloto;
    Sinal* diferenca;
    Sinal* saida;
    Sinal* saidaInvertida;
    int vInicial;
    double* sequenciaSaidaInvertida;
    double ganho;
public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif