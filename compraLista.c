#include "livraria.h"

void printCompra(ListaCompra b){
	ListaCompra list = b;
	Tree livroaux;
	livroaux = searchTreeISBM(mainTree, list->ISBM);
	printf( "ISBM: %d\n Nome: %s\n quantidade: %d\n Preço Total: %f\n Data de Venda: %d/%d/%d\n\n", list->ISBM, livroaux->book.titulo, list->quantidade, list->precoTotal, list->dataVenda.dia, list->dataVenda.mes, list->dataVenda.ano);
}

ListaCompra FreeCompra(ListaCompra l){
	l->Prox = NULL;
	free(l);
	l = NULL;
	
	return l;
}

int equalsCompra(ListaCompra a, ListaCompra b){
        if((a->ISBM == b->ISBM) && (a->quantidade==b->quantidade)){
            return 1;
        }
    return 0;
}

ListaCompra CriarNodoCompra(int ISBM, int quantidade, float precoTotal, Data data){
	ListaCompra P;

	P = (ListaCompra) malloc(sizeof(struct Compra));

	if (P == NULL)
		return NULL;

    P->ISBM = ISBM;
    P->quantidade = quantidade;
	P->dataVenda = data;
	P->precoTotal = precoTotal;
	P->Prox = NULL;
	return P;
}	

ListaCompra LibertarNodoCompra(ListaCompra L){	
	free(L);
	L = NULL;
    return L;
}

ListaCompra InserirInicioCompra(int ISBM, int quantidade, float precoTotal, Data data, ListaCompra L){
	ListaCompra P;
	P = CriarNodoCompra(ISBM, quantidade, precoTotal, data);
	if (P == NULL)
		return L;
	P->Prox = L;
	L = P;
	return L;
}

void ListarCompra (ListaCompra L){
	while(L!=NULL){
		printCompra(L);
		L = L->Prox;
	}
}

int PesquisaCompra(int ISBM,ListaCompra L){
	while((L != NULL) && (L->ISBM == ISBM)){
        L = L->Prox;
	}
    
		if(L == NULL)
			return 0;
		else
			return 1;

}

ListaCompra ProcurarAnteriorCompra (int ISBM, ListaCompra L){
  ListaCompra Ant = NULL; 
	while (L != NULL && (L->ISBM == ISBM)){
	  Ant = L;
		L = L->Prox;
	} 
	return Ant;
}

ListaCompra FreeListaCompras(ListaCompra L){
    if(L == NULL) return NULL;
    L->Prox = FreeCompra(L->Prox);
    return LibertarNodoCompra(L);
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