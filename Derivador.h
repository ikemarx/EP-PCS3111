#ifndef DERIVADOR_H
#define DERIVADOR_H

class Derivador {

public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN);
};

#endif