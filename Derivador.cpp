#include "Derivador.h"

Derivador::Derivador() {

}

Derivador::~Derivador() {
}

Sinal* Derivador::processar(Sinal *sinalIN) {
    double* derivado = new double[sinalIN->getComprimento()];
    double* sequencia = sinalIN->getSequencia();
    derivado[0] = sequencia[0];
    for (int i = 1; i < sinalIN->getComprimento(); i++) {
        derivado[i] = sequencia[i] - sequencia[i-1];
    }
    return new Sinal(derivado, sinalIN->getComprimento());
}
