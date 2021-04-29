#include "livraria.h"

void menuFiles(){
    int option = 99;
    char *path=(char*) malloc(30*sizeof(char));

    while (option != 0){
        printf("----Files----\n");
        printf("1- Novo\n");
        printf("2- Abrir\n");
        printf("3- Guardar\n");
        printf("0- Sair\n");

        scanf("%d",&option);

        switch (option){
        case 1:

            break;

        case 2:
                printf("Insira o nome do Ficheiro:\n");
                scanf("%s", path);
                mainTree = readLivros(path);
            break;
        
        case 3:
            break;
        
        case 0:
            break;
        
        default:
            break;
        }
    }
    
}