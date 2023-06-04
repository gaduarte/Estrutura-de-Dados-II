/*
1.1 - Altura = 3
1.2 - Árvore Resultante:         7
                                /  \
                               6    22
                                   /   \
                                  14    40
                                          \
                                            63
1.3 - A árvore não está balanceada.
1.6
*/

//1.4
#include <iostream>
#include <cmath>
#include <vector>
#ifndef THREADED_TREE
#define THREADED_TREE

template<class T>
class ThreadedNode {
public:
    ThreadedNode() {
        left = right = 0;

    }
    ThreadedNode(const T& el, ThreadedNode *l = 0, ThreadedNode *r = 0) {
        this->el = el;
        left = l;
        right = r;
        sucessor = 0;
    }
    T el;
    ThreadedNode *left, *right;
    unsigned int sucessor : 1;
};


template<class T>
class ThreadedTree {
public:
    ThreadedTree() {
        root = 0;
    }
    void insert(const T&);
    bool contains(const T&);
    void inorder();
    void preorder();
    void BubbleSort(T* vetor, int tamanho);
    void balancear();
    

    // ...................
private:
    ThreadedNode<T>* root;
  
    void rotateLeft(ThreadedNode<T>* node);
    void rotateRight(ThreadedNode<T>* node);
    

    // ....................

};

template<class T>
bool ThreadedTree<T>::contains(const T& value) {
    ThreadedNode<T>* current = root;

    while (current != nullptr) {
        if (value == current->el) {
            return true;
        } else if (value < current->el) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}


template<class T>
void ThreadedTree<T>::insert(const T& p) {
    ThreadedNode<T>* newNode = new ThreadedNode<T>(p);
    if(contains(p)){
        return;
    }
    if (root == nullptr) {
        root = newNode;
    }
    else {
        ThreadedNode<T>* curr = root;
        while (true) {
            if (p < curr->el) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    newNode->right = curr;
                    newNode->sucessor = 1;
                    break;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == nullptr) {
                    newNode->right = curr->right;
                    curr->right = newNode;
                    curr->sucessor = 0;
                    break;
                } else{
                    curr = curr->right;
                }

            }
        }
    }
}



template<class T>
void ThreadedTree<T>::inorder(){
    ThreadedNode<T>* prev, *p = root;
    if (p != 0){
        while (p->left != 0)
            p = p->left;
        while (p != 0){
            std::cout << p->el << " ";
            prev = p;
            p = p->right;
            if (p != 0 && prev->sucessor == 0)
                while (p->left != 0)
                    p = p->left;
        }
    }
}


template<class T>
void ThreadedTree<T>::preorder(){
    ThreadedNode<T>* p = root;

    while (p != 0){
            std::cout << p->el << " ";
            if(p->left != 0){
                p = p->left;
            } else if(p->right != 0 && !p->sucessor){
                p = p->right;
            } else {
                while(p->right != 0 && p->sucessor){
                    p = p->right;
                }
                if(p->right != 0){
                    p = p->right;
                } else {
                    break;
                }
            }

    }

}

template<class T>
void ThreadedTree<T>::rotateLeft() {
    ThreadedNode<T>* temp = p;
    ThreadedNode<T>* par = temp->left;
    ThreadedNode<T>* prox = par->right;
    ThreadedNode<T>* subD;
    par = tmp->left;

    tmp->left = prox;
    subD = prox->left;
    par->right = subD;
    prox->left = par;
}

template<class T>
void ThreadedTree<T>::rotateRight() {
    ThreadedNode<T>* temp = p;
    ThreadedNode<T>* par = temp->right;
    ThreadedNode<T>* prox = par->left;
    ThreadedNode<T>* subD;
    par = tmp->right;

    tmp->right = prox;
    subD = prox->right;
    par->left = subD;
    prox->right = par;
}

template<class T>
void ThreadedTree<T>::balancear(T vetor[], int first, int last){
    if(first<=last){
        int middle = (first + last)/2;
        insert(vetor[middle]);
        balancear(vetor, first, middle-1);
        balancear(vetor,middle+1,last);
    }
}

template<class T>
void ThreadedTree<T>::BubbleSort(T vetor[], int tamanho) {
    bool trocou;
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                T temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }
}

#endif // THREADED_TREE

int main() {
    ThreadedTree<int> *tree = new ThreadedTree<int>();

    tree->insert(7);
    tree->insert(6);
    tree->insert(22);
    tree->insert(14);
    tree->insert(40);
    tree->insert(63);

    tree->inorder();
    std::cout << std::endl;

    tree->preorder();
    std::cout << std::endl;

    tree->balancear();

    tree->inorder();
    std::cout << std::endl;

    return 0;
}
