#include "livraria.h"

Tree newNode(Livro *book){
    Tree n = (Tree) malloc(sizeof(struct LivroTree));
    n->book = *book;
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

int numNodeT(Tree t){
    int l, r;
    if(t==NULL)
        return 0;

    l = numNodeT(t->left);
    r = numNodeT(t->right);

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

Tree addNodoTree(Tree t, Livro l){
    if(t==NULL){
        t = newNode(&l);
        return t;
    }

    int numL = numNodeT(t->left);
    int numR = numNodeT(t->right);

    if(numL == numR || numL < numR)
        t->left = addNodoTree(t->left,l);
    else
        t->right = addNodoTree(t->right,l);

    return t;
}