#include "livraria.h"

Tree readLivros(char *path){

    Tree books = NULL;
    Livro new;

    int ISBM, anoPub, stock;
    float preco;
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

    while (10==fscanf(in,"%d %s %s %s %s %s %d %s %f %d", &ISBM, titulo, idioma, primAutor, secAutor, editora, &anoPub, area, &preco, &stock)){ 

        new = newLivro(ISBM, anoPub, stock, preco, titulo, idioma, primAutor, secAutor, editora, area);

        books = addNodoTree(books,new);
        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return books;
}

void writeLoopLivro(Tree books, FILE *out){
    if(books!=NULL){
        fprintf(out,"%d %s %s %s %s %s %d %s %f %d\n", books->book.ISBM, books->book.titulo, books->book.idioma, books->book.primAutor, books->book.secAutor, books->book.editora, books->book.anoPub, books->book.area, books->book.preco, books->book.stock);
        writeLoopLivro(books->left,out);
        writeLoopLivro(books->right,out);
    }
}

void writeLivros(Tree books, char *path){
    Tree P = books;
    FILE *out;

    out = fopen(path,"w");

    if(out==NULL){
        return;
    }

    writeLoopLivro(P,out);

    fclose(out);
}