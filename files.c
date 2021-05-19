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

Lista readClientes(char * path){
    Compra lCompras = NULL;
    int ISBM, quantidade;
    char *pathCompras =(char*) malloc(30*sizeof(char));
    FILE *compras;
   
    Lista clientes = NULL;
    Cliente newC;
    Morada newM;
    
    int NIF, telefone;
    char *nome = (char*) malloc(30*sizeof(char));
    char *casa = (char*) malloc(30*sizeof(char));
    char *cidade = (char*) malloc(30*sizeof(char)); 
    int cod1, cod2;

    FILE *in;
    in = fopen(path,"r");

    if(in==NULL){
        return NULL;
    }

    while (7==fscanf(in,"%d %d %s %s %s %d-%d ", &NIF, &telefone, nome, casa, cidade, &cod1, &cod2)){ 
        newM = newMorada(casa,cidade,cod1,cod2);
        newC = newCliente(NIF,telefone,nome,newM);

        sprintf(pathCompras,"Compras/%d.txt",NIF);
        compras = fopen(pathCompras,"r");

        if(compras!=NULL){
            while(2==fscanf(compras,"%d %d",&ISBM,&quantidade)){
                lCompras = InserirInicioCompra(ISBM,quantidade,lCompras);
                if(EOF==fgetc(in))
                    break;
            }
            fclose(compras);
        }

        newC.lista = lCompras;
        clientes = InserirInicioLista(newC,clientes);

        lCompras = NULL;
        pathCompras = (char*) malloc(30*sizeof(char));
        
        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return clientes;
}

void writeCompras(Compra lista, char *path){
    FILE *out;
    out = fopen(path,"w");

    if(out==NULL){
        return;
    }

    while(lista!=NULL){
        fprintf(out,"%d %d",lista->ISBM,lista->quantidade);
        lista = lista->Prox;
    }

    fclose(out);
}

void writeClientes(Lista clientes, char *path){
    Lista P = clientes;
    char *pathCompras = (char*) malloc(30*sizeof(char));
    FILE *out;
    out = fopen(path,"w");

    if(out==NULL){
        return;
    }

    while(P!=NULL){
        fprintf(out,"%d %d %s %s %s %d-%d ", P->Cli.NIF, P->Cli.telefone, P->Cli.Nome, P->Cli.MinhaMorada.Casa, P->Cli.MinhaMorada.Cidade, P->Cli.MinhaMorada.CODPostal[0], P->Cli.MinhaMorada.CODPostal[1]);
        sprintf(pathCompras,"Compras/%d.txt",P->Cli.NIF);
        writeCompras(P->Cli.lista,pathCompras);
    }

    fclose(out);

}