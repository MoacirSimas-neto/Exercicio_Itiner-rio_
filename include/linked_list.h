#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;

struct No {
    string nome;
    No* anterior;
    No* proximo;
    No(const string& n) : nome(n), anterior(nullptr), proximo(nullptr) {}
};

class Itinerario {
private:
    No* cabeca;
    No* cauda;
    int tamanho;
    string minusculas(const string& s) const;

public:
    Itinerario();
    ~Itinerario();

    void inserirInicio(const string& nome);
    void inserirFim(const string& nome);
    void inserirPorPosicao(const string& nome, int posicao);
    void removerInicio();
    void removerFim();
    void buscarPorNome(const string& busca) const;
    void listarIda() const;
    void listarInverso() const;
    void contarParadas() const;
};

#endif