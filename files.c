#include "livraria.h"

int readLivros(char *path, Tree *books){

    FILE *in;
    Livro *aux=(Livro*)malloc(sizeof(Livro));
    in = fopen(path,"r");

    if(in==NULL){
        return -1;
    }

    while (10==fscanf(in," %d %s %s %s %s %s %d %s %le %d", &aux->ISBM, aux->titulo, aux->idioma, aux->primAutor, aux->secAutor, aux->editora, &aux->anoPub, aux->area, &aux->preco, &aux->stock)){
        printLivro(*aux);
        
        books = addNodoTree(books,*aux);
        memset(aux,0,1);
        aux=(Livro*)malloc(sizeof(Livro));

        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return 1;
}