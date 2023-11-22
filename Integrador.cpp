#include "Integrador.h"

Integrador::Integrador() {

}

Integrador::~Integrador() {

}

Sinal* Integrador::processar(Sinal *sinalIN) {
    double* sequencia = sinalIN->getSequencia();
    for (int i = 0; i < sinalIN->getComprimento(); i++) {
        sequencia[i + 1] += sequencia[i];
    }
    return new Sinal(sequencia, sinalIN->getComprimento());
}
