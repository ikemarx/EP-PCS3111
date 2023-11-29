#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Modulo.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Piloto.h"

class ModuloRealimentado : public Modulo {
protected:
    Amplificador* inversor;
    Somador* somador;
    Piloto* piloto;
public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();

    Sinal *processar(Sinal *sinalIN);
};

#endif