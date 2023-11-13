#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Sinal.h"

class CircuitoSISO
{
private:
    
public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    Sinal* processar(Sinal* sinalIN); // abstrato
};

#endif