// Resultado: 10 5 3 7 20 15 24
/*
O algorítmo verifica se possui filhos à esquerda, se possuir vai apontar para mesma 
depois vai verificar se possui filhos à direita, se não possuir ele imprime p e segue o percurso.
*/

#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode* left;
    struct tNode* right;
};

void Morris(struct tNode* root){
    struct tNode *cur, *pre;

    if(root == NULL)
        return;
    cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            printf("%d", cur->data);
            cur = cur->right;
        }
        else{
            pre = cur->left;
            while(pre->right != NULL && pre->right != cur)
                pre = pre->right;

            if(pre->right == NULL){
                printf("%d", cur->data);
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }
}

struct tNode* newtNode(int data){
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
};

int main(){
    struct tNode* root = newtNode(10);
    root->left = newtNode(5);
    root->right = newtNode(20);
    root->right->left = newtNode(15);
    root->right->right = newtNode(24);
    root->left->left = newtNode(3);
    root->left->right = newtNode(7);

    Morris(root);

    return 0;
}
