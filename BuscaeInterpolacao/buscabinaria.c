#include <stdio.h>

#define BINARIA 0
#define INTERPOLACAO 1

int pesquisa (int chave, int v[], int n, int tipo){
    int ini = 0, meio, fim = n-1;
    int cont = 0;

    while(ini <= fim){
        meio = tipo == BINARIA ? (ini + fim)/2 : ini + ((fim - ini) * (chave - v[ini])) / (v[fim] - v[ini]);

        if(chave < v[meio]){
            fim = meio -1;
        }else if{
            //continuação na prox aula
        }
    }
}

void compara(int chave, int v[], int n){
    printf("{");

    for(int i =0; i<n; i++){
        printf(" %d", v[i]);
    }

    printf("} -> %d\n", chave);

    printf("Binária: %d iterações\n", pesquisa(chave, v, n, BINARIA));
    printf("Interpolacao: %d iterações\n", pesquisa(chave, v, n, INTERPOLACAO));
}

int main(){
    compara(100, (int[]), {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 10);
    compara(11, (int[]), {1, 2, 4, 7, 11, 16, 22, 29, 37, 46}, 10);
}