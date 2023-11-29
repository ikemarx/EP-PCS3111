#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado(double ganho)
{
    piloto = new Piloto(ganho);
    inversor = new Amplificador(-1);
    somador = new Somador();
}

ModuloRealimentado::~ModuloRealimentado()
{
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN) {
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;
    int vInicial = 0;
    double* sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
    
    sequenciaSaidaInvertida[0] = vInicial;
    diferenca = new Sinal(sinalIN->getSequencia(), 1);
    saida = piloto->processar(diferenca);
    delete diferenca;

    for (int i = 1; i < sinalIN->getComprimento(); i++) {
        sequenciaSaidaInvertida[i] = inversor->processar(saida)->getSequencia()[i - 1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
        diferenca = somador->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = piloto->processar(diferenca);
        delete saidaInvertida;
        delete diferenca;
    }
    return saida;
}