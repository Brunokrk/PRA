#include "btree/btree.h"


//PIOR CASO -> valores ordenados
//MEDIO CASO -> valores aleatórios

int main()
{
    ArvoreB *arvoreB = criaArvore(1);

    adicionaChave(arvoreB, 9);
    adicionaChave(arvoreB, 3);
    adicionaChave(arvoreB, 11);
    adicionaChave(arvoreB, 7);
    adicionaChave(arvoreB, 8);
    adicionaChave(arvoreB, 5);
    adicionaChave(arvoreB, 1);

    percorreArvore(arvoreB->raiz);
    printf("\n");
}