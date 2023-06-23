#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class No {
public:
    char nome;
    No* prox;

    No(char n) {
        nome = n;
        prox = NULL;
    }
};

class Fila {
public:
    No* inicio;
    No* fim;

    Fila() {
        inicio = NULL;
        fim = NULL;
    }

    void enfileira(char n) {
        No* novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    char desenfileira() {
        No* el;
        char nome;
        if (inicio != NULL) {
            el = inicio;
            nome = el->nome;
            inicio = inicio->prox;
            delete el;
        }
        return nome;
    }

    bool vazia() {
        return (inicio == NULL);
    }

    void mostra() {
        No* atual = inicio;
        while (atual != NULL) {
            printf("Nome: %c\n", atual->nome);
            atual = atual->prox;
        }
    }


};

void bfs( char v, char w, No* adj[]) {
    Fila* f = new Fila();
    bool visitado[256] = { false };
    f->enfileira(v);
    visitado[v] = true;
    while (!f->vazia()) {
        char c = f->desenfileira();
        if (c == w) {
            cout << "Caminho encontrado: " << c << endl;
            break;
        } else {
            for (No* s = adj[c]; s; s = s->prox) {
                if (!visitado[s->nome]) {
                    f->enfileira(s->nome);
                    visitado[s->nome] = true;
                }
            }
        }
    }
    delete f;
}



int main() {

    No* adj[256] = { NULL };
    adj['A'] = new No('A');
    adj['A']->prox = new No('B');
    adj['B'] = new No('B');
    adj['B']->prox = new No('C');
    adj['C'] = new No('C');
    adj['C']->prox = new No('D');
    adj['D'] = new No('D');
    adj['D']->prox = new No('E');
    adj['E'] = new No('E');

    char v = 'A';
    char w = 'E';
    bfs(v, w, adj);

    return 0;
}
