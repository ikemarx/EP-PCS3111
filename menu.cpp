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

Sinal* novoSinal(); // implementarei aqui mesmo pq n vejo onde mais seria
void novaOperacao(Sinal *sinalIN);

void menu() {
    int escolha;
    double ganho;
    cout << "\tSimulink em C++" << endl;
    cout << "Qual simulacao gostaria de fazer?" << endl;
    cout << "1) Piloto Automatico" << endl; 
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    Sinal *sinal = novoSinal();
    if (escolha == 1) {
        cout << "Qual o ganho do acelerador?" << endl;
        cout << "g = ";
        cin >> ganho;
        ModuloRealimentado* pilotoautomatico = new ModuloRealimentado(ganho);
        pilotoautomatico->processar(sinal)->imprimir("Velocidade do Carro");
        delete pilotoautomatico;
    }
    if (escolha == 2)
        novaOperacao(sinal);
}

// implementacao de novoSinal conforme item 3.4
Sinal *novoSinal() {
    int escolha;
    double c;
    double a;
    double sequencia[60];
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl;
    cout << "1) 5+3*cos(n*pi/8)" << endl;
    cout << "2) constante" << endl;
    cout << "3) rampa" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    if (escolha == 1)
        for (int n = 0; n < 59; n++)
            sequencia[n] = 5 + 3 * cos(n * M_PI / 8);
    if (escolha == 2) {
        cout << "Qual o valor dessa constante?" << endl;
        cout << "c = ";
        cin >> c;
        for (int i = 0; i < 59; i++)
            sequencia[i] = c;
    }
    if (escolha == 3) {
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cout << "a = ";
        cin >> a;
        for (int i = 0; i < 59; i++)
            sequencia[i] = i * a;
    }
    return new Sinal(sequencia, 60);
}

void novaOperacao(Sinal *sinalIN) {
    int escolha;
    double ganho;
    Sinal* sinal2;
    cout << "Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl;
    cout << "2) Somar" << endl;
    cout << "3) Derivar" << endl;
    cout << "4) Integrar" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    if (escolha == 1) {
        cout << "Qual o ganho dessa amplificacao?" << endl;
        cout << "g = ";
        cin >> ganho;
        Amplificador* amplificador = new Amplificador(ganho);
        sinalIN = amplificador->processar(sinalIN);
    }
    if (escolha == 2) {
        cout << "Informe mais um sinal para ser somado." << endl;
        sinal2 = novoSinal();
        Somador* somador = new Somador();
        sinalIN = somador->processar(sinal2, sinalIN);
    }
    if (escolha == 3) {
        Derivador* derivador = new Derivador();
        sinalIN = derivador->processar(sinalIN);
    }
    if (escolha == 4) {
        Integrador* integrador = new Integrador();
        sinalIN = integrador->processar(sinalIN);
    }
    cout << "O que voce quer fazer agora?" << endl;
    cout << "1) Realizar mais uma operacao no resultado" << endl;
    cout << "2) Imprimir o resultado para terminar" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    if (escolha == 2) {
        sinalIN->imprimir("Resultado Final");
        delete sinalIN;
    }
    if (escolha == 1)
        novaOperacao(sinalIN);
}