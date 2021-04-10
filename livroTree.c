#include "livraria.h"

typedef struct LivroTree{
    Livro book;
    struct LivroTree *left;
    struct LivroTree *right;
}*Tree;

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

int numNodos(Tree t){
    int l, r;
    if(t==NULL)
        return 0;

    l = numNodos(t->left);
    r = numNodos(t->right);

    return (r+l+1);
}