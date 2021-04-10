#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//Livro
typedef struct Livro{
    int ISBM, anoPub, stock;
    float preco;
    char titulo[50], idioma[25], primAutor[25], secAutor[25], editora[25], area[25];
}Livro;

void printLivro(Livro b);
int equalsLivro(Livro a, Livro b);

//Tree
typedef struct LivroTree{
    Livro book;
    struct LivroTree *left;
    struct LivroTree *right;
}*Tree;

Tree criaNodo(Livro book);
Tree freeNode(Tree n);
Tree freeTree(Tree t);
int numNodosT(Tree t);
void printTree(Tree t);
Tree searchTree(Livro l, Tree t);