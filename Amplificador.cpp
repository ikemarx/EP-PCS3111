#include "Amplificador.h"

Amplificador::Amplificador(double ganho) : ganho(ganho)
{
}

Amplificador::~Amplificador() {

}

Sinal* Amplificador::processar(Sinal *sinalIN) {
    double* sequencia = sinalIN->getSequencia();
    for (int i = 0; i < sinalIN->getComprimento(); i++) {
        sequencia[i] *= ganho;
    }
    return new Sinal(sequencia, sinalIN->getComprimento());
}

void Amplificador::setGanho(double ganho) {
    this->ganho = ganho;
}

double Amplificador::getGanho() {
    return ganho;
}