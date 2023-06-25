#include <iostream>
#include <vector>

using namespace std;

struct No {
    int item;
    No* prox;

    No(int valor) {
        item = valor;
        prox = nullptr;
    }
};

void dfs(int u, int destino, No* adj[], vector<bool>& visitado, vector<int>& caminho) {
    visitado[u] = true;
    caminho.push_back(u);

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
            if (!visitado[v]) {
                dfs(v, destino, adj, visitado, caminho);
            }
            percorre = percorre->prox;
        }
    }

    visitado[u] = false;
    caminho.pop_back();
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

    vector<bool> visitado(6, false);
    vector<int> caminho;

    cout << "Caminhos encontrados:\n";
    dfs(origem, destino, adj, visitado, caminho);

    return 0;
}
