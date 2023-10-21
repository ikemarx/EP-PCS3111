#include "Amplificador.h"

Amplificador::Amplificador(double ganho) {
    this->ganho = ganho;
}

Amplificador::~Amplificador() {

}

Sinal *Amplificador::processar(Sinal *sinalIN) {
    double* sequenciaAmplificada = new double[sinalIN->getComprimento()];
    double* sequencia = sinalIN->getSequencia();
    
    for (int i = 0; i < sinalIN->getComprimento(); i++) {
        sequenciaAmplificada[i] = sequencia[i] * ganho;
    } 

    Sinal* sinalOUT = new Sinal(sequenciaAmplificada, sinalIN->getComprimento());

    return sinalOUT;
}

void Amplificador::setGanho(double ganho) {
    this->ganho = ganho;
}

double Amplificador::getGanho() {
    return ganho;
}
