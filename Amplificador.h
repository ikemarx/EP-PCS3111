#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

class Amplificador {
private:

public:
    Amplificador(double ganho);
    virtual ~Amplificador();
    Sinal* processar(Sinal* sinalIN);
    void setGanho(double ganho);
    double getGanho();
};

#endif