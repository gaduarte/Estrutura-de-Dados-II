#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

struct No {
    int item;
    No* prox;

    No(int valor) {
        item = valor;
        prox = nullptr;
    }
};

void bfs(int origem, int destino, No* adj[]) {
    queue<vector<int>> fila;
    vector<int> caminho;
    caminho.push_back(origem);
    fila.push(caminho);

    while (!fila.empty()) {
        caminho = fila.front();
        fila.pop();

        int u = caminho.back();
        if (u == destino) {
            cout << "Caminho encontrado: ";
            for (int i = 0; i < caminho.size(); i++) {
                cout << caminho[i] << " ";
            }
            cout << endl;
        } else {
            No* percorre = adj[u];
            while (percorre != nullptr) {
                int v = percorre->item;
                if (find(caminho.begin(), caminho.end(), v) == caminho.end()) {
                    vector<int> novo_caminho = caminho;
                    novo_caminho.push_back(v);
                    fila.push(novo_caminho);
                }
                percorre = percorre->prox;
            }
        }
    }
}

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

    int origem = 0;
    int destino = 5;

    cout << "Caminhos encontrados:\n";
    bfs(origem, destino, adj);

    return 0;
}
