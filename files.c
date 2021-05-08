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

    while (10==fscanf(in,"%d %s %s %s %s %s %d %s %le %d", &ISBM, titulo, idioma, primAutor, secAutor, editora, &anoPub, area, &preco, &stock)){ 

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
        fprintf(out,"%d %s %s %s %s %s %d %s %.3le %d\n", books->book.ISBM, books->book.titulo, books->book.idioma, books->book.primAutor, books->book.secAutor, books->book.editora, books->book.anoPub, books->book.area, books->book.preco, books->book.stock);
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

Fila readEncomenda(char *path){
    Fila P = createFila();
    Encomenda new;

    int ISBM, NIF, numUnidades, numEnc;
    double preco;
    Data enc, venda;

    FILE *in;
    in = fopen(path,"r");

    if(in==NULL)
        return P;

    while(10==fscanf(in,"%d %d %d %d %le %d/%d/%d %d/%d/%d",&numEnc,&ISBM,&NIF,&numUnidades,&preco, &enc.dia, &enc.mes, &enc.ano, &venda.dia, &venda.mes, &venda.ano)){
        new = newEncomenda(numEnc,ISBM,NIF,numUnidades,preco,enc,venda);

        P = addNodeFila(new,P);
        if(EOF==fgetc(in))
            break;
    }

    return P;
}

void writeEncomendas(Fila order, char *path){
    Fila P = order;
    FILE *out;

    out = fopen(path,"w");

    while (emptyFila(P)!=1){
        fprintf(out,"%d %d %d %d %le %d/%d/%d %d/%d/%d\n",P->order.numEnc,P->order.ISBMLivro,P->order.NIFCliente,P->order.numUnidades,P->order.preco,P->order.enc.dia,P->order.enc.mes,P->order.enc.ano,P->order.venda.dia,P->order.venda.mes,P->order.venda.ano);
        P = P->prox;
    }
}