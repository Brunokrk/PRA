#include "node.h"

Arvore * criar(){
    Arvore *avl = (Arvore*)malloc(sizeof(Arvore));
    avl->raiz = NULL;
    return avl;
}

int alturaDoNo(No* no){
    int esquerda=0 , direita=0;

    if(no->esquerda!=NULL){
        esquerda = alturaDoNo(no->esquerda) + 1;
    }
    
    if(no->direita!=NULL){
        direita = alturaDoNo(no->direita)+1;
    }

    return(esquerda > direita ? esquerda : direita);
}

int fatorBalanceamento(No* no){
    int esquerda = 0, direita = 0;

    if(no->esquerda != NULL){
        esquerda = alturaDoNo(no->esquerda)+1;
    }
    if(no->direita != NULL){
        direita = alturaDoNo(no->direita) + 1;
    }

    return esquerda - direita;
}

No* adicionar(Arvore* arvore, No* pai, int valor) {
    No *no = (No*) malloc(sizeof(No));

    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->value = valor;
  
    if (pai == NULL) {
        //Se não existir Pai, é raiz
        arvore->raiz = no;
    }

    return no;
}

No* rse(Arvore* av ,No* no){
    //lado direito do nó está mais alto
    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai=direita;

    direita->esquerda = no;
    direita->pai = pai;

    return direita;

}

