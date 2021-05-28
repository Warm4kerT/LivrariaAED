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

                scanf("%d",&subOption);
                switch (subOption){
                    case 1:
                        printf("Insira o nome do novo Ficheiro:\n");
                        scanf("%s", pathClientes);
                        mainLista = FreeLista(mainLista);
                        //NewFileClientes
                        break;

                    case 2:
                        printf("Insira o nome do Ficheiro:\n");
                        scanf("%s", pathLivros);
                        mainTree = freeTree(mainTree);
                        //NewFileLivros
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

                scanf("%d",&subOption);
                switch(subOption){
                    case 1:
                        printf("Insira o nome do Ficheiro:\n");
                        scanf("%s", pathClientes);
                        mainLista = readClientes(pathClientes);
                        break;

                    case 2:
                        printf("Insira o nome do Ficheiro:\n");
                        scanf("%s", pathLivros);
                        mainTree = readLivros(pathLivros);
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

                scanf("%d",&subOption);
                switch (subOption){
                    case 1:
                        writeClientes(mainLista,pathClientes);
                        printf("Escrito no ficheiro default\n");
                        break;

                    case 2:
                        writeLivros(mainTree,pathLivros);
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
    int ISBN;
    Livro novoLivro, update;
    Tree search;

    while (option != 0){
        printf("----Livros----\n");
        printf("1- Novo Livro\n");
        printf("2- Remover por ISBN\n");
        printf("3- Alterar por ISBN\n");
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
                printf("Insira o ISBN do Livro a Remover: "); scanf("%d",&ISBN);
                search = searchTreeISBN(mainTree,ISBN);

                if(search==NULL){
                    printf("Livro não existe\n");
                }else{
                    mainTree = removeNodeTree(mainTree,search->book);
                    printf("Livro Removido\n");
                }
            break;

            case 3:
                printf("Insira o ISBN do Livro a Alterar: "); scanf("%d",&ISBN);
                search = searchTreeISBN(mainTree,ISBN);

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
    int ISBNLivro, NIFCliente, numUnidades;
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
                    printf("Insira o ISBN: "); scanf("%d",&ISBNLivro);
                    search = searchTreeISBN(mainTree, ISBNLivro);
                    
                    if(search==NULL){
                        printf("Livro não encontrado\n");
                    }else{
                        flag = 1;
                        newOrder.ISBNLivro = ISBNLivro;
                    }
                }while(flag == 0);

                flag = 0;

                do{
                    printf("Insira o NIF: "); scanf("%d",&NIFCliente);
                    //search clientes para verificar a existencia
                    
                    if(PesquisaLista(NIFCliente,mainLista) == 0){
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
                        newOrder = searchFilaEnc(mainFila, numEnc);
                        mainLista = insereCompraCliente(newOrder.ISBNLivro,newOrder.numUnidades,newOrder.preco,newOrder.venda,newOrder.NIFCliente,mainLista);
                        mainFila = removeFilaEspecifico(mainFila,numEnc);
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

void MenuClientes(){
    int option = 99;
    int NIF;
    Cliente novoCliente, updateC;
    Lista search;

    while (option != 0){
        printf("----Clientes----\n");
        printf("1- Novo Cliente\n");
        printf("2- Remover por NIF\n");
        printf("3- Alterar por NIF\n");
        printf("4- Consultar\n"); 
        printf("0- Sair\n");

        scanf("%d",&option);

        switch (option){
            case 1:
                novoCliente = pedirCliente();
                mainLista = InserirInicioLista(novoCliente,mainLista);
                printf("Cliente Adicionado\n");
            break;

            case 2:
                printf("Insira o NIF do Cliente a Remover: "); scanf("%d",&NIF);
                search = PesquisaPorm(mainLista,NIF);

                if(search==NULL){
                    printf("Cliente não existe\n");
                }else{
                    mainLista = RemoverNodoLista(search->Cli,mainLista);
                    printf("Cliente Removido\n");
                }
            break;

            case 3:
                printf("Insira o NIF do Cliente a Alterar: "); scanf("%d",&NIF);
                search = PesquisaPorm(mainLista,NIF);

                if(search==NULL){
                    printf("Cliente não existe\n");
                }else{
                    printCliente(search->Cli);
                    updateC = alterarCliente(search->Cli);
                    mainLista = RemoverNodoLista(search->Cli,mainLista);
                    mainLista = InserirInicioLista(updateC,mainLista);
                    printf("Cliente Atualizado\n");
                }
            break;

            case 4:
                ListarLista(mainLista); 
            break;

            case 0:
            break;
        }
    }
}


void menuOperacoes(){
    int option = 99;

    int mes, ano, NIF, ISBN;
    ListaCompra show;
    Tree livros;
    int k;

    while(option!=0){
        printf("----Operações----\n");
        printf("1- Vendas Num Periodo de tempo\n");
        printf("2- Ultima Venda de um Livro (ISBN)\n");
        printf("3- Quantidade de Livros comprados Por Cliente (NIF)\n");
        printf("5- Mostrar os K livros mais vendidos de um Periodo de tempo\n");
        printf("0- Sair\n");

        scanf("%d",&option);

        switch(option){
            case 1:
                printf("Insira o mes e ano (mm/aaaa): "); scanf("%d/%d",&mes,&ano);
                show = vendasNumPeriodo(mes,ano);
                ListarCompra(show);
                break;

            case 2:
                printf("Insira o ISBN do Livro a consultar: "); scanf("%d",&ISBN);
                ultimaVendaLivro(ISBN);
                break;

            case 3:
                printf("Insira o NIF do Cliente a Consultar: "); scanf("%d",&NIF);
                quantidadeVendidaCliente(NIF);
                break;

            case 5:
                printf("Insira o mes e ano (mm/aaaa): "); scanf("%d/%d",&mes,&ano);
                printf("Insira o numero de livros: "); scanf("%d",&k);
                show = vendasNumPeriodo(mes,ano);
                livros = LivrosMaisVendidosK(show,k);
                printTree(livros);
                break;
        
            default:
                break;
        }
    }
}