#ifndef SOMADOR_H
#define SOMADOR_H

class Somador
{
public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};

#endif