#include "ModuloEmParalelo.h"

ModuloEmParalelo::ModuloEmParalelo() : Modulo()
{
}

ModuloEmParalelo::~ModuloEmParalelo()
{
}

Sinal* ModuloEmParalelo::processar(Sinal* sinalIN) {
    Somador* somador = new Somador();
    if (circuitos->empty())
        throw logic_error("Nenhum CircuitoSISO na lista");
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    Sinal* sinalOUT = (*i)->processar(sinalIN);
    i++;
    while (i != circuitos->end()) {
        sinalOUT = somador->processar((*i)->processar(sinalIN), sinalOUT);
        i++;
    }
    delete somador;
    return sinalOUT;
}