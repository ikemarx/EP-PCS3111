#include "Integrador.h"
#include "Sinal.h"

Integrador::Integrador() {

}

Integrador::~Integrador() {

}

Sinal *Integrador::processar(Sinal *sinalIN) {
    int comprimento = sinalIN->getComprimento();
    double* sequencia = sinalIN->getSequencia();
    double* integrado = new double[comprimento];
    integrado[0] = sequencia[0];

    for (int i = 1; i < comprimento; i++) {
        integrado[i] = integrado[i] + sequencia[i - 1];
    }

    Sinal* sinalOUT = new Sinal(integrado, comprimento);

    return sinalOUT;
}
