#include "livraria.h"

void menuFiles(){
    int option = 99;
    int subOption = 99;

    while (option != 0){
        printf("----Files----\n");
        printf("1- Novo\n");
        printf("2- Abrir\n");
        printf("3- Guardar\n");
        printf("0- Sair\n");

        scanf("%d",&option);

        switch (option){
        case 1:
                printf("----Novo----\n");
                printf("1- Clientes\n");
                printf("2- Livros\n");

                scanf("%d",&subOption);
                switch (subOption){
                case 1:
                    printf("Insira o nome do novo Ficheiro:\n");
                    scanf("%s", pathClientes);
                    //NewFileClientes
                    break;

                case 2:
                    printf("Insira o nome do Ficheiro:\n");
                    scanf("%s", pathLivros);
                    //NewFileLivros
                    break;
                
                default:
                    break;
                }

                subOption = 99;

            break;

        case 2:
                printf("----Abrir----\n");
                printf("1- Clientes\n");
                printf("2- Livros\n");

                scanf("%d",&subOption);
                switch (subOption){
                case 1:
                    printf("Insira o nome do Ficheiro:\n");
                    scanf("%s", pathClientes);
                    //Read list of clients
                    break;

                case 2:
                    printf("Insira o nome do Ficheiro:\n");
                    scanf("%s", pathLivros);
                    mainTree = readLivros(pathLivros);
                    break;
                
                default:
                    break;
                }

                subOption = 99;
                
            break;
        
        case 3:
                printf("----Guardar----\n");
                printf("1- Clientes\n");
                printf("2- Livros\n");

                scanf("%d",&subOption);
                switch (subOption){
                case 1:
                    //write list of clients
                    printf("Escrito no ficheiro default\n");
                    break;

                case 2:
                    writeLivros(mainTree,pathLivros);
                    printf("Escrito no ficheiro default\n");
                    break;
                
                default:
                    break;
                }

                subOption = 99;
            break;
        
        case 0:
            break;
        
        default:
            break;
        }
    }
    
}