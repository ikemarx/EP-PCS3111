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

void menu() {
    int simulacao;
    cout << "\tSimulink em C++" << endl;
    cout << "Qual simulacao gostaria de fazer?" << endl;
    cout << "1) Piloto Automatico" << endl; 
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: ";
    cin >> simulacao;
    Sinal *sinal = novoSinal();
    if (simulacao == 1) {
        cout << "Qual o ganho do acelerador?" << endl;
        cout << "g = ";
        // cin >> ganho; acho q aqui chama o piloto automatico ne
    }
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
    Sinal *sinal = new Sinal(sequencia, 60);
    return sinal;
}
