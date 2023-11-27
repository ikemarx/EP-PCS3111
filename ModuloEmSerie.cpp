#include "ModuloEmSerie.h"

ModuloEmSerie::ModuloEmSerie()
{
}

ModuloEmSerie::~ModuloEmSerie()
{
}

Sinal *ModuloEmSerie::processar(Sinal *sinalIN)
{
    if (circuitos->empty())
        throw new logic_error("Nenhum Circuito SISO na lista");
    Sinal* sinalOUT = sinalIN;
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    while (i != circuitos->end()) {
        sinalOUT = (*i)->processar(sinalOUT);
        i++;
    }
    return sinalOUT;
}