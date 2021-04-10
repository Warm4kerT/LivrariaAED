#include "livraria.h"

Tree criaNodo(Livro book){
    Tree n = (Tree) malloc(sizeof(struct LivroTree));
    n->book = book;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

Tree freeNode(Tree n){
    n->left = NULL;
    n->right = NULL;
    free(n);
    n = NULL;
    
    return n;
}

Tree freeTree(Tree t){
    if(t==NULL)
        return NULL;
    
    t->left = freeTree(t->left);
    t->right = freeTree(t->right);

    return freeNode(t);
}

int numNodosT(Tree t){
    int l, r;
    if(t==NULL)
        return 0;

    l = numNodosT(t->left);
    r = numNodosT(t->right);

    return (r+l+1);
}

void printTree(Tree t){
    if(t!=NULL){
        printLivro(t->book);
        printTree(t->left);
        printTree(t->right);
    }
}

Tree searchTree(Livro l, Tree t){
    Tree n;
    if(t==NULL)
        return NULL;

    if(equalsLivro(l,t->book)==1)
        return t;

    n = searchTree(l,t->left);
    if(n!=NULL)
        return n;
    
    return searchTree(l,t->right);
}