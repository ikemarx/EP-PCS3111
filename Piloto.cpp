#include "Piloto.h"

Piloto::Piloto(double ganho) {
    this->ganho = ganho;
}

Piloto::~Piloto() {
    delete amplificador;
    delete integrador;
}

Sinal* Piloto::processar(Sinal* sinalIN) {
    amplificador = new Amplificador(ganho);
    integrador = new Integrador();
    Sinal* sinalOUT = integrador->processar(amplificador->processar(sinalIN));
    return sinalOUT;
}