#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Piloto.h"
#include "Somador.h"

class ModuloRealimentado {
private:
    Amplificador* inversor;
    Somador* somador;
    Piloto* piloto;
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;
    int vInicial = 0;
    double* sequenciaSaidaInvertida;
public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif