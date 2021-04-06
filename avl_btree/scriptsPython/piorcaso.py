import random
arquivo = open("arqs//pior_caso.txt", 'w')

values = []
for i in range(100):
    values.append(random.randint(1,1000))
values.sort()

for i in values:
    arquivo.write(str(i)+"\n")

