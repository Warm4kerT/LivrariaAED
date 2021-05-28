#include "livraria.h"

Livro pedirLivro(){
    int ISBN, anoPub, stock;
    double preco;
    char *titulo = (char*) malloc(allocSize*sizeof(char));
    char *idioma = (char*) malloc(allocSize*sizeof(char));
    char *primAutor = (char*) malloc(allocSize*sizeof(char)); 
    char *secAutor = (char*) malloc(allocSize*sizeof(char));
    char *editora = (char*) malloc(allocSize*sizeof(char));
    char *area = (char*) malloc(allocSize*sizeof(char));

    Livro new;

    printf("Insira o ISBN: "); scanf("%d",&ISBN);
    printf("Insira o Titulo: "); scanf("%s",titulo);
    printf("Insira o Idioma: "); scanf("%s",idioma);
    printf("Insira o Primeiro Autor: "); scanf("%s",primAutor);
    printf("Insira o Segundo Autor: "); scanf("%s",secAutor);
    printf("Insira a Editora: "); scanf("%s",editora);
    printf("Insira o Ano de Publicação: "); scanf("%d",&anoPub);
    printf("Insira a Area Científica: "); scanf("%s",area);
    printf("Insira o Preço: "); scanf("%le",&preco);
    printf("Insira o Stock: "); scanf("%d",&stock);

    new = newLivro(ISBN, anoPub, stock, preco, titulo, idioma, primAutor, secAutor, editora, area);

    return new;
}

Livro alterarLivro(Livro book){
    int option;
    Livro update = book;

    int ISBN, anoPub, stock;
    double preco;
    char *titulo = (char*) malloc(allocSize*sizeof(char));
    char *idioma = (char*) malloc(allocSize*sizeof(char));
    char *primAutor = (char*) malloc(allocSize*sizeof(char)); 
    char *secAutor = (char*) malloc(allocSize*sizeof(char));
    char *editora = (char*) malloc(allocSize*sizeof(char));
    char *area = (char*) malloc(allocSize*sizeof(char));

    printf("--Valor a Alterar--\n");
    printf("1- ISBN\n");
    printf("2- Titulo\n"); 
    printf("3- Idioma\n"); 
    printf("4- Primeiro Autor\n");
    printf("5- Segundo Autor\n");
    printf("6- Editora\n");
    printf("7- Ano de Publicação\n");
    printf("8- Area Científica\n");
    printf("9- Preço\n");
    printf("10- Stock\n");

    scanf("%d",&option);

    switch (option)
    {
    case 1:
        printf("Insira o novo ISBN: "); scanf("%d",&ISBN);
        update.ISBN = ISBN;
        break;

    case 2:
        printf("Insira o Titulo: "); scanf("%s",titulo);
        update.titulo = (char*) malloc(allocSize*sizeof(char));
        update.titulo = titulo;
        break;
    
    case 3:
        printf("Insira o Idioma: "); scanf("%s",idioma);
        update.idioma = (char*) malloc(allocSize*sizeof(char));
        update.idioma = idioma;
        break;
    
    case 4:
        printf("Insira o Primeiro Autor: "); scanf("%s",primAutor);
        update.primAutor = (char*) malloc(allocSize*sizeof(char));
        update.primAutor = primAutor;
        break;
    
    case 5:
        printf("Insira o Segundo Autor: "); scanf("%s",secAutor);
        update.secAutor = (char*) malloc(allocSize*sizeof(char));
        update.secAutor = secAutor;
        break;
        
    case 6:
        printf("Insira a Editora: "); scanf("%s",editora);
        memset(update.editora,0,1);
        update.editora = (char*) malloc(allocSize*sizeof(char));
        update.editora = editora;
        break;
    
    case 7:
        printf("Insira o Ano de Publicação: "); scanf("%d",&anoPub);
        update.anoPub = anoPub;
        break;
    
    case 8:
        printf("Insira a Area Científica: "); scanf("%s",area);
        update.area = (char*) malloc(allocSize*sizeof(char));
        update.area = area;
        break;
    
    case 9:
        printf("Insira o Preço: "); scanf("%le",&preco);
        update.preco = preco;
        break;
    
    case 10:
        printf("Insira o Stock: "); scanf("%d",&stock);
        update.stock = stock;
        break;
        
    default:
        break;
    }

    return update;
}

void searchByMenu(){
    int option = 99;

    int ISBN, anoPub;
    char *titulo = (char*) malloc(allocSize*sizeof(char));
    char *idioma = (char*) malloc(allocSize*sizeof(char));
    char *primAutor = (char*) malloc(allocSize*sizeof(char)); 
    char *secAutor = (char*) malloc(allocSize*sizeof(char));
    char *editora = (char*) malloc(allocSize*sizeof(char));
    char *area = (char*) malloc(allocSize*sizeof(char));

    printf("-- Procurar por --\n");
    printf("1- ISBN\n");
    printf("2- Titulo\n"); 
    printf("3- Idioma\n"); 
    printf("4- Primeiro Autor\n");
    printf("5- Segundo Autor\n");
    printf("6- Editora\n");
    printf("7- Ano de Publicação\n");
    printf("8- Area Científica\n");
    printf("9- Preço\n");
    printf("10- Stock\n");

    scanf("%d",&option);

    switch (option){
    case 1:
        printf("Insira o ISBN: "); scanf("%d",&ISBN);
        printLivro((searchTreeISBN(mainTree,ISBN))->book);
        break;

    case 2:
        printf("Insira o Titulo: "); scanf("%s",titulo);

        break;
    
    case 3:
        printf("Insira o Idioma: "); scanf("%s",idioma);

        break;
    
    case 4:
        printf("Insira o Primeiro Autor: "); scanf("%s",primAutor);

        break;
    
    case 5:
        printf("Insira o Segundo Autor: "); scanf("%s",secAutor);

        break;
        
    case 6:
        printf("Insira a Editora: "); scanf("%s",editora);

        break;
    
    case 7:
        printf("Insira o Ano de Publicação: "); scanf("%d",&anoPub);

        break;
    
    case 8:
        printf("Insira a Area Científica: "); scanf("%s",area);

        break;
    
    case 9:
        printTree(mainTree);
        break;
    
    default:
        break;
    }
}

Cliente pedirCliente(){
    int NIF, telefone;
    char *nome = (char*) malloc(allocSize*sizeof(char));
    char *casa = (char*) malloc(allocSize*sizeof(char));
    char *cidade = (char*) malloc(allocSize*sizeof(char)); 
    int cod1, cod2;
    Cliente newC;
    Morada newM;

    printf("Insira o NIF: "); scanf("%d",&NIF);
    printf("Insira o Nome: "); scanf("%s",nome);
    printf("Insira o Telefone: "); scanf("%d",&telefone);
    printf("Insira o Morada:\nRua: "); scanf("%s",casa);
    printf("Cidade: "); scanf("%s",cidade);
    printf("Codigo Postal (xxxx-yyy): "); scanf("%d-%d",&cod1,&cod2);
    
    newM = newMorada(casa,cidade,cod1,cod2);
    newC = newCliente(NIF,telefone,nome,newM);

    return newC;
}

Cliente alterarCliente(Cliente cli){
    int option;
    Cliente update = cli;
    Morada updateM;

    int NIF, telefone;
    char *nome = (char*) malloc(allocSize*sizeof(char));
    char *casa = (char*) malloc(allocSize*sizeof(char));
    char *cidade = (char*) malloc(allocSize*sizeof(char)); 
    int cod1, cod2;

    printf("--Valor a Alterar--\n");
    printf("1- NIF\n");
    printf("2- Nome\n"); 
    printf("3- Telefone\n"); 
    printf("4- Morada\n");

    scanf("%d",&option);

    switch (option)
    {
    case 1:
        printf("Insira o novo NIF: "); scanf("%d",&NIF);
        update.NIF = NIF;
        break;

    case 2:
        printf("Insira o NOme: "); scanf("%s",nome);
        update.Nome = (char*) malloc(allocSize*sizeof(char));
        update.Nome = nome;
        break;
    
    case 3:
        printf("Insira o Telefone: "); scanf("%d",&telefone);
        update.telefone = telefone;
        break;
    
    case 4:
        printf("Insira o Morada:\nRua: "); scanf("%s",casa);
        printf("Cidade: "); scanf("%s",cidade);
        printf("Codigo Postal (xxxx-yyy): "); scanf("%d-%d",&cod1,&cod2);
        updateM = newMorada(casa,cidade,cod1,cod2);
        update.MinhaMorada = updateM;
        break;
        
    default:
        break;
    }

    return update;
}

Lista insereCompraCliente(int ISBN, int quantidade, float precoTotal, Data data, int NIF, Lista L){
	Lista search, final;
	Cliente updateC;
	search = PesquisaPorm(L, NIF); 
	updateC = search->Cli;

	updateC.lista = InserirInicioCompra(ISBN,quantidade,precoTotal,data,search->Cli.lista);

	final = RemoverNodoLista(search->Cli,L);
    final = InserirInicioLista(updateC,final);

	return final;
}
