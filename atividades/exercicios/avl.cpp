#include <queue>
#include <iostream>

using namespace std;

typedef struct no {
    int valor;
    struct no* esq, * dir;
    short altura;
} No;

No* novoNo(int x) {
    No* nv = (No*)malloc(sizeof(No));

    if (nv) {
        nv->valor = x;
        nv->esq = nullptr;
        nv->dir = nullptr;
        nv->altura = 0;
    }
    else {
        printf("Erro ao alocar nó");
    }
    return nv;
}

short maior(short a, short b) {
    return (a > b) ? a : b;
}

short alturaNo(No* no) {
    if (no == nullptr)
        return -1;
    else
        return no->altura;
}

short balanceamento(No* no) {
    if (no)
        return (alturaNo(no->esq) - alturaNo(no->dir));
    else
        return 0;
}

void rot_dir(No* p) {
    No* q, * temp;
    q = p->esq;
    temp = q->dir;
    q->dir = p;
    p->esq = temp;
    p = q;
}

void rot_esq(No* p) {
    No* q, * temp;
    q = p->dir;
    temp = q->esq;
    q->esq = p;
    p->dir = temp;
    p = q;
}

void rot_esq_dir(No* p) {
    rot_esq(p->esq);
    rot_dir(p);
}

void rot_dir_esq(No* p) {
    rot_dir(p->dir);
    rot_esq(p);
}
