#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Memory size alloc
#define allocSize 30

//Paths
char *pathLivros;
char *pathClientes;
char *pathEncomendas;

//Data
typedef struct Data{
    int ano,mes,dia;
}Data;

//Compras
typedef struct Compra{
    int ISBN, quantidade;
    float precoTotal;
    Data dataVenda;
    struct Compra *Prox;
}*ListaCompra;

void printCompra(ListaCompra b);
int equalsCompra(ListaCompra a, ListaCompra b);
ListaCompra FreeCompra(ListaCompra l);
ListaCompra CriarNodoCompra(int ISBN, int quantidade, float precoTotal, Data data);
ListaCompra LibertarNodoCompra(ListaCompra L);
ListaCompra InserirInicioCompra(int ISBN, int quantidade, float precoTotal, Data data, ListaCompra L);
void ListarCompra (ListaCompra L);
int PesquisaCompra(int ISBN,ListaCompra L);
ListaCompra ProcurarAnteriorCompraISBN(int ISBN, ListaCompra L);
ListaCompra FreeListaCompras(ListaCompra L);
ListaCompra swapCompra(ListaCompra a, ListaCompra b, ListaCompra L);
ListaCompra bubbleSortCompra(ListaCompra L);
int getSizeCompra(ListaCompra L);

//Cliente
typedef struct Morada{
    char *Casa, *Cidade;
    int CODPostal[2];
}Morada;

typedef struct Cliente {
    int NIF, telefone;
    char *Nome;
    Morada MinhaMorada;
    ListaCompra lista;
}Cliente;

Cliente newCliente(int NIF, int Telefone, char *Nome, Morada morada);
Morada newMorada(char *Casa, char *Cidade, int COD1, int COD2);
void printCliente(Cliente b);
void printMorada(Morada b);
int equalsMorada(Morada a, Morada b);
int equalsCliente(Cliente a, Cliente b);

//Lista ligada Cliente
 typedef struct ClienteLista{
     Cliente Cli;
     struct ClienteLista *Prox;
 }*Lista;


Lista CriarNodoLista(Cliente CLI);
Lista LibertarNodoLista(Lista L);
Lista InserirInicioLista(Cliente CLI,Lista L);
void ListarLista (Lista L);
int PesquisaLista(int NIF,Lista L);
Lista ProcurarAnteriorLista (Cliente X, Lista L);
Lista RemoverNodoLista (Cliente X, Lista L);
Lista FreeLista(Lista L);
Lista PesquisaPorm(Lista L, int NIF);
Lista bubbleSortClientes(Lista L);

Lista mainLista;
 

//Livro
typedef struct Livro{
    int ISBN, anoPub, stock;
    float preco;
    char *titulo, *idioma, *primAutor, *secAutor, *editora, *area;
}Livro;

Livro newLivro(int ISBN, int anoPub, int stock, float preco, char *titulo, char *idioma, char *primAutor, char *secAutor, char *editora, char *area);;
Data newData(int dia, int mes, int ano);
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
Tree searchTreeISBN(Tree t, int ISBN);
void searchTreeAC(Tree t, Tree *Final, char *AC);
Tree removeNodeAux (Tree t);
Tree removeNodeTree (Tree t, Livro l);

Tree mainTree;

//Encomendas
typedef struct Encomenda{
    int numEnc;
    int ISBNLivro, NIFCliente, numUnidades;
    float preco;
    Data enc, venda;
}Encomenda;

Encomenda newEncomenda(int numEnc, int ISBN, int NIF, int quantidade, float preco, Data enc, Data venda);
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
Encomenda searchFilaEnc(Fila F, int numEnc);

Fila mainFila;

//Files

Tree readLivros(char *path);
void writeLivros(Tree books, char *path);
Lista readClientes(char * path);
void writeClientes(Lista clientes, char *path);

//Menus

void menuFiles();
void menuBooks();
void menuOrders();
void MenuClientes();
void menuOperacoes();

//Menu Auxiliar

Livro pedirLivro();
Livro alterarLivro(Livro book);
Cliente pedirCliente();
Cliente alterarCliente(Cliente cli);
Lista insereCompraCliente(int ISBN, int quantidade, float precoTotal, Data data, int NIF, Lista L);

//Operações

ListaCompra vendasNumPeriodo(int mes, int ano);
void ultimaVendaLivro(int ISBN);
void quantidadeVendidaCliente(int NIF);
Tree LivrosMaisVendidosK(ListaCompra L, int k);
int wastedMemory();
Cliente bigSpender(int ano, int mes);
Cliente maisLivrosComprados();
Tree KRecentesAC (Tree T, Livro l);

int anoMaisPublicacoes();
char *areaMaisLivros();

void mostrarComprasCliente(int NIF);