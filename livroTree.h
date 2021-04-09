#include "livraria.h"

struct livroTree{
    Livro book;
    struct livroTree *left;
    struct LivroTree *right;
}

LivroTree criaNodo(Livro book){
    LivroTree n = NULL;
    n->book = book;
    n->left = null;
    n->right = null;
    
    return n;
}

LivroTree freeNode(LivroTree n){
    n->left = NULL;
    n->right = NULL;
    free(n);
    n = NULL;
    
    return n;
}

LivroTree freeTree(LivroTree t){
    if(t==NULL)
        return NULL;
    
    t->left = freeTree(t->left);
    t->right = freeTree(t->right);

    return freeNode(t);
}

int numNodos(LivroTree t){
    int l, r;
    if(t==NULL)
        return 0;

    l = numNodos(t->left);
    r = numNodos(t->right);

    return (r+l+1);
}