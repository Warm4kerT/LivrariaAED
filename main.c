/**
 * @file main.c
*/

#include "livraria.h"

int main(){
    printf("Hello World!\n");
    pathLivros = (char*) malloc(allocSize*sizeof(char));
    pathClientes = (char*) malloc(allocSize*sizeof(char));
    pathEncomendas = (char*) malloc(allocSize*sizeof(char));

    pathLivros = "livros.txt";
    pathClientes = "clientes.txt";
    int NIF;
    mainTree = readLivros("livros.txt");
    mainLista = readClientes("clientes.txt");

    int mainOption = 99;

    while (mainOption != 0){
        printf("----Menu----\n");
        printf("1- Ficheiros\n");
        printf("2- Livros\n");
        printf("3- Clientes\n");
        printf("4- Encomendas\n");
        printf("5- Operações\n");
        printf("0- Sair\n");

        scanf("%d",&mainOption);
        switch (mainOption){
        case 1:
            menuFiles();
            break;
        case 2:
            menuBooks();
            break;
        case 3:
            MenuClientes();
            break;
        case 4:
            menuOrders();
            break;
        case 5:
            menuOperacoes();
            break;
        case 0:
            printf("Adeus\n");
            break;

        case 25:
            scanf("%d",&NIF);
            mostrarComprasCliente(NIF);
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
}