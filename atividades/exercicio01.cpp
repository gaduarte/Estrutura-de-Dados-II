#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int Item;
typedef struct arv{
    struct arv* esq;
    Item item;
    struct arv* dir;
} *Arv;

Arv arv_cria(Arv e, Item x, Arv d){
        Arv n = (Arv)malloc(sizeof(struct arv));
        n->esq = e;
        n->item = x;
        n->dir = d;
        return n;
}
Arv arv_vazia(void){
    return NULL;
}

int vazia(Arv a){
    return a == NULL;
}

void arv_imprime(Arv a){
    if(!vazia(a)){
        cout<<"<"<<a->item;
        arv_imprime(a->esq);
        arv_imprime(a->dir);
        cout<<">";
    }
    else
        cout<<"<>";
}

int main(){
    Arv arv2 = arv_vazia();
    arv2 = arv_cria(arv2,2,arv_vazia());
    arv2 = arv_cria(arv2,1,arv_cria(arv2,3,arv_vazia()));
    arv2 = arv_cria(arv2,4,arv_vazia());
    arv_imprime(arv2);
}
