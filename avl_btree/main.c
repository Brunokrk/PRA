#include "btree/btree.h"
#define PIOR_CASO "arqs//pior_caso.txt"

//PIOR CASO -> valores ordenados
//MEDIO CASO -> valores aleatórios

int main()
{
    char valor_str[4];
    ArvoreB *arvoreB = criaArvore(1);
    FILE *pior_caso;
    pior_caso = fopen(PIOR_CASO, "r+");

    while (fgets(valor_str, 4, pior_caso) != NULL)
    {
        //printf("%d", atoi(valor_str));
        if(atoi(valor_str)!=0){
            adicionaChave(arvoreB,atoi(valor_str) );
        }
    }

    fclose(pior_caso);
    percorreArvore(arvoreB->raiz);
    printf("Operacoes: %d", arvoreB->contador);
    printf("\n");
}