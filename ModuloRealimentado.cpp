#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado(double ganho) {
    piloto = new Piloto(ganho);
}

ModuloRealimentado::~ModuloRealimentado() {
    delete sequenciaSaidaInvertida;
    delete somador;
    delete inversor;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN) {
    inversor = new Amplificador(-1.0);
    somador = new Somador();
    sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
    sequenciaSaidaInvertida[0] = vInicial;
    diferenca = new Sinal(sinalIN->getSequencia(), 1);
    saida = piloto->processar(diferenca);
    delete diferenca;
    for (int i = 1; i < sinalIN->getComprimento() - 1; i++) {
        inversor->processar(saida);
        sequenciaSaidaInvertida[i] = saida->getSequencia()[i - 1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
        diferenca = somador->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = new Sinal(diferenca->getSequencia(), diferenca->getComprimento());
        delete saidaInvertida;
        delete diferenca;
    }
    return saida;
}