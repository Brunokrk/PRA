#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int value;
}No;

typedef struct arvore{
    struct no* raiz;
}Arvore;


int alturaDoNo(No*);
int fatoraBalanceamento(No*);
No* rse(Arvore*, No*);
No*rsd(Arvore*, No*);
No* rdd(Arvore*, No*);
No* rde(Arvore*, No*);