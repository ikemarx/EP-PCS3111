#ifndef INTEGRADOR_H
#define INTEGRADOR_H

class Integrador
{
public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);
};

#endif