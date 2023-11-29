#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H

#include<string>
#include "Modulo.h"
#include<fstream>

class PersistenciaDeModulo
{
private:
    string nomeDoArquivo;
public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};

#endif