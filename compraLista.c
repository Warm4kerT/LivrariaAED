#include "livraria.h"

void printCompra(Compra b){
	Compra list = b;
	Tree livroaux;
	while(list!=NULL){
		livroaux = searchTreeISBM(mainTree, list->ISBM);
		float PrecoTot = (livroaux->book.preco) * (list->quantidade);
		printf( "ISBM: %d\n Nome: %s\n quantidade: %d\n Preço Total: %f\n\n", list->ISBM, livroaux->book.titulo, list->quantidade, PrecoTot);
		livroaux = NULL;
		list = list->Prox;
	}
}

Compra FreeCompra(Compra l){
	l->Prox = NULL;
	free(l);
	l = NULL;
	
	return l;
}

int equalsCompra(Compra a, Compra b){
        if((a->ISBM == b->ISBM) && (a->quantidade==b->quantidade)){
            return 1;
        }
    return 0;
}

Compra CriarNodoCompra(int ISBM, int quantidade){
	Compra P;

	P = (Compra) malloc(sizeof(struct Compra));

	if (P == NULL)
		return NULL;

    P->ISBM = ISBM;
    P->quantidade = quantidade;
	P->Prox = NULL;
	return P;
}	

Compra LibertarNodoCompra(Compra L){	
	free(L);
	L = NULL;
    return L;
}
Compra InserirInicioCompra(int ISBM, int quantidade , Compra L){
Compra P;
	P = CriarNodoCompra(ISBM, quantidade);
	if (P == NULL)
		return L;
	P->Prox = L;
	L = P;
	return L;
}

void ListarCompra (Compra L){
	while(L!=NULL){
		printCompra(L);
		L = L->Prox;
	}
}

int PesquisaCompra(int ISBM,Compra L){
	while((L != NULL) && (equalsCompra((L->ISBM), ISBM)!= 0)){
        L = L->Prox;
	}
    
		if(L == NULL)
			return 0;
		else
			return 1;

}

Compra ProcurarAnteriorCompra (int ISBM, Compra L){
  Compra  Ant = NULL; 
	while (L != NULL && equalsCompra(L->ISBM, ISBM) != 0){
	  Ant = L;
		L = L->Prox;
	} 
	return Ant;
}

// remover X da lista L, em que X está na lista
/*
Compra RemoverNodoLista (Compra X, Compra L){ 
  Compra P, PAnt;
	PAnt = ProcurarAnteriorLista(X, L); 
	if (PAnt == NULL){   // remover elemento do início de L
	  P = L;
		L = L->Prox;
	} 
	else{
	  P = PAnt->Prox;
		PAnt->Prox = P->Prox; // ou (PAnt->Prox)->Prox
	} 
	LibertarNodoLista(P); 
	return  L;
}
*/

Compra FreeListaCompras(Compra L){
    if(L == NULL) return NULL;
    L->Prox = FreeCompra(L->Prox);
    return LibertarNodoCompra(L);
}

/*
Compra PesquisaPorm(Compra L, int NIF){
    Compra p;
    p = L;
    if(L==NULL) 
        return NULL;
    while(p != NULL){
        if(p->Cliente. == NIF){
            return p;
        }
    } return NULL;
}
*/