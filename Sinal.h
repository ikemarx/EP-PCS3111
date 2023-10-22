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
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
};

#endif