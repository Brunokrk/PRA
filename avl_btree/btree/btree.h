#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct no
{
    int total;
    int *chaves;
    struct no **filhos;
    struct no *pai;
} No;

typedef struct arvoreB
{
    No *raiz;
    int ordem;
    int contador;
} ArvoreB;

ArvoreB *criaArvore(int);
No *criaNo(ArvoreB *);
void percorreArvore(No *);
int pesquisaBinaria(ArvoreB *arvore, No *, int);
int localizaChave(ArvoreB *, int);
No *localizaNo(ArvoreB *, int);
void adicionaChaveNo(ArvoreB *, No *, No *, int);
int transbordo(ArvoreB *, No *);
No *divideNo(ArvoreB *, No *);
void adicionaChaveRecursivo(ArvoreB *, No *, No *, int);
void adicionaChave(ArvoreB *, int);
void excluiNo(No*, int);
void excluiBtree(ArvoreB *);