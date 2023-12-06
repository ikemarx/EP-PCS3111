#include "Modulo.h"

Modulo::Modulo() : circuitos(new list<CircuitoSISO*>) {}

Modulo::~Modulo()
{
    delete circuitos;
}

void Modulo::adicionar(CircuitoSISO *circ)
{
    circuitos->push_back(circ);
}

list<CircuitoSISO *> *Modulo::getCircuitos()
{
    return circuitos;
}

void Modulo::imprimir()
{
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    cout << "Modulo com ID " << ID << " e:" << endl;
    while (i != circuitos->end()) {
        (*i)->imprimir();
        i++;
    }
    cout << "--" << endl;
}