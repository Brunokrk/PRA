#include <stdio.h>
#include <stdlib.h>

int maiorSoma(int *array, int tam);

int main(){
    int vetor[4]= {5,1,1,5};  
    int tam = 4;

    printf("%d", maiorSoma(vetor, tam));
}

int maiorSoma(int *array, int tam){
    int resultado =0;

    for(int i=0; i<tam; i++){
        resultado += *(array +i);
    }
    if(tam >1){
        int max =0;
        max = resultado - *(array +1);
        
        for(int i =1; i<tam-1; i++){
            if(resultado - *(array +i -1) - *(array +i+1) > max){
                max = resultado - *(array +i -1) - *(array +i +1);
            }
        }
        if(resultado - *(array + tam-2)>max){
            max = resultado-(*array + tam-2);
        }
        return max;
    }
    return resultado;
}