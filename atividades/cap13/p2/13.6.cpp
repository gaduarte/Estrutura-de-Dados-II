#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define fmt "%d"

using namespace std;

struct noArv{
    int info;
    struct noArv* esq;
    struct noArv* dir;
};
typedef struct noArv NoArv;

NoArv* cria_vazia(void){
    return NULL;
}
NoArv* arv_cria(int c,NoArv* sae,NoArv* sad){
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(NoArv* a){
    return a == NULL;
}

void emordem (NoArv* a){
    if (a == NULL) return;
    emordem(a->esq);
    printf(fmt, a->info);
    emordem(a->dir);
}

void preordem(NoArv* a){
    printf(fmt, a->info);
    preordem(a->esq);
    preordem(a->dir);
}

void posordem(NoArv* a){
    posordem(a->esq);
    posordem(a->dir);
    printf(fmt, a->info);
}

int arv_binaria(NoArv* arv){
    if(vazia(arv)){
        return 0;
    }
    else{
        int esquerda = arv_binaria(arv->esq);
        int direita = arv_binaria(arv->dir);
        if(esquerda == direita)return 1;
    }
}

int main(){
    NoArv* a1 = arv_cria(2,cria_vazia(),cria_vazia());
    NoArv* a2 = arv_cria(1,cria_vazia(),a1);
    NoArv* a3 = arv_cria(4,cria_vazia(),cria_vazia());
    NoArv* a4 = arv_cria(3,a2,a3);
    int bin = arv_binaria(a4);
    cout<<bin;
}
