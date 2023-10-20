#ifndef INTEGRADOR_H
#define INTEGRADOR_H

class Integrador
{
private:
    /* data */
public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);
};

#endif