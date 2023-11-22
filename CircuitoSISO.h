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
    virtual Sinal* processar(Sinal* sinalIN) = 0; // abstrato
};

#endif