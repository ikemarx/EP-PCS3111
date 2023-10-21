#ifndef PILOTO_H
#define PILOTO_H

class Piloto {
private:
    Amplificador amplificador;
    Integrador integrador;
    
public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);
};

#endif