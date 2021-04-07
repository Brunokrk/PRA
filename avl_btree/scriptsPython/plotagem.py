import matplotlib.pyplot as plt
import pylab
from json import load
from typing import Dict


def plotaGraficoPiorCaso():
    pior_caso_avl = open(
        'C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\outputs\\pior_caso_out_avl.txt', 'r')
    pior_caso_btree = open(
        'C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\outputs\\pior_caso_out_btree.txt', 'r')

    x_avl = []
    y_avl = []
    cont_chaves = 1
    for linha in pior_caso_avl:
        x_avl.append(cont_chaves)
        y_avl.append(int(linha))
        cont_chaves += 1

    x_btree = []
    y_btree = []
    cont_chaves = 1
    for linha in pior_caso_btree:
        x_btree.append(cont_chaves)
        y_btree.append(int(linha))
        cont_chaves += 1

    # plotando AVL
    #plt.scatter(x_avl, y_avl, color='blue')
    plt.plot(x_avl, y_avl, color='blue', label='AVL-Tree')

    # plotando BTREE
    #plt.scatter(x_btree, y_btree, color='red')
    plt.plot(x_btree, y_btree, color='red', label='B-Tree')

    plt.title('Gráfico para pior caso, chaves ordenadas')
    # Eixo X
    plt.xlabel('Quantidade de Chaves')
    # Eixo Y
    plt.ylabel('Quantidade de Operações')

    plt.grid(True)
    plt.legend()
    plt.xscale('log')
    # plt.show()
    plt.savefig(
        "C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\graficos\\pior_caso.png")


def plotaGraficoMedioCaso():

    medio_caso_avl = open(
        'C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\outputs\\medio_caso_out_avl.txt', 'r')

    # Cria dicionario
    data_lines_avl = medio_caso_avl.readlines()
    data = set_data(data_lines_avl)
    data = preenche_data(data_lines_avl, data)

    x_avl = [j+1 for j in range(100)]
    y_avl = []
    media = 0
    for i in range(100):
        for key in data.keys():
            valor = int(data[key][i])
            media += valor
        y_avl.append(int(media/10))
        media = 0

    # plotando AVL
    plt.plot(x_avl, y_avl, color='blue', label='AVL-Tree')
    # plotando BTREE
    #plt.plot(x_btree, y_btree, color='red', label='B-Tree')

    plt.title('Gráfico para caso medio, chaves desordenadas')
    # Eixo X
    plt.xlabel('Quantidade de Chaves')
    # Eixo Y
    plt.ylabel('Quantidade de Operações')

    plt.grid(True)
    plt.legend()
    plt.xscale('log')
    # plt.show()
    plt.savefig(
        "C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\graficos\\medio_caso.png")


def set_data(data_lines_avl):
    data = dict()
    for data_line in data_lines_avl:
        nroaTeste, ops = data_line.split(", ")
        nroaTeste = int(nroaTeste)
        data[nroaTeste] = []
    return data


def preenche_data(data_lines_avl, data):
    for data_line in data_lines_avl:
        nroaTeste, ops = data_line.split(", ")
        nroaTeste = int(nroaTeste)
        ops = int(ops)
        data[nroaTeste].append(ops)
    return data


if __name__ == "__main__":
    # plotaGraficoPiorCaso()
    plotaGraficoMedioCaso()
