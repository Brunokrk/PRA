#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[5]= {1, 2, 3, 4, 5};
    int i, j, prod=1;
    int new_vet[5];

    for(i=0; i<5;i++){
        for(j=0;j<5;j++){
            if(i!=j){
                prod = prod * vetor[j];
                new_vet[i] = prod;
            }
        }
        prod = 1;
    }
    for(i=0; i<5;i++) printf("%d ", new_vet[i]);
}