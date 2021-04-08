# PRA
Projeto de Arquivos

Trabalho - árvores AVL e B
Trabalho em equipe (até 5 integrantes)

O objetivo deste trabalho consiste em analisar a complexidade algorítmica das operações de adição de nós e balanceamento em árvores AVL e Árvores B. A análise deve ser realizada considerando a geração de um conjunto de dados (chaves) com tamanho variando entre 1 e 100. As chaves devem ser geradas prevendo o pior caso (chaves ordenadas crescente ou decrescente) e caso médio (chaves aleatórias). Para geração das chaves aleatórias, sugere-se o uso da função rand e srand em C considerando um tamanho de amostra de 10 conjuntos para validade estatística.

O resultado final do experimento deve ser exibido em dois gráfico de linha (um para o pior caso e outro para o caso médio), onde o eixo X representa o tamanho dos conjuntos de dados (1 a 100) e o eixo Y representa o esforço computacional das operações (adição de chaves e balanceamento). O gráfico deve apresentar 2 linhas, as quais representam as respectivas operações para cada estrutura de dados avaliada.

Data de entrega: 08/04/2021

Para executar o programa, basta compilar e executar o arquivo "main.c" no compilador do seu Sistema Operacional, o código em C irá gerar como saída quatro arquivos txt, contendo a contagem de operações de inserção nas árvores no pior e médio caso.

Após gerar tais arquivos, o script "plotagem.py" deve ser executado, ele irá gerar os gráficos
comparativos entre as árvores Avl e Btree.


