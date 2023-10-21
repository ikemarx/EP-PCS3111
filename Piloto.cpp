#include "Piloto.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"

Piloto::Piloto(double ganho) : amplificador(ganho) {
    
}

Piloto::~Piloto() {

}

Sinal *Piloto::processar(Sinal *sinalIN) {
    Sinal* sinalOUT = integrador.processar(amplificador.processar(sinalIN));
    //delete integrador
    //delete amplificador
    return sinalOUT;
}
