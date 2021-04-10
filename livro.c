#include "livraria.h"

void printLivro(Livro *b){
    printf( " ISBM: %d\n Titulo: %c\n Idioma: %c\n Autor 1: %s\n Autor 2: %s\n Editora: %s\n Ano de Publicacao: %d\n Area Cientifica: %s\n Preco: %f\n Stock: %d\n ", 
            b->ISBM, b->titulo, b->idioma, b->primAutor, b->secAutor, b->editora, b->anoPub, b->area, b->preco, b->stock);
}