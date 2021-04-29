#include "livraria.h"

Tree readLivros(char *path){

    Tree books = NULL;
    Livro new;

    int ISBM, anoPub, stock;
    double preco;
    char *titulo = (char*) malloc(30*sizeof(char));
    char *idioma = (char*) malloc(30*sizeof(char));
    char *primAutor = (char*) malloc(30*sizeof(char)); 
    char *secAutor = (char*) malloc(30*sizeof(char));
    char *editora = (char*) malloc(30*sizeof(char));
    char *area = (char*) malloc(30*sizeof(char));

    FILE *in;
    in = fopen(path,"r");

    if(in==NULL){
        return NULL;
    }

    printf("Entrada no read\n");

    while (10==fscanf(in,"%d %s %s %s %s %s %d %s %le %d", &ISBM, titulo, idioma, primAutor, secAutor, editora, &anoPub, area, &preco, &stock)){ 

        new = newLivro(ISBM, anoPub, stock, preco, titulo, idioma, primAutor, secAutor, editora, area);

        books = addNodoTree(books,new);
        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return books;
}