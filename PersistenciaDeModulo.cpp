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
    input.open(nomeDoArquivo);
}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    return nullptr;
}
