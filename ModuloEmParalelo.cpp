#include "ModuloEmParalelo.h"

ModuloEmParalelo::ModuloEmParalelo()
{
}

ModuloEmParalelo::~ModuloEmParalelo()
{
}

ModuloEmParalelo::processar(Sinal* SinalIN) {
    
    Somador* somador = new Somador();
    
    list<*CircuitoSISO>::iterador i = circuitos->begin();
    if (circuitos->empty()) throw new logic_error("Sem circuitos");

    while(i =! circuitos->end()) {
        (*i)->processar(SinalIN);
        i ++;
    }
    list<*CircuitoSISO>::iterador i = circuitos->begin();
    somador = somador->processar(*i, ++*i);
    
    while(i =! circuitos->end()) {
        somador->processar(somador, *i++);
    }
    return somador;
}