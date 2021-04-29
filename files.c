#include "livraria.h"

Tree readLivros(char *path){

    Tree books = NULL;
    Livro new;
    int ISBM, anoPub, stock;
    double preco;
    char titulo[30], idioma[30], primAutor[30], secAutor[30], editora[30], area[30];
    FILE *in;
    in = fopen(path,"r");

    if(in==NULL){
        return NULL;
    }

    printf("Entrada no read\n");

    while (10==fscanf(in,"%d %s %s %s %s %s %d %s %le %d", &ISBM, titulo, idioma, primAutor, secAutor, editora, &anoPub, area, &preco, &stock)){ 

        new = newLivro(ISBM, anoPub, stock, preco, titulo, idioma, primAutor, secAutor, editora, area);
        
        printf("%s\n",titulo);

        books = addNodoTree(books,new);
        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return books;
}