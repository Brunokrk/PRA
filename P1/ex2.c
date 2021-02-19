#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **Aloca_Matriz(int lines, int columns);
int Imprime_Matriz(int **Matriz, int lines, int columns);
void pontuaMatriz(int **matriz, int lines, int columns, const char *str1, const char *str2);

int main(){

    int **matriz;
    const char word1[] = "benyam";
    const char word2[] = "ephrem";
    matriz = Aloca_Matriz(strlen(word1)+1, strlen(word2)+1);
    pontuaMatriz(matriz, strlen(word1)+1, strlen(word2)+1, word1, word2);
    Imprime_Matriz(matriz, strlen(word1)+1, strlen(word2)+1 );

}

int **Aloca_Matriz(int lines, int columns)
{
    int **matriz;
    int i;
    matriz = (int **)malloc(lines * sizeof(int *));
    if (matriz == NULL)
    {
        printf("ERROR::Matriz nao alocada");
    }
    for (i = 0; i < columns; i++)
    {
        matriz[i] = (int *)malloc(columns * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("ERROR::Memoria insuficiente para concluir alocação Dinamica");
        }
    }
    printf("Matriz Alocada com Sucesso!\n");
    return matriz;
}

int Imprime_Matriz(int **Matriz, int lines, int columns)
{
    int i, j;
    for (i = 0; i < lines; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("[%d] ", Matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void iniciaMatriz(int **matriz, int lines, int columns){
    for(int i=0; i<lines; i++){
        matriz[i][0] = i;
    }
    for(int j=0; j<columns; j++){
        matriz[0][j] = j;
    }
}

int identificaMenorCusto(int esq, int cima, int dsEsq){
    if (esq < cima && esq < dsEsq) {
        return esq;
    }
    if (cima < esq && cima < dsEsq) {
        return cima;
    }
    return dsEsq;
}

void pontuaMatriz(int **matriz, int lines, int columns, const char *str1, const char *str2){
    int custo = 0, menorCusto = 0;
    iniciaMatriz(matriz, lines, columns);
    for(int i = 1; i<lines; i++){
        for(int j = 1; j<columns; j++){
            if(str1[j-1] == str2[i-1]){
                custo = 0;
            }else{
                custo = 1;
            }
            menorCusto = identificaMenorCusto(matriz[i][j-1], matriz[i-1][j], matriz[i-1][j-1]);
            matriz[i][j] = menorCusto + custo;
        }
    }
}