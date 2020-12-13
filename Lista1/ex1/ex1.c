#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool checker(int *vetor, int n, int k);

int main(){
    int n, k;
    int vetor[n];
    int i;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Informe a chave: ");
    scanf("%d", &k);
    checker(vetor, n, k);
}

bool checker(int *vetor, int n, int k){
    int i, j;
    for(i=0; i<n; i++){
        for(j=1; j<n; j++){
            if((vetor[i]+vetor[j])==k){
                printf("%d + %d = %d", vetor[i], vetor[j], k);
                return true;
            }
        }
    }
    return false;
}