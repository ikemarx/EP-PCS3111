#ifndef MODULO_H
#define MODULO_H
#include "CircuitoSISO.h"

class Modulo : public CircuitoSISO
{
private:
    
public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
};

#endif