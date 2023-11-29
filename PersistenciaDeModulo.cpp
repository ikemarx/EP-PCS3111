#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) : nomeDoArquivo(nomeDoArquivo)
{
}

PersistenciaDeModulo::~PersistenciaDeModulo()
{
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod)
{
    ifstream input;
    list<CircuitoSISO*>* circuitos = mod->getCircuitos();
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    input.open(nomeDoArquivo);
    while(i != circuitos->end()) {
        
        i++;
    }
    
}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    return nullptr;
}
