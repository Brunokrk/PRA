#include <stdio.h>
#include <stdlib.h>
int* BubleSort(int *vetor);
int main()
{
    int vetor[4] = {3, 4, -1, 1};
    int i, *aux;

    aux = BubleSort(vetor);



    for (i = 0; i < 4; i++)
    {
        printf("%d", aux[i]);
    }
}

/* 
int checking(int *vetor){
    int i;

    for(i=0; i<4; i++){
        if(((vetor[i]-1)>0)){
            return
        }
    } 
} */

int *BubleSort(int *vetor)
{
    int i, j, aux;

    for (j = 3; j >= 1; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
    return vetor;
}