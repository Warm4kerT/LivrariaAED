#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Paths
char *pathLivros;
char *pathClientes;
char *pathEncomendas;

//Compras
typedef struct Compra{
    int ISBM, quantidade;
    struct Compra *prox;
}Compra;


//Cliente
typedef struct Morada{
    char Casa[50], Cidade[30];
    double CODPostal;
}Morada;

typedef struct Cliente {
    int NIF, telefone;
    char Nome[30];
    Morada MinhaMorada;
}Cliente;

//Livro
typedef struct Livro{
    int ISBM, anoPub, stock;
    float preco;
    char *titulo, *idioma, *primAutor, *secAutor, *editora, *area;
}Livro;

Livro newLivro(int ISBM, int anoPub, int stock, float preco, char *titulo, char *idioma, char *primAutor, char *secAutor, char *editora, char *area);;
void printLivro(Livro b);
int equalsLivro(Livro a, Livro b);

//Tree
typedef struct LivroTree{
    Livro book;
    struct LivroTree *left;
    struct LivroTree *right;
}*Tree;

Tree newNode(Livro book);
Tree freeNode(Tree n);
Tree freeTree(Tree t);
int numNodeT(Tree t);
int heightTree(Tree t);
void printTree(Tree t);
Tree searchTree(Livro l, Tree t);
Tree searchLeafTree(Tree t, Livro *out);
Tree addNodoTree(Tree t, Livro l);
Tree searchTreeISBM(Tree t, int ISBM);
Tree removeNodeAux (Tree t);
Tree removeNodeTree (Tree t, Livro l);

Tree mainTree;

//Encomendas
typedef struct Data{
    int ano,mes,dia;
}Data;

typedef struct Encomenda{
    int numEnc;
    int ISBMLivro, NIFCliente, numUnidades;
    float preco;
    Data enc, venda;
}Encomenda;

Encomenda newEncomenda(int numEnc, int ISBM, int NIF, int quantidade, float preco, Data enc, Data venda);
Data newDate(int dia, int mes, int ano);
void printEncomenda(Encomenda o);

//Fila
typedef struct FilaEnc{
    Encomenda order;
    struct FilaEnc *prox;
}*Fila;

Fila createNodeFila(Encomenda order);
Fila freeNodeFila(Fila P);
int emptyFila(Fila P);
Fila createFila();
Fila addNodeFila(Encomenda order, Fila P);
Fila removeFila(Fila F);
Fila freeFila(Fila F);
Encomenda front(Fila F);
Fila removeFilaEspecifico(Fila F, int numEnc);
int searchFilaNumEnc(Fila F, int numEnc);
int numUltimaEncomenda(Fila F);
void printFila(Fila F);

Fila mainFila;

//Files

Tree readLivros(char *path);
void writeLivros(Tree books, char *path);

//Menus

void menuFiles();
void menuBooks();
void menuOrders();

//Operacoes

Livro pedirLivro();
Livro alterarLivro(Livro book);
