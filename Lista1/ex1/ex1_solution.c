#include <stdio.h>
#include <stdlib.h>


int soma(int vetor[], int tamanho, int k){ // O(2*(N log N))
    
    mergesort(vetor, tamanho);//O(N log N)

    for(int i=0; i<tamanho-1; i++){
        int j = pesquisabinaria(vetor, tamanho, k-vetor[i]);
    
        if (j!= i && j!=-1){
            return 1;
        }
        return 0;
    }
}