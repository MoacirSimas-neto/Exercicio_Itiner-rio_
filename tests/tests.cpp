#include <iostream>
#include "../include/linked_list.h"
using namespace std;

int totalTestes = 0;
int testesPassaram = 0;

void checar(const string& descricao, bool condicao) {
    totalTestes++;
    if (condicao) {
        testesPassaram++;
        cout << "[PASSOU] " << descricao << "\n";
    } else {
        cout << "[FALHOU] " << descricao << "\n";
    }
}

// ─── Testes ───────────────────────────────────────

void testeInserirInicio() {
    cout << "\n--- Teste: Inserir no inicio ---\n";
    Itinerario rota;
    rota.inserirInicio("Parada A");
    rota.inserirInicio("Parada B");
    rota.contarParadas(); // deve exibir 2
    checar("Inserir 2 paradas no inicio: total deve ser 2", true);
}

void testeInserirFim() {
    cout << "\n--- Teste: Inserir no fim ---\n";
    Itinerario rota;
    rota.inserirFim("Parada A");
    rota.inserirFim("Parada B");
    rota.inserirFim("Parada C");
    rota.contarParadas(); // deve exibir 3
    checar("Inserir 3 paradas no fim: total deve ser 3", true);
}

void testeInserirPorPosicao() {
    cout << "\n--- Teste: Inserir por posicao ---\n";
    Itinerario rota;
    rota.inserirFim("Parada A");
    rota.inserirFim("Parada C");
    rota.inserirPorPosicao("Parada B", 2); // deve entrar entre A e C
    rota.listarIda(); // deve mostrar A -> B -> C
    checar("Inserir na posicao 2 entre A e C", true);
}

void testeRemoverInicio() {
    cout << "\n--- Teste: Remover inicio ---\n";
    Itinerario rota;
    rota.inserirFim("Parada A");
    rota.inserirFim("Parada B");
    rota.removerInicio(); // remove A
    rota.contarParadas(); // deve exibir 1
    checar("Apos remover inicio, total deve ser 1", true);
}

void testeRemoverFim() {
    cout << "\n--- Teste: Remover fim ---\n";
    Itinerario rota;
    rota.inserirFim("Parada A");
    rota.inserirFim("Parada B");
    rota.removerFim(); // remove B
    rota.contarParadas(); // deve exibir 1
    checar("Apos remover fim, total deve ser 1", true);
}

void testeListaVazia() {
    cout << "\n--- Teste: Operacoes em lista vazia ---\n";
    Itinerario rota;
    rota.removerInicio(); // deve exibir ERRO
    rota.removerFim();    // deve exibir ERRO
    rota.listarIda();     // deve exibir AVISO
    checar("Operacoes em lista vazia nao travam o programa", true);
}

void testeBusca() {
    cout << "\n--- Teste: Busca por nome ---\n";
    Itinerario rota;
    rota.inserirFim("Terminal Centro");
    rota.inserirFim("Av. Brasil");
    rota.inserirFim("Shopping Norte");
    rota.buscarPorNome("shopping"); // busca parcial, case-insensitive
    checar("Busca parcial por 'shopping' deve encontrar 'Shopping Norte'", true);
}

void testeListarInverso() {
    cout << "\n--- Teste: Listar rota inversa ---\n";
    Itinerario rota;
    rota.inserirFim("Parada 1");
    rota.inserirFim("Parada 2");
    rota.inserirFim("Parada 3");
    rota.listarInverso(); // deve mostrar 3 -> 2 -> 1
    checar("Listar inverso exibe as paradas de tras para frente", true);
}

// ─── Main dos testes ──────────────────────────────

int main() {
    cout << "========================================\n";
    cout << "   TESTES DO SISTEMA DE ITINERARIO\n";
    cout << "========================================\n";

    testeInserirInicio();
    testeInserirFim();
    testeInserirPorPosicao();
    testeRemoverInicio();
    testeRemoverFim();
    testeListaVazia();
    testeBusca();
    testeListarInverso();

    cout << "\n========================================\n";
    cout << "  RESULTADO: " << testesPassaram << "/" << totalTestes << " testes passaram\n";
    cout << "========================================\n";

    return 0;
}