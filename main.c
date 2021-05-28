#include "livraria.h"

int main(){
    printf("Hello World!\n");
    pathLivros = (char*) malloc(30*sizeof(char));
    pathClientes = (char*) malloc(30*sizeof(char));
    pathEncomendas = (char*) malloc(30*sizeof(char));

    mainLista = readClientes("clientes.txt");
    mainTree = readLivros("livros.txt");

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
        
        default:
            break;
        }
    }
    
    
    return 0;
}