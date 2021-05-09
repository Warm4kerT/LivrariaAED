#include "livraria.h"

void menuFiles(){
    int option = 99;
    int subOption = 99;

    while(option != 0){
        printf("----Files----\n1- Novo\n2- Abrir\n3- Guardar\n0- Sair\n");

        scanf("%d", &option);

        switch(option){
            default:
                scanf("%d", &option);
            break;

            case 1:
                printf("----Novo----\n");
                printf("1- Clientes\n");
                printf("2- Livros\n");
                printf("3- Encomendas\n");

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
                        mainTree = freeTree(mainTree);
                        //NewFileLivros
                        break;

                    case 3:
                        printf("Insira o nomde do Ficheiro:\n");
                        scanf("%s",pathEncomendas);
                        mainFila = freeFila(mainFila);
                        //NewFileEncomendas
                        break;
                    
                    case 0:
                        break;
                }
                subOption = 99;
            break;

            case 2:
                printf("----Abrir----\n");
                printf("1- Clientes\n");
                printf("2- Livros\n");
                printf("3- Encomendas\n");

                scanf("%d",&subOption);
                switch(subOption){
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

                    case 3:
                        printf("Insira o nome do Ficherio:\n");
                        scanf("%s",pathEncomendas);
                        mainFila = readEncomenda(pathEncomendas);
                        break;

                    case 0:
                        break;
                }
                subOption = 99;

            break;
        
            case 3:
                printf("----Guardar----\n");
                printf("1- Clientes\n");
                printf("2- Livros\n");
                printf("3- Encomendas\n");

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

                    case 3:
                        writeEncomendas(mainFila,pathEncomendas);
                        printf("Escrito no ficheiro default\n");
                        break;
                    
                    case 0:
                        break;
                }
                subOption = 99;
            break;
        
            case 0:
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

            case 0:
            break;
        }
    }
}

void menuOrders(){
    int options = 99;

    Tree search;
    Encomenda newOrder;
    int flag = 0;
    int numEnc;
    int ISBMLivro, NIFCliente, numUnidades;
    Data enc, venda;

    while(options!=0){

        printf("---Encomendas---\n");
        printf("1- Inserir\n");
        printf("2- Remover\n");
        printf("0- Sair\n");

        scanf("%d",&options);

        switch(options){
            case 1:
                do{
                    printf("Insira o ISBM: "); scanf("%d",&ISBMLivro);
                    search = searchTreeISBM(mainTree, ISBMLivro);
                    
                    if(search==NULL){
                        printf("Livro não encontrado\n");
                    }else{
                        flag = 1;
                        newOrder.ISBMLivro = ISBMLivro;
                    }
                }while(flag == 0);

                flag = 0;

                do{
                    printf("Insira o NIF: "); scanf("%d",&NIFCliente);
                    //search clientes para verificar a existencia
                    
                    if(NIFCliente == 0){
                        printf("Cliente não encontrado\n");
                    }else{
                        flag = 1;
                        newOrder.NIFCliente = NIFCliente;
                    }
                }while(flag == 0);

                printf("Insira quantidade: "); scanf("%d",&numUnidades);
                newOrder.numUnidades = numUnidades;

                printf("%f\n",search->book.preco);

                newOrder.preco = (search->book.preco)*numUnidades;

                printf("Insira a data de Encomenda (dd/mm/aaaa): "); scanf("%d/%d/%d",&enc.dia,&enc.mes,&enc.ano);
                printf("Insira a data de Venda (dd/mm/aaaa): "); scanf("%d/%d/%d",&venda.dia,&venda.mes,&venda.ano);

                newOrder.enc = enc;
                newOrder.venda = venda;
                newOrder.numEnc = numUltimaEncomenda(mainFila)+1;

                mainFila = addNodeFila(newOrder, mainFila);

                break;

            case 2:
                do{
                    printf("Insira o numero da Encomenda a remover: "); scanf("%d",&numEnc);
                    if(searchFilaNumEnc(mainFila,numEnc)==0){
                        printf("Encomenda não encontrada.\n");
                    }else{
                        mainFila = removeFilaEspecifico(mainFila,numEnc);

                        //Falta remover a encomenda do Cliente

                        printf("Encomenda Removida");
                        flag = 1;
                    }
                }while(flag == 0);

                break;

            case 0:
                break;

            case 9:
                printFila(mainFila);
                break;

        }
    }
}