
/**
 * @file files.c
*/
#include "livraria.h"

Tree readLivros(char *path){

    Tree books = NULL;
    Livro new;

    int ISBN, anoPub, stock;
    float preco;
    char *titulo = (char*) malloc(allocSize*sizeof(char));
    char *idioma = (char*) malloc(allocSize*sizeof(char));
    char *primAutor = (char*) malloc(allocSize*sizeof(char)); 
    char *secAutor = (char*) malloc(allocSize*sizeof(char));
    char *editora = (char*) malloc(allocSize*sizeof(char));
    char *area = (char*) malloc(allocSize*sizeof(char));

    FILE *in;
    in = fopen(path,"r");

    if(in==NULL){
        return NULL;
    }

    while (10==fscanf(in,"%d %s %s %s %s %s %d %s %f %d", &ISBN, titulo, idioma, primAutor, secAutor, editora, &anoPub, area, &preco, &stock)){ 

        new = newLivro(ISBN, anoPub, stock, preco, titulo, idioma, primAutor, secAutor, editora, area);

        books = addNodoTree(books,new);

        titulo = (char*) malloc(allocSize*sizeof(char));
        idioma = (char*) malloc(allocSize*sizeof(char));
        primAutor = (char*) malloc(allocSize*sizeof(char)); 
        secAutor = (char*) malloc(allocSize*sizeof(char));
        editora = (char*) malloc(allocSize*sizeof(char));
        area = (char*) malloc(allocSize*sizeof(char));

        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return books;
}

void writeLoopLivro(Tree books, FILE *out){
    if(books!=NULL){
        fprintf(out,"%d %s %s %s %s %s %d %s %f %d\n", books->book.ISBN, books->book.titulo, books->book.idioma, books->book.primAutor, books->book.secAutor, books->book.editora, books->book.anoPub, books->book.area, books->book.preco, books->book.stock);
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

ListaCompra readCompras(char *path){
    ListaCompra lCompras = NULL;
    Data newD;
    int ISBN, quantidade;
    float precoTotal;
    int ano,mes,dia;
    FILE *compras;
    
    compras = fopen(path,"r");

    if(compras == NULL){
        printf("ITS NULL\n");
        return NULL;
    }

    while(6==fscanf(compras,"%d %d %f %d/%d/%d",&ISBN,&quantidade,&precoTotal,&dia,&mes,&ano)){
        newD = newData(dia,mes,ano);
        lCompras = InserirInicioCompra(ISBN,quantidade,precoTotal,newD,lCompras);
        if(EOF==fgetc(compras)){
            fclose(compras);
            break;
        }
    }

    return lCompras;

}

Lista readClientes(char *path){
    char *pathCompras =(char*) malloc(allocSize*sizeof(char));
   
    Lista clientes = NULL;
    Lista aux = (Lista) malloc(sizeof(*aux));
    Cliente newC;
    Morada newM;
    
    int NIF, telefone;
    char *nome = (char*) malloc(allocSize*sizeof(char));
    char *casa = (char*) malloc(allocSize*sizeof(char));
    char *cidade = (char*) malloc(allocSize*sizeof(char)); 
    int cod1, cod2;

    FILE *in;
    in = fopen(path,"r");

    if(in==NULL){
        return NULL;
    }

    while(7 == fscanf(in," %d %d %s %s %s %d-%d", &NIF, &telefone, nome, casa, cidade, &cod1, &cod2)){ 
        newM = newMorada(casa,cidade,cod1,cod2);
        newC = newCliente(NIF,telefone,nome,newM);

        sprintf(pathCompras,"Compras/%d.txt",NIF);

        newC.lista = readCompras(pathCompras);

        clientes = InserirInicioLista(newC,clientes);

        pathCompras = (char*) malloc(allocSize*sizeof(char));
        nome = (char*) malloc(allocSize*sizeof(char));
        casa = (char*) malloc(allocSize*sizeof(char));
        cidade = (char*) malloc(allocSize*sizeof(char));

        if(EOF==fgetc(in))
            break;
    }
    
    fclose(in);

    return clientes;
}

void writeCompras(ListaCompra lista, char *path){
    FILE *out;
    remove(path);
    out = fopen(path,"w+");

    printf("path: %s\n",path); 

    if(out==NULL){
        return;
    }

    while(lista != NULL){
        fprintf(out,"%d %d %f %d/%d/%d\n",lista->ISBN,lista->quantidade,lista->precoTotal,lista->dataVenda.dia,lista->dataVenda.mes,lista->dataVenda.ano);
        lista = lista->Prox;
    }

    fclose(out);
}

void writeClientes(Lista clientes, char *path){
    Lista P = clientes;
    char *pathCompras = (char*) malloc(allocSize*sizeof(char));
    FILE *out;
    out = fopen(path,"w");

    if(out==NULL){
        return;
    }

    while(P!=NULL){
        fprintf(out,"%d %d %s %s %s %d-%d\n", P->Cli.NIF, P->Cli.telefone, P->Cli.Nome, P->Cli.MinhaMorada.Casa, P->Cli.MinhaMorada.Cidade, P->Cli.MinhaMorada.CODPostal[0], P->Cli.MinhaMorada.CODPostal[1]);
        sprintf(pathCompras,"Compras/%d.txt",P->Cli.NIF);
        writeCompras(P->Cli.lista,pathCompras);
        P = P->Prox;
    }

    fclose(out);

}