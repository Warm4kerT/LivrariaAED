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

void menuBooks(){
    int option = 99;
    int ISBM;
    Livro novoLivro, update;
    Tree search;

    while (option != 0){
        printf("----Livros----\n");
        printf("1- Novo Livro\n");
        printf("2- Remover por ISBM\n");
        printf("3- Alterar por ISBM\n");
        printf("4- Consultar\n"); 
        printf("0- Sair\n");

        scanf("%d",&option);

        switch (option){
            case 1:
                novoLivro = pedirLivro();
                mainTree = addNodoTree(mainTree,novoLivro);
                printf("Livro Adicionado\n");
            break;

            case 2:
                printf("Insira o ISBM do Livro a Remover: "); scanf("%d",&ISBM);
                search = searchTreeISBM(mainTree,ISBM);

                if(search==NULL){
                    printf("Livro não existe\n");
                }else{
                    mainTree = removeNodeTree(mainTree,search->book);
                    printf("Livro Removido\n");
                }
            break;

            case 3:
                printf("Insira o ISBM do Livro a Alterar: "); scanf("%d",&ISBM);
                search = searchTreeISBM(mainTree,ISBM);

                if(search==NULL){
                    printf("Livro não existe\n");
                }else{
                    printLivro(search->book);
                    update = alterarLivro(search->book);
                    mainTree = removeNodeTree(mainTree,search->book);
                    mainTree = addNodoTree(mainTree,update);
                    printf("Livro Atualizado\n");
                }
            break;

            case 4:
                printTree(mainTree); 
            break;

            case 5:
            break;
        }
    }

}