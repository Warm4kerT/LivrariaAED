
/**
 * @file livro.c
 * @brief Ficheiro de funções principais do livro. 
*/
#include "livraria.h"

Livro newLivro(int ISBN, int anoPub, int stock, float preco, char *titulo, char *idioma, char *primAutor, char *secAutor, char *editora, char *area){
    Livro new;
    new.ISBN = ISBN;
    new.anoPub = anoPub;
    new.stock = stock;
    new.preco = preco;
    new.titulo = titulo; 
    new.idioma = idioma; 
    new.primAutor = primAutor;
    new.secAutor = secAutor;
    new.editora = editora;
    new.area = area;

    return new;
}

Data newData(int dia, int mes, int ano){
    Data new;
    new.dia = dia;
    new.mes = mes;
    new.ano = ano;

    return new;    
}

void printLivro(Livro b){
    printf( " ISBN: %d\n Titulo: %s\n Idioma: %s\n Autor 1: %s\n Autor 2: %s\n Editora: %s\n Ano de Publicacao: %d\n Area Cientifica: %s\n Preco: %f\n Stock: %d\n\n", 
            b.ISBN, b.titulo, b.idioma, b.primAutor, b.secAutor, b.editora, b.anoPub, b.area, b.preco, b.stock);
}

int equalsLivro(Livro a, Livro b){
    if ((a.ISBN == b.ISBN)&&(a.anoPub == b.anoPub)&&(a.preco == b.preco)&&(a.stock == b.stock)){
        if(strcmp(a.titulo,b.titulo)>0 && strcmp(a.idioma,b.idioma)>0 && strcmp(a.primAutor,b.primAutor)>0){
            if(strcmp(a.secAutor,b.secAutor)>0 && strcmp(a.editora,b.editora)>0 && strcmp(a.area,b.area)>0){
                return 1;
            }
        }
    }

    return 0; //not equals
}