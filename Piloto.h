#ifndef PILOTO_H
#define PILOTO_H
#include "Amplificador.h"
#include "Integrador.h"

class Piloto {
protected:
    Amplificador* amplificador;
    Integrador* integrador;
    double ganho;
public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);
};

#endif