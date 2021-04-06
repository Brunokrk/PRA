#include "btree/btree.h"
#define PIOR_CASO_IN "inputs//pior_caso.txt"
#define PIOR_CASO_OUT "outputs//pior_caso_out_btree.txt"
#define SEPARATOR ", "

//PIOR CASO -> valores ordenados, não necessita de 10 execuções para comprovar valdiade estatística
//MEDIO CASO -> valores aleatórios, necessita 10 execuções para validade estatística

int main()
{
    
    //PIOR_CASO -> BTREE
    char valor_str[4];
    //char tam[4];
    ArvoreB *arvoreB = criaArvore(1);

    FILE *pior_caso_in;//input
    pior_caso_in = fopen(PIOR_CASO_IN, "r");
    
    FILE *pior_caso_out_btree;//output
    pior_caso_out_btree = fopen(PIOR_CASO_OUT,"w");

    while (fgets(valor_str, 4, pior_caso_in) != NULL)
    {
        //printf("%d", atoi(valor_str));
        if(atoi(valor_str)!=0){
            adicionaChave(arvoreB,atoi(valor_str));
            fprintf(pior_caso_out_btree,"%d \n", arvoreB->contador);
        }
    }

    fclose(pior_caso_in);
    fclose(pior_caso_out_btree);
    //percorreArvore(arvoreB->raiz);
    printf("Operacoes: %d", arvoreB->contador);
    printf("\n");
}