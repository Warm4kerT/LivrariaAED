/**
 * @file livroTree.c
 * @brief Ficheiro com funções gerais para trabalhar sobre uma Árvore Binária de Pesquisa Balanceada (Livro). 
*/

#include "livraria.h"

Tree newNode(Livro book){
    Tree n = (Tree) malloc(sizeof(struct LivroTree));
    if (n==NULL){
        return NULL;
    }

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

int numNodeT(Tree t){
    int l, r;
    if(t==NULL)
        return 0;

    l = numNodeT(t->left);
    r = numNodeT(t->right);

    return (r+l+1);
}

int heightTree(Tree t){
    int e, d;
    if(t == NULL)
        return -1;

    e = heightTree(t->left);
    d = heightTree(t->right);
    
    if(e > d){
        return (e+1);
    }else{
        return (d+1);
    }
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

    if(equalsLivro(l , t->book)==1)
        return t;

    n = searchTree(l,t->left);
    if(n!=NULL)
        return n;
    
    return searchTree(l,t->right);
}

   
Tree searchTreeISBN(Tree t, int ISBN){
    Tree n;
    if(t==NULL)
        return NULL;

    if((t->book.ISBN) == ISBN)
        return t;

    n = searchTreeISBN(t->left,ISBN);
    if(n!=NULL)
        return n;
    
    return searchTreeISBN(t->right,ISBN);
}

void searchTreeAC(Tree t, Tree *Final, char *AC){
    if (t==NULL){
        Final = NULL;
        return;
    }

    if(strcmp(t->book.area,AC) != 0){
        *Final = addNodoTree(*Final,t->book);
    }

    searchTreeAC(t->left,Final,AC);
    searchTreeAC(t->right,Final,AC);
}

Tree searchLeafTree(Tree t, Livro *out){
    if(t->left == NULL && t->right){
        *out = t->book;
        return t;
    }

    if(heightTree(t->left)>heightTree(t->right))
        return searchLeafTree(t->left,out);
    else
        return searchLeafTree(t->right,out);
}

Tree addNodoTree(Tree t, Livro l){
    
    if(t==NULL){
        t = newNode(l);
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

Tree removeNodeAux (Tree t){
    Tree p, r;
    Livro l;

    if(t->left == NULL && t->right == NULL){
        t = freeNode(t);
        return t;
    }

    if(t->left == NULL){
        r=t;
        t=t->right;
        r=freeNode(r);
        return t;
    }

    if(t->right == NULL){
        r=t;
        t=t->left;
        r=freeNode(r);
        return t;
    }

    p = searchLeafTree(t,&l);
    p = freeNode(p);
    t->book = l;
    return t;
}

Tree removeNodeTree (Tree t, Livro l) {
    Tree p;
    if (t == NULL)
        return NULL;
    if (equalsLivro(t->book, l) == 0) {
        t = removeNodeAux(t);
        return t;
    }
    p = searchTree(l,t->left);
    if (p != NULL){
        t->left = removeNodeTree(t->left, l);
    }
    else{
        t->right = removeNodeTree(t->right, l);
    }
    return t;
}