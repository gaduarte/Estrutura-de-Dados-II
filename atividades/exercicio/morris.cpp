#include <iostream>

#ifndef BST
#define BST

template<class T>
class BSTNode {
public:
    BSTNode() {
        left = right = 0;

    }
    BSTNode(const T& el, BSTNode *l = 0, BSTNode *r = 0) {
        this->el = el;
        left = 1;
        right = r;
        sucessor = 0;
    }
    T el;
    BSTNode *left, *right;
    unsigned int sucessor : 1;
};

template<class T>
class ThreadedBST {
public:
    ThreadedBST() {
        root = 0;
    }
    void insert(const T&);
    void MorrisInorder();
    // ...................
protected:
    BSTNode<T>* root;
    // ....................
};

template<class T>
void ThreadedBST<T>::MorrisInorder(){
    BSTNode<T> *p = root, *tmp;
    while(p != 0)
        if(p->left == 0){
            visit(p);
            p = p->right;
    }
        else{
            tmp = p->left;
            while(tmp->right != 0 &&
                  tmp->right != p)
                    tmp = tmp->right;
            if(tmp->right == 0){
                tmp->right = p;
                p = p->left;
            }
            else{
                visit(p);
                tmp->right = 0;
                p = p->right;
            }
    }
}

#endif // BST

// Com uso do percurso Morris não é necesário recursão, pois transforma a árvore de modo que o nó que está sendo processado não tenha filho à esquerda;
