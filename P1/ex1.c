#include <stdio.h>
#include <stdlib.h>
int fezPar(int j, int vet[]);
void addLuva(int j);
void printVet();
int vetAux[] = {-1, -1, -1, -1, -1, -1, -1, -1};
int main()
{
    int vet[] = {6, 5, 2, 3, 5, 2, 2, 1}; //vetor de luvas
    int contPares;

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if (vet[j] == vet[i] && fezPar(i, vetAux) == 0)
            {
                addLuva(i);
                addLuva(j);
                contPares++;
            }
        }
    }
    printf("%d", contPares);
}

int fezPar(int j, int vet[])
{
    for (int i = 0; i < 8; i++)
    {
        if (vet[i] == j)
        {
            return 1;
        }
    }
    return 0;
}

void addLuva(int j)
{
    for (int i = 0; i < 8; i++)
    {
        if (vetAux[i] == -1)
        {
            vetAux[i] = j;
            break;
        }
    }
}