
/**
 * @file teste.c
*/
#include <stdio.h>

typedef struct intTree{
    int valor;
    struct LivroTree *left;
    struct LivroTree *right;
}*Tree;

int numFolhas(Tree t){

    if(t->left == NULL && t->right==NULL){
        return 1;
    }

    if(t->left == NULL){
        return numFolhas(t->right);
    }

    if(t->right == NULL){
        return numFolhas(t->left);
    }

    return numFolhas(t->left) + numFolhas(t->right);
}

int numIntervalo(int a, int b, Tree T){

    if(T==NULL){
        return 0;
    }

    if(T->valor > b){
        return numIntervalo(a,b,T->left);
    }

    if(T->valor < a){
        return numIntervalo(a,b,T->right);
    }

    return numIntervalo(a,b,T->right)+numIntervalo(a,b,T->left)+1;
}

int menoresK(int k, Tree T){

    if(T==NULL){
        return 0;
    }

    if(T->valor < k){
        return menoresK(k,T->left)+menoresK(k,T->right)+T->valor;
    }

    return menoresK(k,T->left)+menoresK(k,T->right);
}

int foraIntervalo(int a, int b, Tree T){

    if(T==NULL){
        return 0;
    }

    if(T->valor < b && T->valor > a){
        return foraIntervalo(a, b, T->right)+foraIntervalo(a,b, T->left);
    }

    return foraIntervalo(a, b, T->right)+foraIntervalo(a,b, T->left)+1;
}