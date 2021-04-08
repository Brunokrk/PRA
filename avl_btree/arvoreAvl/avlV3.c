//Bruno Marchi Pires
//Árvore AVL, código base retirado do Site "GeeksForGeeks"
//Remoção de nodos não foi implementada, visto que não é objetivo o cálculo desta operação
#include "avlV3.h"

int altura(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AvlTree *criar()
{
    struct AvlTree *a = malloc(sizeof(AvlTree));
    a->root = NULL;
    a->contador = 0;
    return a;
}

Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->altura = 1;
    return (node);
}

struct Node *rightRotate(AvlTree *A, struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //rotação
    x->right = y;
    y->left = T2;

    //alturas atualizadas
    y->altura = max(altura(y->left), altura(y->right)) + 1;
    x->altura = max(altura(x->left), altura(x->right)) + 1;

    //nova raiz
    return x;
}

struct Node *leftRotate(AvlTree *A, struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    //alturas atualizadas
    x->altura = max(altura(x->left), altura(x->right)) + 1;
    y->altura = max(altura(y->left), altura(y->right)) + 1;

    //nova raiz
    return y;
}

// Get Balance factor of node N
int fatorBalanceamento(struct Node *N)
{
    if (N == NULL)
        return 0;
    return altura(N->left) - altura(N->right);
}

//Um pouco de mágica acontece aqui, caso não acredite, pule para proxima função
struct Node *adiciona(AvlTree *A, struct Node *node, int key)
{
    //Verificando onde será inserção
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = adiciona(A, node->left, key);
    else if (key > node->key)
        node->right = adiciona(A, node->right, key);
    else
        return node;

    node->altura = 1 + max(altura(node->left), altura(node->right));

    //descobre o se o nodo está desbalanceado
    int balance = fatorBalanceamento(node);

    //então se necessário realiza o balanceamento
    A->contador++;
    //rsd
    if (balance > 1 && key < node->left->key)
    {
        A->contador++;
        return rightRotate(A, node);
    }

    //rse
    if (balance < -1 && key > node->right->key)
    {
        A->contador++;
        return leftRotate(A, node);
    }

    //rdd
    if (balance > 1 && key > node->left->key)
    {
        A->contador++;
        node->left = leftRotate(A, node->left);
        return rightRotate(A, node);
    }

    //rde
    if (balance < -1 && key < node->right->key)
    {
        A->contador++;
        node->right = rightRotate(A, node->right);
        return leftRotate(A, node);
    }

    return node;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
