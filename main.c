#include "livraria.h"

int main(){
    printf("Hello World!\n");

    char *file = "livros.txt";

    Tree *books = (Tree*)malloc(sizeof(Tree));
    int flag = 0;
    flag = readLivros(file, books);

    if(flag==1){
        printTree(*books);
    }else if(flag==-1){
        printf("ERROR READING!!!\n");
    }else{
        printf("Não sei\n");
    }

    return 0;
}