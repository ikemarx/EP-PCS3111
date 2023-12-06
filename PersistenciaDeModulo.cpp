#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) : nomeDoArquivo(nomeDoArquivo)
{
}

PersistenciaDeModulo::~PersistenciaDeModulo()
{
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod)
{


    ofstream output;
    // auxilio(mod, output);

    // fazer um iterador aqui da lista circuitoSISO

}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    return nullptr;
}

/* void auxilio(Modulo* mod, ofstream output) {
    list<CircuitoSISO*>* circuitos = mod->getCircuitos();
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    while (i != circuitos->end()) {
        if (dynamic_cast<ModuloEmSerie*>(*i)) {
            output << "S" << endl;
            auxilio(dynamic_cast<Modulo*>(*i), output);
        }
        if (dynamic_cast<ModuloEmParalelo*>(*i)) {
            output << "P" << endl;
            auxilio();
        }
        if (dynamic_cast<ModuloRealimentado*>(*i)) {
            output << "R" << endl;
            auxilio();
        }
        if (dynamic_cast<Amplificador*>(*i)) {
            output << "A" << endl;
            auxilio();
        }
        if (dynamic_cast<ModuloEmSerie*>(*i)) {
            output << "S" << endl;
            auxilio();
        }
        if (dynamic_cast<ModuloEmSerie*>(*i)) {
            output << "S" << endl;
            auxilio();
        }
        i++;
    }
} */