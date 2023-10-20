#ifndef SINAL_H
#define SINAL_H

class Sinal
{
private:
    /* data */
public:
    Sinal(double *sequencia, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
};

#endif