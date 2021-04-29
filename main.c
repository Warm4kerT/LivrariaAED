#include "livraria.h"

int main(){
    printf("Hello World!\n");
    pathLivros = (char*) malloc(30*sizeof(char));
    pathClientes = (char*) malloc(30*sizeof(char));

    int option = 99;

    while (option != 0){
        printf("----Menu----\n");
        printf("1- Ficheiros\n");
        printf("2- Livros\n");
        printf("3- Clientes\n");
        printf("4- Encomendas\n");
        printf("5- Operações\n");
        printf("0- Sair\n");

        scanf("%d",&option);
        switch (option){
        case 1:
            menuFiles();
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
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