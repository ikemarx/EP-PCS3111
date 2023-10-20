#ifndef DERIVADOR_H
#define DERIVADOR_H

class Derivador
{
private:
    /* data */
public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN);
};

#endif