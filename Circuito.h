#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "Grafico.h"
#include <string>
using namespace std;

class Circuito
{
protected:
public:
    Circuito();
    virtual ~Circuito();
    int getID();
    void imprimir();
    static int getUltimoID();
};

#endif