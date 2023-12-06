#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) : nomeDoArquivo(nomeDoArquivo)
{
}

PersistenciaDeModulo::~PersistenciaDeModulo()
{
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod)
{
    // fazer um iterador aqui da lista circuitoSISO
    list<CircuitoSISO*>::iterator i = circuitos->begin();
}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    return nullptr;
}

void fodase() {
    if (dynamic_cast<ModuloEmSerie*>(*i)) {
        cout << "S" << endl;
        fodase();
    }
}