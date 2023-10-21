#include "Somador.h"
#include "Sinal.h"

Somador::Somador() {

}

Somador::~Somador() {

}

Sinal *Somador::processar(Sinal *sinalIN1, Sinal *sinalIN2) {
    int comprimento;
    double* seq1 = sinalIN1->getSequencia();
    double* seq2 = sinalIN2->getSequencia();

    if (sinalIN2->getComprimento() < sinalIN1->getComprimento()) {
        comprimento = sinalIN2->getComprimento();
    }   else comprimento = sinalIN1->getComprimento();

    double* somado = new double[comprimento];

    for (int i = 0; i < comprimento; i++) {
        somado[i] = seq1[i] + seq2[i];
    }

    Sinal* sinalOUT = new Sinal(somado, comprimento);

    return sinalOUT; 
}
