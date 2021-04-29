#include "livraria.h"

Livro pedirLivro(){
    int ISBM, anoPub, stock;
    double preco;
    char *titulo = (char*) malloc(30*sizeof(char));
    char *idioma = (char*) malloc(30*sizeof(char));
    char *primAutor = (char*) malloc(30*sizeof(char)); 
    char *secAutor = (char*) malloc(30*sizeof(char));
    char *editora = (char*) malloc(30*sizeof(char));
    char *area = (char*) malloc(30*sizeof(char));

    Livro new;

    printf("Insira o ISBM: "); scanf("%d",&ISBM);
    printf("Insira o Titulo: "); scanf("%s",titulo);
    printf("Insira o Idioma: "); scanf("%s",idioma);
    printf("Insira o Primeiro Autor: "); scanf("%s",primAutor);
    printf("Insira o Segundo Autor: "); scanf("%s",secAutor);
    printf("Insira a Editora: "); scanf("%s",editora);
    printf("Insira o Ano de Publicação: "); scanf("%d",&anoPub);
    printf("Insira a Area Científica: "); scanf("%s",area);
    printf("Insira o Preço: "); scanf("%le",&preco);
    printf("Insira o Stock: "); scanf("%d",&stock);

    new = newLivro(ISBM, anoPub, stock, preco, titulo, idioma, primAutor, secAutor, editora, area);

    return new;
}

Livro alterarLivro(Livro book){
    int option;
    Livro update = book;

    int ISBM, anoPub, stock;
    double preco;
    char *titulo = (char*) malloc(30*sizeof(char));
    char *idioma = (char*) malloc(30*sizeof(char));
    char *primAutor = (char*) malloc(30*sizeof(char)); 
    char *secAutor = (char*) malloc(30*sizeof(char));
    char *editora = (char*) malloc(30*sizeof(char));
    char *area = (char*) malloc(30*sizeof(char));

    printf("--Valor a Alterar--\n");
    printf("1- ISBM\n");
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
        printf("Insira o novo ISBM: "); scanf("%d",&ISBM);
        update.ISBM = ISBM;
        break;

    case 2:
        printf("Insira o Titulo: "); scanf("%s",titulo);
        update.titulo = titulo;
        break;
    
    case 3:
        printf("Insira o Idioma: "); scanf("%s",idioma);
        update.idioma = idioma;
        break;
    
    case 4:
        printf("Insira o Primeiro Autor: "); scanf("%s",primAutor);
        update.primAutor = primAutor;
        break;
    
    case 5:
        printf("Insira o Segundo Autor: "); scanf("%s",secAutor);
        update.secAutor = secAutor;
        break;
        
    case 6:
        printf("Insira a Editora: "); scanf("%s",editora);
        update.editora = editora;
        break;
    
    case 7:
        printf("Insira o Ano de Publicação: "); scanf("%d",&anoPub);
        update.anoPub = anoPub;
        break;
    
    case 8:
        printf("Insira a Area Científica: "); scanf("%s",area);
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