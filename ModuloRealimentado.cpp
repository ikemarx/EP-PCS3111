#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado(double ganho) {
    this->ganho = ganho;
    inversor = new Amplificador(-1.0);
    somador = new Somador();
    piloto = new Piloto(ganho);
    diferenca = nullptr;
    saida = nullptr;
    saidaInvertida = nullptr;
    vInicial = 0;
    sequenciaSaidaInvertida = nullptr;
}

ModuloRealimentado::~ModuloRealimentado() {
    delete inversor;
    delete somador;
    delete piloto;
    delete diferenca;
    delete saida;
    delete saidaInvertida;
    delete[] sequenciaSaidaInvertida;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN) {
    sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
    /* sequenciaSaidaInvertida[0] = vInicial;
    diferenca = new Sinal(sinalIN->getSequencia(), 1);
    saida = piloto->processar(diferenca);
    delete diferenca;
    for (int i = 1; i < sinalIN->getComprimento() - 1; i++) {
        sequenciaSaidaInvertida[i] = inversor->processar(saida)->getSequencia()[i - 1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
        diferenca = somador->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = new Sinal(diferenca->getSequencia(), diferenca->getComprimento());
        delete saidaInvertida;
        delete diferenca;
    }
    return saida; */
    sequenciaSaidaInvertida[0] = ganho * sinalIN->getSequencia()[0];
    for (int i = 1; i < sinalIN->getComprimento(); i++) {
        sequenciaSaidaInvertida[i] = ((sinalIN->getSequencia()[i] - sequenciaSaidaInvertida[i - 1]) * ganho) + sequenciaSaidaInvertida[i - 1];
    }
    Sinal* sinalOUT = new Sinal(sequenciaSaidaInvertida, sinalIN->getComprimento());
    return sinalOUT;
}