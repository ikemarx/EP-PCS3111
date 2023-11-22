#include "Amplificador.h"

Amplificador::Amplificador(double ganho) : ganho(ganho)
{
}

Amplificador::~Amplificador() {

}

Sinal* processar(Sinal *sinalIN) {
    double* sequencia = sinalIN->getSequencia();

    for (int i = 0; i < sinalIN->getComprimento(); i++) {
        sequencia[i] *= ganho;
    }
    Sinal* sinalOUT = new Sinal(sequencia, sinalIN->getComprimento());
    return sinalOUT;
}

void Amplificador::setGanho(double ganho) {
    this->ganho = ganho;
}

double Amplificador::getGanho() {
    return ganho;
}