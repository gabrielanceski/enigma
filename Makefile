# Configurações do compilador
CC = gcc
CFLAGS = -Wall -g

# Diretórios para fonte e binários
SRC = src
BIN = bin
EXEC = enigma

# Arquivos fonte
SRCS := $(wildcard $(SRC)/*.c)
# Lista de objetos
OBJS := $(SRCS:$(SRC)/%.c=$(BIN)/%.o)

# Regra para compilar todos os arquivos
all: dirs $(BIN)/$(EXEC)

$(BIN)/$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Regra para criar os diretórios
dirs:
	mkdir -p $(BIN)

# Regra para abrir o programa
run: $(BIN)/$(EXEC)
	./$(BIN)/$(EXEC)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(BIN)/*