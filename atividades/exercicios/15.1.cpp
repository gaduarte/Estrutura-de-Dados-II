#include <iostream>

using namespace std;

struct No {
    int item;
    No* prox;

    No(int valor) {
        item = valor;
        prox = nullptr;
    }
};

int main() {
    No* adj[6];

    adj[0] = new No(1);
    adj[0]->prox = new No(2);
    adj[0]->prox->prox = new No(3);

    adj[1] = new No(0);
    adj[1]->prox = new No(3);

    adj[2] = new No(0);
    adj[2]->prox = new No(4);
    adj[2]->prox->prox = new No(3);

    adj[3] = new No(1);
    adj[3]->prox = new No(5);
    adj[3]->prox->prox = new No(2);

    adj[4] = nullptr;

    adj[5] = new No(3);

    for (int i = 0; i < 6; i++) {
        cout << i << " -> ";
        No* atual = adj[i];
        while (atual != nullptr) {
            cout << atual->item << " ";
            atual = atual->prox;
        }
        cout << endl;
    }

    return 0;
}
