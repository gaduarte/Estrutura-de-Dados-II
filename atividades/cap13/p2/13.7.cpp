#include<stdio.h>
#include<stdlib.h>
#include<iostream>

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

int igual(NoArv* a, NoArv* b){
    if(vazia(a) && vazia(b))
        return 1;
    if(!vazia(a) && !vazia(b)){
        return((a->info==b->info) && igual(a->esq,b->esq) && (a->dir,b->dir));
    }
    if(vazia(a) || vazia(b))
        return 0;
}

int main(){
    NoArv* a1 = arv_cria(2,cria_vazia(),cria_vazia());
    NoArv* b1 = arv_cria(1,cria_vazia(),cria_vazia());
    int compara = compara(a1,b1);
        if(compara){
        cout<<"iguais";
    } else{
        cout<<"diferentes";
    }
}
