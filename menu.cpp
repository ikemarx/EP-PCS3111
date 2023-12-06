#include "Amplificador.h"
#include "Derivador.h"
#include "Grafico.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Piloto.h"
#include "Sinal.h"
#include "Somador.h"
#include "Circuito.h"
#include "CircuitoMISO.h"
#include "CircuitoSISO.h"
#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "PersistenciaDeModulo.h"
#include <cmath>
#include <iostream>
using namespace std;

void i(string);
void o(string);
void novaOperacao(Sinal*sinal, Modulo*modulo);
Sinal* novoSinal();

void menu() {

    Modulo* modulo;
    Sinal* sinal;
    PersistenciaDeModulo* persistencia;
    int escolha;
    double sequencia[60], a;
    string nomeArquivo;


{ // inicio ---------------------------------------------------------------------------------------------------
    cout << "\tSimulink em C++" << endl; 
    cout << "Qual simulacao gostaria de fazer?" << endl;
    cout << "1) Circuito advindo de arquivo" << endl; 
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: ";
    cin >> escolha;
}

{ // criacao de um novo sinal
    try {
    sinal = novoSinal();
    } catch(invalid_argument *e) {
        cout << e->what();
        delete e;
    }
}

{ // simulacao 1 -----------------------------------------------------------------------------------------------
    if (escolha == 1) {
    i("Qual o nome do arquivo a ser lido?");
    o("Nome: ");
    cin >> nomeArquivo;
        try {
        persistencia = new PersistenciaDeModulo(nomeArquivo);
        } catch (invalid_argument *e) {
            cout << e->what();
            delete e;
        }
        try {
        (persistencia->lerDeArquivo())->processar(sinal);
        } catch (logic_error *e) {
            cout << e->what();
            delete e;
        }
    }
}
    
{ // simulacao 2 -----------------------------------------------------------------------------------------------
    if (escolha == 2) {
        int escolhaOperacoes;
        i("Qual estrutura de operacoes voce deseja ter como base?");
        i("1) Operacoes em serie nao realimentadas");
        i("2) Operacoes em paralelo nao realimendadas");
        i("3) Operacoes em serie realimentadas");
        o("Escolha: ");
        cin >> escolhaOperacoes;
        
        if (escolhaOperacoes == 1) {
            ModuloEmSerie* modulo = new ModuloEmSerie();
        }

        if (escolhaOperacoes == 2) {
            ModuloEmParalelo* modulo = new ModuloEmParalelo();
        }

        if (escolhaOperacoes == 3) {
            ModuloRealimentado* modulo = new ModuloRealimentado();
        }

        { // processo de aquisicao de uma nova operacao ---------------------------------------------------------
        novaOperacao(sinal, modulo);
        }

        i("Voce gostaria de salvar o circuito em um novo arquivo?");
        i("1) Sim");
        i("2) Nao");
        o("Escolha: ");
        cin >> escolhaOperacoes;

        if (escolha == 1) {
            i("Qual o nome do arquivo a ser escrito?");
            o("Nome: ");
            cin >> nomeArquivo;

            try {
            persistencia = new PersistenciaDeModulo(nomeArquivo);
            } catch (invalid_argument *e) {
                cout << e->what();
                delete e;
            }
            
            persistencia->salvarEmArquivo(modulo);
            delete modulo;
        }
    }
}

}

//--------------------------------------------------------------------------------------------------------------

void o(string p) { // imprime sem pular linha
    cout << p;
}

void i(string p) { // imprime pulando linha
    cout << p;
    cout << endl;
}

Sinal *novoSinal() { // cria um novo sinal
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
        for (int n = 0; n < 60; n++)
            sequencia[n] = 5 + 3 * cos(n * M_PI / 8);

    if (escolha == 2) {
        cout << "Qual o valor dessa constante?" << endl;
        cout << "c = ";
        cin >> c;
        return new Sinal(c, 60);
    }

    if (escolha == 3) {
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cout << "a = ";
        cin >> a;
        for (int i = 0; i < 60; i++)
            sequencia[i] = (i + 1) * a;
    }
    return new Sinal(sequencia, 60);
}

void novaOperacao(Sinal*sinalIN, Modulo* modulo) { // realiza operacoes com o sinal
    int escolhaOperacoes;
    double g;

        i("Qual operacao voce gostaria de fazer?");
        i("1) Amplificar");
        i("2) Derivar");
        i("3) Integrar");
        o("Escolha: ");
        cin >> escolhaOperacoes;

        if (escolhaOperacoes == 1) { // amplifica
            i("Qual o ganho dessa amplificacao?");
            o("g = ");
            cin >> g;
            Amplificador* amplificador = new Amplificador(g);
            modulo->adicionar(amplificador);
        }

        if (escolhaOperacoes == 2) { // deriva
            Derivador* derivador = new Derivador();
            modulo->adicionar(derivador);
        }

        if (escolhaOperacoes == 3) { // integra
            Integrador* integrador = new Integrador();
            modulo->adicionar(integrador);
        }

        i("O que voce quer fazer agora?");
        i("1) Realizar mais uma operacao no resultado");
        i("Imprimir o resultado");
        o("Escolha: ");
        cin >> escolhaOperacoes;

        if(escolhaOperacoes == 1) {
            novaOperacao(sinalIN, modulo);
        }

        if (escolhaOperacoes == 2) {
            modulo->processar(sinalIN);
            sinalIN->imprimir("Resultado Final");
            delete sinalIN;
        }
}
