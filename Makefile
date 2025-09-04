# Makefile para o projeto ArvoreRubroNegra

CC = gcc
CFLAGS = -I. -I./Operacoes -Wall -g
TARGET = ExemploArvoreInteiros.exe
SRC = ExemploArvoreInteiros.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
