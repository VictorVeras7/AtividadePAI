#include <iostream>
#include "arvore.h"

using namespace std;

int main()
{
    ArvoreDec arvore;

    int opcao;
    bool busca = false;

    do {
        cout << "Digite 0 para parar o algoritmo!" << endl;
        cout << "Digite 1 para inserir um sintoma!" << endl;
        cout << "Digite 2 para remover um sintoma!" << endl;
        cout << "Digite 3 para buscar um sintoma!" << endl;
        cout << "Digite 4 para imprimir a árvore!" << endl;
        cin >> opcao;

        if (opcao == 1) {
            int resposta;
            cout << "Digite a resposta do sintoma (1 para Sim, 0 para Não): ";
            cin >> resposta;
            diagnostico diagn(resposta);

            if (arvore.estacheio()) {
                cout << "A árvore está cheia!" << endl;
                cout << "Não foi possível inserir o sintoma!" << endl;
            } else {
                arvore.inserir(diagn);
            }
        } else if (opcao == 2) {
            int resposta;
            cout << "Digite a resposta do sintoma a ser removido (1 para Sim, 0 para Não): ";
            cin >> resposta;
            diagnostico diagn(resposta);
            arvore.remover(diagn);
        } else if (opcao == 3) {
            int resposta;
            cout << "Digite a resposta do sintoma a ser buscado (1 para Sim, 0 para Não): ";
            cin >> resposta;
            diagnostico diagn(resposta);
            arvore.buscar(diagn, busca);
            if (busca) {
                cout << "Sintoma encontrado!" << endl;
                cout << "Resposta: " << diagn.obterResposta() << endl;
            } else {
                cout << "Sintoma não encontrado!" << endl;
            }
        } else if (opcao == 4) {
            int imp;
            cout << "Digite 1 para fazer a impressão em pré-ordem!" << endl;
            cout << "Digite 2 para fazer a impressão em ordem!" << endl;
            cout << "Digite 3 para fazer a impressão em pós-ordem!" << endl;
            cin >> imp;
            if (imp == 1) {
                arvore.imprimirpreo(arvore.obterRaiz());
            } else if (imp == 2) {
                arvore.imprimiremo(arvore.obterRaiz());
            } else if (imp == 3) {
                arvore.imprimirposo(arvore.obterRaiz());
            }
        }
    } while (opcao != 0);

    return 0;
}
