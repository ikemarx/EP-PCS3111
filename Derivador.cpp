#include "Derivador.h"
#include "Sinal.h"

Derivador::Derivador() {

}

Derivador::~Derivador() {

}

Sinal *Derivador::processar(Sinal *sinalIN) {
    double* derivado = new double[sinalIN->getComprimento()];
    double* sequencia = sinalIN->getSequencia();
    derivado[0] = sequencia[0];
    for (int i = 1; i < sinalIN->getComprimento() - 1; i++) {
        derivado[i] = sequencia[i + 1] - sequencia[i];
    }
    
    Sinal* sinalOUT = new Sinal(derivado, sinalIN->getComprimento());

    return sinalOUT;
}
