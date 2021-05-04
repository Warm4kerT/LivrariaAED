#include "livraria.h"

Fila createNodeFila(Encomenda order){
    Fila P;
    P = (Fila) malloc(sizeof(struct FilaEnc));
    if(P == NULL)
        return P;

    P->order = order;
    P->prox = NULL;
    return P;
}

Fila freeNodeFila(Fila F){
    free(F);
    F = NULL;
    return F;
}

int emptyFila(Fila F){
    if(F == NULL){
        return 1;
    }else{
        return 0;
    }
}

Fila createFila(){
  Fila P;
  P = NULL;
  return P;
}

Fila addNodeFila(Encomenda order, Fila F){
    Fila New, PAnt;
    New = createNodeFila(order);
    if(New == NULL)
        return F;
    
    if(emptyFila(F)){
        F = New;
        return F;
    }

    PAnt = F;
    while (PAnt->prox != NULL){
        PAnt = PAnt->prox;
    }

    PAnt->prox = New;
    return F;
}

Fila removeFila(Fila F){
    Fila P;
    P = F;
    F = F->prox;
    P = freeNodeFila(P);
    return F;
}

Encomenda front(Fila F){
    return F->order;
}