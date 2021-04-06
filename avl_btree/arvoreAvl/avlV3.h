#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int altura;
} Node;

typedef struct AvlTree
{
    struct Node *root;
    int contador;
} AvlTree;

//Prototipos
int max(int, int);
int altura(Node *);
AvlTree *criar();
Node *newNode(int);
Node *rightRotate(AvlTree *, Node *);
Node *leftRotate(AvlTree *, Node *);
int fatorBalanceamento(Node *);
Node *adiciona(AvlTree *, Node *n, int);
void preOrder(Node *);