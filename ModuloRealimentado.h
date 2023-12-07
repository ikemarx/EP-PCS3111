#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Modulo.h"
#include "Amplificador.h"
#include "Somador.h"
#include "ModuloEmSerie.h"

class ModuloRealimentado : public Modulo {
protected:
    Amplificador* inversor;
    Somador* somador;
    ModuloEmSerie* moduloEmSerie;
public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();

    Sinal *processar(Sinal *sinalIN);
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
};

#endif