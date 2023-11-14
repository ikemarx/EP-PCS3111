#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado()
{
}

ModuloRealimentado::~ModuloRealimentado()
{
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN) {
    double sequenciaOUT[sinalIN->getComprimento()];
    sequenciaOUT[0] = ganho * sinalIN->getSequencia()[0];
    for (int i = 1; i < sinalIN->getComprimento(); i++) {
        sequenciaOUT[i] = ((sinalIN->getSequencia()[i] - sequenciaOUT[i - 1]) * ganho) + sequenciaOUT[i - 1];
    }
    Sinal* sinalOUT = new Sinal(sequenciaOUT, sinalIN->getComprimento());
    return sinalOUT;
}