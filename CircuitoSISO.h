#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Sinal.h"
#include "Circuito.h"

class CircuitoSISO : public Circuito
{
private:
    
public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    Sinal* processar(Sinal* sinalIN); // abstrato
};

#endif