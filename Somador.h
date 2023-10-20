#ifndef SOMADOR_H
#define SOMADOR_H

class Somador
{
private:
    /* data */
public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};

#endif