#include "btree/btree.h"
#include "arvoreAvl/avlV3.h"
#define PIOR_CASO_IN "inputs//pior_caso.txt"
#define MEDIO_CASO_IN "inputs//medio_caso.txt"
#define PIOR_CASO_OUT_BTREE "outputs//pior_caso_out_btree.txt"
#define MEDIO_CASO_OUT_BTREE "outputs//medio_caso_out_btree.txt"
#define PIOR_CASO_OUT_AVL "outputs//pior_caso_out_avl.txt"
#define MEDIO_CASO_OUT_AVL "outputs//medio_caso_out_avl.txt"
#define ORDEM 10

//PIOR CASO -> valores ordenados, não necessita de 10 execuções para comprovar valdiade estatística
//MEDIO CASO -> valores aleatórios, necessita 10 execuções para validade estatística
void executaPiorCasoBtree();
void executaMedioCasoBtree();
void executaPiorCasoAvl();
void executaMedioCasoAvl();
void geraMedioCaso();

int main()
{
    //gcc.exe -Wall -g main.c arvoreAvl/avlV3.c btree/btree.c -o main.exe
    geraMedioCaso();
    //pior caso gerado por script python ->gambiarra infeliz

    //PIOR CASO ->BTREE
    executaPiorCasoBtree();

    //MEDIO CASO -> BTREE
    executaMedioCasoBtree();

    //PIOR CASO ->AVL
    executaPiorCasoAvl();

    //MEDIO CASO -> AVL
    executaMedioCasoAvl();

    printf("DADOS GERADOS, EXECUTAR SCRIPT PYTHON PARA GERAR GRÁFICOS");
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
        //printf("%d\n", atoi(valor_str));
        if (atoi(valor_str) != 0)
        {
            arvoreAvl->root = adiciona(arvoreAvl, arvoreAvl->root, atoi(valor_str));
            //printf("%d \n", arvoreAvl->contador);
            fprintf(pior_caso_out, "%d\n", arvoreAvl->contador);
        }
    }

    fclose(pior_caso_out);
    fclose(pior_caso_in);
}

void executaMedioCasoAvl()
{
    FILE *medio_caso_in = fopen(MEDIO_CASO_IN, "r");
    FILE *medio_caso_out = fopen(MEDIO_CASO_OUT_AVL, "w");
    int linha = 1;
    char valor_str[4];

    AvlTree *arvoreAvl1 = criar();
    AvlTree *arvoreAvl2 = criar();
    AvlTree *arvoreAvl3 = criar();
    AvlTree *arvoreAvl4 = criar();
    AvlTree *arvoreAvl5 = criar();
    AvlTree *arvoreAvl6 = criar();
    AvlTree *arvoreAvl7 = criar();
    AvlTree *arvoreAvl8 = criar();
    AvlTree *arvoreAvl9 = criar();
    AvlTree *arvoreAvl10 = criar();

    while (fgets(valor_str, 4, medio_caso_in) != NULL)
    {
        if (atoi(valor_str) != 0)
        {
            if (linha <= 100)
            {
                arvoreAvl1->root = adiciona(arvoreAvl1, arvoreAvl1->root, atoi(valor_str));
                fprintf(medio_caso_out, "1, %d \n", arvoreAvl1->contador);
            }
            if (linha <= 200 && linha > 100)
            {
                arvoreAvl2->root = adiciona(arvoreAvl2, arvoreAvl2->root, atoi(valor_str));
                fprintf(medio_caso_out, "2, %d \n", arvoreAvl2->contador);
            }
            if (linha <= 300 && linha > 200)
            {
                arvoreAvl3->root = adiciona(arvoreAvl3, arvoreAvl3->root, atoi(valor_str));
                fprintf(medio_caso_out, "3, %d \n", arvoreAvl3->contador);
            }
            if (linha <= 400 && linha > 300)
            {
                arvoreAvl4->root = adiciona(arvoreAvl4, arvoreAvl4->root, atoi(valor_str));
                fprintf(medio_caso_out, "4, %d \n", arvoreAvl4->contador);
            }
            if (linha <= 500 && linha > 400)
            {
                arvoreAvl5->root = adiciona(arvoreAvl5, arvoreAvl5->root, atoi(valor_str));
                fprintf(medio_caso_out, "5, %d \n", arvoreAvl5->contador);
            }
            if (linha <= 600 && linha > 500)
            {
                arvoreAvl6->root = adiciona(arvoreAvl6, arvoreAvl6->root, atoi(valor_str));
                fprintf(medio_caso_out, "6, %d \n", arvoreAvl6->contador);
            }
            if (linha <= 700 && linha > 600)
            {
                arvoreAvl7->root = adiciona(arvoreAvl7, arvoreAvl7->root, atoi(valor_str));
                fprintf(medio_caso_out, "7, %d \n", arvoreAvl7->contador);
            }
            if (linha <= 800 && linha > 700)
            {
                arvoreAvl8->root = adiciona(arvoreAvl8, arvoreAvl8->root, atoi(valor_str));
                fprintf(medio_caso_out, "8, %d \n", arvoreAvl8->contador);
            }
            if (linha <= 900 && linha > 800)
            {
                arvoreAvl9->root = adiciona(arvoreAvl9, arvoreAvl9->root, atoi(valor_str));
                fprintf(medio_caso_out, "9, %d \n", arvoreAvl9->contador);
            }
            if (linha <= 1000 && linha > 900)
            {
                arvoreAvl10->root = adiciona(arvoreAvl10, arvoreAvl10->root, atoi(valor_str));
                fprintf(medio_caso_out, "10, %d \n", arvoreAvl10->contador);
            }
            linha++;
        }
    }
    fclose(medio_caso_in);
    fclose(medio_caso_out);
}

void executaPiorCasoBtree()
{
    //PIOR_CASO -> BTREE
    char valor_str[4];
    //char tam[4];
    ArvoreB *arvoreB = criaArvore(ORDEM);

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
    //printf("Operacoes Pior Caso Btree: %d", arvoreB->contador);
    //printf("\n");
}

void executaMedioCasoBtree()
{
    ArvoreB *arvore1 = criaArvore(ORDEM);
    ArvoreB *arvore2 = criaArvore(ORDEM);
    ArvoreB *arvore3 = criaArvore(ORDEM);
    ArvoreB *arvore4 = criaArvore(ORDEM);
    ArvoreB *arvore5 = criaArvore(ORDEM);
    ArvoreB *arvore6 = criaArvore(ORDEM);
    ArvoreB *arvore7 = criaArvore(ORDEM);
    ArvoreB *arvore8 = criaArvore(ORDEM);
    ArvoreB *arvore9 = criaArvore(ORDEM);
    ArvoreB *arvore10 = criaArvore(ORDEM);

    char valor_str[4];
    int linha = 1;

    FILE *medio_caso_in;
    medio_caso_in = fopen(MEDIO_CASO_IN, "r");

    FILE *medio_caso_out_btree = fopen(MEDIO_CASO_OUT_BTREE, "w");

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
    fclose(medio_caso_in);
    fclose(medio_caso_out_btree);
}
