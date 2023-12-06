#include "PersistenciaDeModulo.h"
#include <iostream>

// Função auxiliar para salvar módulos recursivamente
void salvarModuloRecursivo(ofstream& arquivo, Modulo* mod) {
    if (dynamic_cast<ModuloEmSerie*>(mod)) {
        arquivo << "S" << endl;
    } else if (dynamic_cast<ModuloEmParalelo*>(mod)) {
        arquivo << "P" << endl;
    } else if (dynamic_cast<ModuloRealimentado*>(mod)) {
        arquivo << "R" << endl;
    }

    // Salvar os circuitos internos
    for (Circuito* circuito : mod->getCircuitosInternos()) {
        if (dynamic_cast<Amplificador*>(circuito)) {
            Amplificador* amp = dynamic_cast<Amplificador*>(circuito);
            arquivo << "A " << amp->getGanho() << endl;
        } else if (dynamic_cast<Integrador*>(circuito)) {
            arquivo << "I" << endl;
        } else if (dynamic_cast<Derivador*>(circuito)) {
            arquivo << "D" << endl;
        } else if (Modulo* subModulo = dynamic_cast<Modulo*>(circuito)) {
            // Chamar recursivamente para ler submódulos
            salvarModuloRecursivo(arquivo, subModulo);
        }
    }

    arquivo << "f" << endl; // Indica o final do módulo
}

// Função auxiliar para ler módulos recursivamente
Modulo* lerModuloRecursivo(ifstream& arquivo) {
    string tipo;
    arquivo >> tipo;

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
        arquivo >> tipo;

        if (tipo == "A") {
            double ganho;
            arquivo >> ganho;
            mod->adicionar(new Amplificador(ganho));
        } else if (tipo == "I") {
            mod->adicionar(new Integrador());
        } else if (tipo == "D") {
            mod->adicionar(new Derivador());
        } else if (tipo == "S" || tipo == "P" || tipo == "R") {
            // Chamada recursiva para ler submódulos
            Modulo* subModulo = lerModuloRecursivo(arquivo);
            mod->adicionar(subModulo);
        } else if (tipo == "f") {
            // Indica o final do módulo
            break;
        } else {
            throw logic_error("Formato incorreto do arquivo");
        }
    }

    return mod;
}

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) : nomeDoArquivo(nomeDoArquivo) {
    output.open(nomeDoArquivo);
    if (!output.is_open()) {
        throw invalid_argument("Erro ao abrir o arquivo");
    }
}

PersistenciaDeModulo::~PersistenciaDeModulo() {
    output.close();
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod) {
    salvarModuloRecursivo(output, mod);
}

Modulo* PersistenciaDeModulo::lerDeArquivo() {
    ifstream input(nomeDoArquivo);
    if (!input.is_open()) {
        throw invalid_argument("Erro ao abrir o arquivo");
    }

    Modulo* mod = lerModuloRecursivo(input);

    input.close();

    return mod;
}