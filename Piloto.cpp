#include "Piloto.h"

Piloto::Piloto(double ganho) {
    amplificador = new Amplificador(ganho);
    integrador = new Integrador();
}

Piloto::~Piloto() {
    delete amplificador;
    delete integrador;
}

Sinal* Piloto::processar(Sinal* sinalIN) {
    Sinal* sinalOUT = integrador->processar(amplificador->processar(sinalIN));
    return sinalOUT;
}