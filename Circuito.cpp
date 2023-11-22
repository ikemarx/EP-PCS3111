#include "Circuito.h"

int Circuito::ultimoID = 0;

Circuito::Circuito()
{
    ID = ++ultimoID;
}

Circuito::~Circuito()
{
}

int Circuito::getID()
{
    return ID;
}

void Circuito::imprimir()
{
    cout << "Circuito com ID " << ID << endl;
}

int Circuito::getUltimoID()
{
    return ultimoID;
}