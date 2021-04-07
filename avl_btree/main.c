#include "btree/btree.h"
#include "arvoreAvl/avlV3.h"
#define PIOR_CASO_IN "inputs//pior_caso.txt"
#define MEDIO_CASO_IN "inputs//medio_caso.txt"
#define PIOR_CASO_OUT_BTREE "outputs//pior_caso_out_btree.txt"
#define MEDIO_CASO_OUT_BTREE "outputs//medio_caso_out_btree.txt"
#define PIOR_CASO_OUT_AVL "outputs//pior_caso_out_avl.txt"
#define MEDIO_CASO_OUT_AVL "outputs//medio_caso_out_avl.txt"

//PIOR CASO -> valores ordenados, não necessita de 10 execuções para comprovar valdiade estatística
//MEDIO CASO -> valores aleatórios, necessita 10 execuções para validade estatística
void executaPiorCasoBtree();
void executaMedioCasoBtree();
void executaPiorCasoAvl();
void executaMedioCasoBtree();
void geraMedioCaso();

int main()
{
    //gcc.exe -Wall -g main.c arvoreAvl/avlV3.c btree/btree.c -o main.exe

    //PIOR CASO ->BTREE
    executaPiorCasoBtree();

    //MEDIO CASO -> BTREE
    //gerando chaves aleatórias
    geraMedioCaso();
    executaMedioCasoBtree();

    //PIOR CASO ->AVL
    executaPiorCasoAvl();
}

void geraMedioCaso()
{
    FILE *medio_caso_in;
    medio_caso_in = fopen(MEDIO_CASO_IN, "w");
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            fprintf(medio_caso_in, "%d\n", 1 + (rand() % 1000));
        }
    }
    fclose(medio_caso_in);
}

void executaPiorCasoAvl()
{

    char valor_str[4];
    AvlTree *arvoreAvl = criar();

    FILE *pior_caso_in = fopen(PIOR_CASO_IN, "r");
    FILE *pior_caso_out = fopen(PIOR_CASO_OUT_AVL, "w");

    while (fgets(valor_str, 4, pior_caso_in) != NULL)
    {
        printf("%d\n", atoi(valor_str));
        if (atoi(valor_str) != 0)
        {
            arvoreAvl->root = adiciona(arvoreAvl, arvoreAvl->root, atoi(valor_str));
            printf("%d \n", arvoreAvl->contador);
            fprintf(pior_caso_out, "%d\n", arvoreAvl->contador);
        }
    }
    fclose(pior_caso_out);
    fclose(pior_caso_in);
}

void executaPiorCasoBtree()
{
    //PIOR_CASO -> BTREE
    char valor_str[4];
    //char tam[4];
    ArvoreB *arvoreB = criaArvore(5);

    FILE *pior_caso_in; //input
    pior_caso_in = fopen(PIOR_CASO_IN, "r");

    FILE *pior_caso_out_btree; //output
    pior_caso_out_btree = fopen(PIOR_CASO_OUT_BTREE, "w");

    while (fgets(valor_str, 4, pior_caso_in) != NULL)
    {
        //printf("%d", atoi(valor_str));
        if (atoi(valor_str) != 0)
        {
            adicionaChave(arvoreB, atoi(valor_str));
            fprintf(pior_caso_out_btree, "%d\n", arvoreB->contador);
        }
    }
    fclose(pior_caso_in);
    fclose(pior_caso_out_btree);
    //percorreArvore(arvoreB->raiz);
    printf("Operacoes Pior Caso Btree: %d", arvoreB->contador);
    printf("\n");
}

void executaMedioCasoBtree()
{
    ArvoreB *arvore1 = criaArvore(5);
    ArvoreB *arvore2 = criaArvore(5);
    ArvoreB *arvore3 = criaArvore(5);
    ArvoreB *arvore4 = criaArvore(5);
    ArvoreB *arvore5 = criaArvore(5);
    ArvoreB *arvore6 = criaArvore(5);
    ArvoreB *arvore7 = criaArvore(5);
    ArvoreB *arvore8 = criaArvore(5);
    ArvoreB *arvore9 = criaArvore(5);
    ArvoreB *arvore10 = criaArvore(5);

    char valor_str[4];
    int linha = 1;

    FILE *medio_caso_in;
    medio_caso_in = fopen(MEDIO_CASO_IN, "r");

    FILE *medio_caso_out_btree = fopen(MEDIO_CASO_OUT_BTREE, "w");

    /*
    FILE *medio_caso_out_btree1 = fopen("medio_caso_btree1", "w");
    FILE *medio_caso_out_btree2 = fopen("medio_caso_btree2", "w");
    FILE *medio_caso_out_btree3 = fopen("medio_caso_btree3", "w");
    FILE *medio_caso_out_btree4 = fopen("medio_caso_btree4", "w");
    FILE *medio_caso_out_btree5 = fopen("medio_caso_btree5", "w");
    FILE *medio_caso_out_btree6 = fopen("medio_caso_btree6", "w");
    FILE *medio_caso_out_btree7 = fopen("medio_caso_btree7", "w");
    FILE *medio_caso_out_btree8 = fopen("medio_caso_btree8", "w");
    FILE *medio_caso_out_btree9 = fopen("medio_caso_btree9", "w");
    FILE *medio_caso_out_btree10 = fopen("medio_caso_btree10", "w");
    */

    while (fgets(valor_str, 4, medio_caso_in) != NULL)
    {
        if (atoi(valor_str) != 0)
        {
            if (linha <= 100)
            {
                adicionaChave(arvore1, atoi(valor_str));
                fprintf(medio_caso_out_btree, "1, %d \n", arvore1->contador);
            }
            if (linha <= 200 && linha > 100)
            {
                adicionaChave(arvore2, atoi(valor_str));
                fprintf(medio_caso_out_btree, "2, %d \n", arvore2->contador);
            }
            if (linha <= 300 && linha > 200)
            {
                adicionaChave(arvore3, atoi(valor_str));
                fprintf(medio_caso_out_btree, "3, %d \n", arvore3->contador);
            }
            if (linha <= 400 && linha > 300)
            {
                adicionaChave(arvore4, atoi(valor_str));
                fprintf(medio_caso_out_btree, "4, %d \n", arvore4->contador);
            }
            if (linha <= 500 && linha > 400)
            {
                adicionaChave(arvore5, atoi(valor_str));
                fprintf(medio_caso_out_btree, "5, %d \n", arvore5->contador);
            }
            if (linha <= 600 && linha > 500)
            {
                adicionaChave(arvore6, atoi(valor_str));
                fprintf(medio_caso_out_btree, "6, %d \n", arvore6->contador);
            }
            if (linha <= 700 && linha > 600)
            {
                adicionaChave(arvore7, atoi(valor_str));
                fprintf(medio_caso_out_btree, "7, %d \n", arvore7->contador);
            }
            if (linha <= 800 && linha > 700)
            {
                adicionaChave(arvore8, atoi(valor_str));
                fprintf(medio_caso_out_btree, "8, %d \n", arvore8->contador);
            }
            if (linha <= 900 && linha > 800)
            {
                adicionaChave(arvore9, atoi(valor_str));
                fprintf(medio_caso_out_btree, "9, %d \n", arvore9->contador);
            }
            if (linha <= 1000 && linha > 900)
            {
                adicionaChave(arvore10, atoi(valor_str));
                fprintf(medio_caso_out_btree, "10, %d \n", arvore10->contador);
            }
            linha++;
        }
    }
}
