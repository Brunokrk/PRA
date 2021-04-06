#include "btree/btree.h"

//PIOR CASO -> valores ordenados
//MEDIO CASO -> valores aleatórios

int main()
{
    ArvoreB *arvoreB = criaArvore(1);

    percorreArvore(arvoreB->raiz);
    printf("Operacoes: %d", arvoreB->contador);
    printf("\n");
    
}