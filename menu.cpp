#include "Amplificador.h"
#include "Derivador.h"
#include "Grafico.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Piloto.h"
#include "Sinal.h"
#include "Somador.h"
#include <cmath>
#include <iostream>
using namespace std;

void menu() {
    cout << "Qual simulacao gostaria de fazer?" << endl;
    cout << "1) Piloto Automatico" << endl; 
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: ";
}