#include "Sinal.h"

Sinal::Sinal(double *sequencia, int comprimento) {
    this->sequencia = new double[comprimento];
    for (int i = 0; i < comprimento; i++)
        this->sequencia[i] = sequencia[i];
    this->comprimento = comprimento;
}

Sinal::~Sinal() {
    delete[] sequencia;
}

double* Sinal::getSequencia() {
    return sequencia;
}

int Sinal::getComprimento() {
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal) {
    Grafico* grafico = new Grafico(nomeDoSinal, sequencia, comprimento);
    grafico->plot();
    delete grafico;
}