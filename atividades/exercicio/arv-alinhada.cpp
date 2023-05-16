#include <iostream>
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
        left = 1;
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
    void inorder();
    void preorder();
    // ...................
protected:
    ThreadedNode<T>* root;
    // ....................
};

template<class T>
void ThreadedTree<T>::inorder(){
    ThreadedNode<T> *prev, *p = root;
    if(p != 0){
        while (p->left != 0)
            p = p->left;
        while (p != 0){
            visit(p);
            prev = p;
            p =p->right;
            if(p != 0 && prev->sucessor == 0)
                while(p->left != 0)
                    p = p->left;

        }
    }
}


template<class T>
void ThreadedTree<T>::preorder(){
    ThreadedNode<T> *p = root;

    while (p != 0){
            visit(p);
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

#endif // THREADED_TREE
