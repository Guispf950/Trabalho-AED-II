# Variáveis de Configuração
CC = gcc
CFLAGS = -Wall -Wextra -I./TADS -I./Utils

# Diretórios
TADS_DIR = TADS
MAIN_DIR = "Questoes Main"
UTILS_DIR = Utils
# Arquivos de TADs (objetos ou fontes)

BST = $(TADS_DIR)/arvoreBinaria.c
AVL = $(TADS_DIR)/arvoreAVL.c
VETOR = $(TADS_DIR)/vetor.c
UTIL = $(UTILS_DIR)/utils.c

# Alvos principais
all: q1 q2 q3 q4
# Questão 1: Caminhamentos em BST
q1:
	$(CC) $(CFLAGS) $(MAIN_DIR)/questao1main.c $(BST) -o questao1

# Questão 2: Simulação de Pacotes de Rede (usa BST)
q2:
	$(CC) $(CFLAGS) $(MAIN_DIR)/questao2main.c $(BST) $(UTIL) -o questao2

# Questão 3: Desempenho BST vs Vetor
q3:
	$(CC) $(CFLAGS) $(MAIN_DIR)/questao3main.c $(BST) $(VETOR) $(UTIL) -o questao3

# Questão 4: Desempenho AVL vs BST
q4:
	$(CC) $(CFLAGS) $(MAIN_DIR)/questao4main.c $(BST) $(AVL) $(UTIL) -o questao4

# Limpeza dos executáveis
clean:
	rm -f questao1 questao2 questao3 questao4