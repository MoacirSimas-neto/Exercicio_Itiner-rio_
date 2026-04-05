#include <iostream>
#include <string>
#include "include/linked_list.h"
using namespace std;

void exibirMenu() {
    cout << "\n=========================================\n";
    cout << "    SISTEMA DE ITINERARIO DE ONIBUS\n";
    cout << "=========================================\n";
    cout << "  1. Inserir parada no inicio\n";
    cout << "  2. Inserir parada no fim\n";
    cout << "  3. Inserir parada por posicao\n";
    cout << "  4. Remover primeira parada\n";
    cout << "  5. Remover ultima parada\n";
    cout << "  6. Buscar parada por nome\n";
    cout << "  7. Listar rota completa (ida)\n";
    cout << "  8. Listar rota em ordem inversa\n";
    cout << "  9. Contar paradas\n";
    cout << "  0. Sair\n";
    cout << "=========================================\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Itinerario rota;
    int opcao;
    string nome;
    int posicao;

    cout << "Bem-vindo ao Sistema de Itinerario de Onibus!\n";

    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Nome da parada: ";
                getline(cin, nome);
                rota.inserirInicio(nome);
                break;
            case 2:
                cout << "Nome da parada: ";
                getline(cin, nome);
                rota.inserirFim(nome);
                break;
            case 3:
                cout << "Nome da parada: ";
                getline(cin, nome);
                cout << "Posicao: ";
                cin >> posicao;
                cin.ignore();
                rota.inserirPorPosicao(nome, posicao);
                break;
            case 4:
                rota.removerInicio();
                break;
            case 5:
                rota.removerFim();
                break;
            case 6:
                cout << "Digite o nome (ou parte) da parada: ";
                getline(cin, nome);
                rota.buscarPorNome(nome);
                break;
            case 7:
                rota.listarIda();
                break;
            case 8:
                rota.listarInverso();
                break;
            case 9:
                rota.contarParadas();
                break;
            case 0:
                cout << "Encerrando o sistema. Ate logo!\n";
                break;
            default:
                cout << "[ERRO] Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}