#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H

#include "Sinal.h"
#include "Circuito.h"

class CircuitoMISO : public Circuito
{
private:
    
public:
    CircuitoMISO();
    virtual ~CircuitoMISO();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};

#endif