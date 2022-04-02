# Encontrar em um vetor dois valores dos quais a soma resulta em outro determinado valor 
target = int(input("Digite o valor alvo: "))
size = int(input("Digite o tamanho do vetor: "))
vetor = []
for i in range(size):
    n = int(input(f"Digite o número {i+1} do vetor: "))
    vetor.append(n)
for i in range(size):
    for j in range(size-1):
        if(vetor[i]+vetor[j+1] == target): 
            print([i, j+1])