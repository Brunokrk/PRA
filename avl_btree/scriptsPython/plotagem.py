import matplotlib.pyplot as plt
import pylab
from json import load
from typing import Dict


def plotaGraficoPiorCaso():
    #fig, axs = plt.subplots(2)

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

    return x_avl, y_avl, x_btree, y_btree


def plotaGraficoMedioCaso():

    medio_caso_avl = open(
        'C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\outputs\\medio_caso_out_avl.txt', 'r')

    medio_caso_btree = open(
        'C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\outputs\\medio_caso_out_btree.txt', 'r')

    # Cria dicionarios
    # avl
    data_lines_avl = medio_caso_avl.readlines()
    data_avl = set_data(data_lines_avl)
    data_avl = preenche_data(data_lines_avl, data_avl)
    # btree
    data_lines_btree = medio_caso_btree.readlines()
    data_btree = set_data(data_lines_btree)
    data_btree = preenche_data(data_lines_btree, data_btree)

    # AVL
    x_avl = [j+1 for j in range(100)]
    y_avl = []
    media = 0
    for i in range(100):
        for key in data_avl.keys():
            valor = int(data_avl[key][i])
            media += valor
        y_avl.append(int(media/10))
        media = 0

    # BTREE
    x_btree = [j+1 for j in range(100)]
    y_btree = []
    media = 0
    for i in range(100):
        for key in data_btree.keys():
            valor = int(data_btree[key][i])
            media += valor
        y_btree.append(int(media/10))
        media = 0

    return x_avl, y_avl, x_btree, y_btree
    


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
    x_avl_p, y_avl_p, x_btree_p, y_btree_p = plotaGraficoPiorCaso()
    x_avl_m, y_avl_m, x_btree_m, y_btree_m = plotaGraficoMedioCaso()

    figure = plt.figure(figsize=(10, 10), dpi=80)

    sub_piorcaso = figure.add_subplot(211)
    sub_mediocaso = figure.add_subplot(212)

    sub_piorcaso.set_title("Pior Caso")
    sub_piorcaso.set_xlabel("Qtd Chaves")
    sub_piorcaso.set_ylabel("Qtd Operações")

    sub_mediocaso.set_title("Caso Medio")
    sub_mediocaso.set_xlabel("Qtd Chaves")
    sub_mediocaso.set_ylabel("Qtd Operações")

    sub_piorcaso.plot(x_avl_p, y_avl_p, label="AVL")
    sub_piorcaso.plot(x_btree_p, y_btree_p, label="BTree")

    sub_mediocaso.plot(x_avl_m, y_avl_m, label="AVL")
    sub_mediocaso.plot(x_btree_m, y_btree_m, label="BTree")

    sub_piorcaso.legend()
    sub_mediocaso.legend()

    sub_piorcaso.set_xscale('log')
    sub_mediocaso.set_xscale('log')
    sub_mediocaso.grid(True)
    sub_piorcaso.grid(True)
    #plt.savefig("C:\\Users\\pires\\Documents\\GitHub\\PRA\\avl_btree\\graficos\\analise.png")

    plt.show()
