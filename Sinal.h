#ifndef SINAL_H
#define SINAL_H

#include "Grafico.h"
#include <string>
using namespace std;

class Sinal
{
protected:
    double *sequencia;
    int comprimento;
public:
    Sinal(double *sequencia, int comprimento);
    Sinal(double constante, int comprimento);
    ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
    void imprimir(); // para testes
    void imprimir(int tamanho);
};

#endif