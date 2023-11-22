#include "Sinal.h"

Sinal::Sinal(double *sequencia, int comprimento) {
    if (comprimento <= 0)
        throw new invalid_argument("Comprimento Invalido");
    this->sequencia = new double[comprimento];
    for (int i = 0; i < comprimento; i++)
        this->sequencia[i] = sequencia[i];
    this->comprimento = comprimento;
}

Sinal::Sinal(double constante, int comprimento)
{
    if (comprimento <= 0)
        throw new invalid_argument("Comprimento Invalido");
    this->sequencia = new double[comprimento];
    *sequencia = {constante};
    this->comprimento = comprimento;
}

Sinal::~Sinal() {
    delete sequencia;
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

void Sinal::imprimir()
{
    for (int i = 0; i < comprimento; i++) {
        cout << i << "- " << sequencia[i] << endl;
    }
    cout << "--" << endl;
}

void Sinal::imprimir(int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        cout << i << "- " << sequencia[i] << endl;
    }
    cout << "--" << endl;
}
