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
void BST<T>::MorrisInorder(){
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

template<class T>
void ThreadedBST<T>::MorrisPreorder(){
    BSTNode<T> *p=root, *tmp;
    while (p!=0){
        if (p->left==0){
            visit(p);
            p=p->right;
        }
        else{
            tmp = p->left;
            while (tmp->right!= 0 && tmp->right!=p)
                tmp=tmp->right;
                if (tmp->right== p){
                    tmp->right= nullptr;
                    p = p->right;
                }
                else{
                    visit(p);
                    tmp->right = p;
                    p = p->left;
                }
                }
        }
}


#endif // THREADED_TREE
