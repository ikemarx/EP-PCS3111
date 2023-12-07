#include "PersistenciaDeModulo.h"
#include <iostream>

// Função auxiliar para salvar módulos recursivamente
void salvarModuloRecursivo(ofstream& output, Modulo* mod) {
    if (dynamic_cast<ModuloEmSerie*>(mod)) {
        output << "S" << endl;
    } else if (dynamic_cast<ModuloEmParalelo*>(mod)) {
        output << "P" << endl;
    } else if (dynamic_cast<ModuloRealimentado*>(mod)) {
        output << "R" << endl;
    }
    // Salvar os circuitos internos
    list<CircuitoSISO*>* circuitos = mod->getCircuitos();
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    while (i != circuitos->end()) {
        if (dynamic_cast<Amplificador*>(*i)) {
            Amplificador* amp = dynamic_cast<Amplificador*>(*i);
            output << "A " << amp->getGanho() << endl;
        } else if (dynamic_cast<Integrador*>(*i)) {
            output << "I" << endl;
        } else if (dynamic_cast<Derivador*>(*i)) {
            output << "D" << endl;
        } else if (Modulo* subModulo = dynamic_cast<Modulo*>(*i)) {
            // Chamar recursivamente para ler submódulos
            salvarModuloRecursivo(output, subModulo);
        }
        i++;
    }
    output << "f" << endl; // Indica o final do módulo
}

// Função auxiliar para ler módulos recursivamente
Modulo* lerModuloRecursivo(ifstream& input) {
    string tipo;
    input >> tipo;

    Modulo* mod = nullptr;

    if (tipo == "S") {
        mod = new ModuloEmSerie();
    } else if (tipo == "P") {
        mod = new ModuloEmParalelo();
    } else if (tipo == "R") {
        mod = new ModuloRealimentado();
    }

    // Ler os circuitos internos
    while (true) {
        input >> tipo;

        if (tipo == "A") {
            double ganho;
            input >> ganho;
            mod->adicionar(new Amplificador(ganho));
        } else if (tipo == "I") {
            mod->adicionar(new Integrador());
        } else if (tipo == "D") {
            mod->adicionar(new Derivador());
        } else if (tipo == "S" || tipo == "P" || tipo == "R") {
            // Chamada recursiva para ler submódulos
            Modulo* subModulo = lerModuloRecursivo(input);
            mod->adicionar(subModulo);
        } else if (tipo == "f") {
            // Indica o final do módulo
            return mod;
        } else {
            throw new logic_error("Formato incorreto do arquivo");
        }
    }

    
}

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) : nomeDoArquivo(nomeDoArquivo) {}

PersistenciaDeModulo::~PersistenciaDeModulo() {}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod) {
    output.open(nomeDoArquivo);
    if (!output.is_open()) {
        throw new invalid_argument("Erro ao abrir o arquivo");
    }
    salvarModuloRecursivo(output, mod);
    output.close();
}

Modulo* PersistenciaDeModulo::lerDeArquivo() {
    input.open(nomeDoArquivo);
    if (!input.is_open()) {
        throw new invalid_argument("Erro ao abrir o arquivo");
    }

    Modulo* mod = lerModuloRecursivo(input);

    input.close();

    return mod;
}