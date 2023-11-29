#include "Derivador.h"

Derivador::Derivador() {

}

Derivador::~Derivador() {
}

Sinal* Derivador::processar(Sinal *sinalIN) {
    double* derivado = sinalIN->getSequencia();
    double* sequencia = sinalIN->getSequencia();
    for (int i = 0; i < sinalIN->getComprimento() - 1; i++) {
        derivado[i + 1] -= sequencia[i];
    }
    return new Sinal(derivado, sinalIN->getComprimento());
}
