#include <stdio.h>
#include <stdlib.h>

struct Livro{
    int ISBM, anoPub, stock;
    float preco;
    char *titulo[50], *idioma[25], *primAutor[25], *secAutor[25], *editora[25], *area[25];
};

struct Cliente{
    long NIF[10];
    char Nome[30];
    long telefone[10];
    struct Morada MinhaMorada;
};

struct Morada{
    char Casa[50], Cidade[30];
    double CODPostal;
    int pornstar;
};

