#apenas gera um arquivo de inteiros aleatórios ordenados
import random
arquivo = open("inputs//pior_caso.txt", 'w')

values = []
for i in range(100):
    values.append(random.randint(1,1000))
values.sort()

for i in values:
    arquivo.write(str(i)+"\n")

