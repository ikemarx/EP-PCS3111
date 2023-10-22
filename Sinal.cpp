#include "Sinal.h"

Sinal::Sinal(double *sequencia, int comprimento) {
    this->sequencia = new double[comprimento];
    for (int i = 0; i < comprimento; i++)
        this->sequencia[i] = sequencia[i];
    this->comprimento = comprimento;
}

Sinal::~Sinal() {
}

double* Sinal::getSequencia() {
    return this->sequencia;
}

int Sinal::getComprimento() {
    return this->comprimento;
}

void Sinal::imprimir(string nomeDoSinal) {
    Grafico* grafico = new Grafico(nomeDoSinal, sequencia, comprimento);
    grafico->plot();
    delete grafico;
}