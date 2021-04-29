#include "livraria.h"

int main(){
    printf("Hello World!\n");

    char *file = "livros.txt";

    Tree books;
    int flag = 1;
    books = readLivros(file);

    if(flag==1){
        printTree(books);
    }else if(flag==-1){
        printf("ERROR READING!!!\n");
    }else{
        printf("Não sei\n");
    }

    return 0;
}