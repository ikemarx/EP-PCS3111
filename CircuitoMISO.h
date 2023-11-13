#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H

#include "Sinal.h"

class CircuitoMISO
{
private:
    
public:
    CircuitoMISO();
    virtual ~CircuitoMISO();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};

#endif