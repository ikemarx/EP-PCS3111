#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

class ModuloRealimentado {
private:

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif