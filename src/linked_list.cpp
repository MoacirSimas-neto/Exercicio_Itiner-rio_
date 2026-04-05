#include "../include/linked_list.h"
#include <iostream>
#include <algorithm>
using namespace std;

Itinerario::Itinerario() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

Itinerario::~Itinerario() {
    No* atual = cabeca;
    while (atual) {
        No* temp = atual->proximo;
        delete atual;
        atual = temp;
    }
}

string Itinerario::minusculas(const string& s) const {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void Itinerario::inserirInicio(const string& nome) {
    No* novo = new No(nome);
    if (!cabeca) {
        cabeca = cauda = novo;
    } else {
        novo->proximo = cabeca;
        cabeca->anterior = novo;
        cabeca = novo;
    }
    tamanho++;
    cout << "[OK] Parada \"" << nome << "\" inserida no inicio da rota.\n";
}

void Itinerario::inserirFim(const string& nome) {
    No* novo = new No(nome);
    if (!cauda) {
        cabeca = cauda = novo;
    } else {
        novo->anterior = cauda;
        cauda->proximo = novo;
        cauda = novo;
    }
    tamanho++;
    cout << "[OK] Parada \"" << nome << "\" inserida no final da rota.\n";
}

void Itinerario::inserirPorPosicao(const string& nome, int posicao) {
    if (posicao <= 1) { inserirInicio(nome); return; }
    if (posicao > tamanho) { inserirFim(nome); return; }

    No* novo = new No(nome);
    No* atual = cabeca;
    for (int i = 1; i < posicao - 1; i++) atual = atual->proximo;

    novo->proximo = atual->proximo;
    novo->anterior = atual;
    if (atual->proximo) atual->proximo->anterior = novo;
    atual->proximo = novo;

    tamanho++;
    cout << "[OK] Parada \"" << nome << "\" inserida na posicao " << posicao << ".\n";
}

void Itinerario::removerInicio() {
    if (!cabeca) { cout << "[ERRO] A rota esta vazia.\n"; return; }
    string nome = cabeca->nome;
    No* temp = cabeca;
    cabeca = cabeca->proximo;
    if (cabeca) cabeca->anterior = nullptr;
    else cauda = nullptr;
    delete temp;
    tamanho--;
    cout << "[OK] Parada \"" << nome << "\" removida do inicio.\n";
}

void Itinerario::removerFim() {
    if (!cauda) { cout << "[ERRO] A rota esta vazia.\n"; return; }
    string nome = cauda->nome;
    No* temp = cauda;
    cauda = cauda->anterior;
    if (cauda) cauda->proximo = nullptr;
    else cabeca = nullptr;
    delete temp;
    tamanho--;
    cout << "[OK] Parada \"" << nome << "\" removida do final.\n";
}

void Itinerario::buscarPorNome(const string& busca) const {
    if (!cabeca) { cout << "[ERRO] A rota esta vazia.\n"; return; }
    string buscaMin = minusculas(busca);
    No* atual = cabeca;
    int posicao = 1;
    bool encontrado = false;

    cout << "\n--- Resultado da busca por \"" << busca << "\" ---\n";
    while (atual) {
        if (minusculas(atual->nome).find(buscaMin) != string::npos) {
            cout << "  Posicao " << posicao << ": " << atual->nome << "\n";
            encontrado = true;
        }
        atual = atual->proximo;
        posicao++;
    }
    if (!encontrado) cout << "  Nenhuma parada encontrada.\n";
    cout << "-------------------------------------------\n";
}

void Itinerario::listarIda() const {
    if (!cabeca) { cout << "[AVISO] A rota esta vazia.\n"; return; }
    cout << "\n========= ROTA COMPLETA (IDA) =========\n";
    No* atual = cabeca;
    int pos = 1;
    while (atual) {
        cout << "  [" << pos++ << "] " << atual->nome;
        if (atual->proximo) cout << " --> ";
        atual = atual->proximo;
    }
    cout << "\n=======================================\n";
}

void Itinerario::listarInverso() const {
    if (!cauda) { cout << "[AVISO] A rota esta vazia.\n"; return; }
    cout << "\n======= ROTA COMPLETA (VOLTA) =========\n";
    No* atual = cauda;
    int pos = tamanho;
    while (atual) {
        cout << "  [" << pos-- << "] " << atual->nome;
        if (atual->anterior) cout << " --> ";
        atual = atual->anterior;
    }
    cout << "\n=======================================\n";
}

void Itinerario::contarParadas() const {
    cout << "[INFO] Total de paradas na rota: " << tamanho << "\n";
}