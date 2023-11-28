#include "ModuloEmSerie.h"

ModuloEmSerie::ModuloEmSerie() : Modulo()
{
}

ModuloEmSerie::~ModuloEmSerie()
{
}

Sinal *ModuloEmSerie::processar(Sinal *sinalIN)
{
    if (circuitos->empty())
        throw new logic_error("Nenhum CircuitoSISO na lista");
    Sinal* sinalOUT = sinalIN;
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    while (i != circuitos->end()) {
        sinalOUT = (*i)->processar(sinalOUT);
        i++;
    }
    return sinalOUT;
}