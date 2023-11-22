#ifndef MODULO_H
#define MODULO_H
#include "CircuitoSISO.h"
#include<list>

class Modulo : public CircuitoSISO
{
protected:
    list<CircuitoSISO*>* circuitos;
public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();

    void imprimir();
};

#endif