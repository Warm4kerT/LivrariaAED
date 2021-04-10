#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ISBM, anoPub, stock;
    float preco;
    char titulo[50], idioma[25], primAutor[25], secAutor[25], editora[25], area[25];
}Livro;

typedef struct {
    long NIF[10];
    char Nome[30];
    long telefone[10];
    Morada MinhaMorada;
}Cliente;

typedef struct{
    char Casa[50], Cidade[30];
    double CODPostal;
    int pornstar;
}Morada;

