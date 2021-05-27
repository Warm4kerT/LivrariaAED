#include "livraria.h"

void printCompra(ListaCompra b){
	ListaCompra list = b;
	Tree livroaux;
	livroaux = searchTreeISBM(mainTree, list->ISBN);
	printf( "ISBN: %d\n Nome: %s\n quantidade: %d\n Preço Total: %f\n Data de Venda: %d/%d/%d\n\n", list->ISBN, livroaux->book.titulo, list->quantidade, list->precoTotal, list->dataVenda.dia, list->dataVenda.mes, list->dataVenda.ano);
}

ListaCompra FreeCompra(ListaCompra l){
	l->Prox = NULL;
	free(l);
	l = NULL;
	
	return l;
}

int equalsCompra(ListaCompra a, ListaCompra b){
        if((a->ISBN == b->ISBN) && (a->quantidade==b->quantidade)){
            return 1;
        }
    return 0;
}

ListaCompra CriarNodoCompra(int ISBN, int quantidade, float precoTotal, Data data){
	ListaCompra P;

	P = (ListaCompra) malloc(sizeof(struct Compra));

	if (P == NULL)
		return NULL;

    P->ISBN = ISBN;
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

ListaCompra InserirInicioCompra(int ISBN, int quantidade, float precoTotal, Data data, ListaCompra L){
	ListaCompra P;
	P = CriarNodoCompra(ISBN, quantidade, precoTotal, data);
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

int PesquisaCompra(int ISBN,ListaCompra L){
	while((L != NULL) && (L->ISBN != ISBN)){
        L = L->Prox;
	}
    
		if(L == NULL)
			return 0;
		else
			return 1;

}

ListaCompra ProcurarAnteriorCompraISBM (int ISBN, ListaCompra L){
  ListaCompra Ant = NULL; 
	while (L != NULL && (L->ISBN == ISBN)){
	  Ant = L;
		L = L->Prox;
	} 
	return Ant;
}

ListaCompra ProcurarAnteriorCompra(ListaCompra a, ListaCompra L){
	ListaCompra ant;
	while(L!=NULL && (equalsCompra(a,L)==0)){
		ant = L;
		L = L->Prox;
	}

	return ant;
}

ListaCompra FreeListaCompras(ListaCompra L){
    if(L == NULL) return NULL;
    L->Prox = FreeCompra(L->Prox);
    return LibertarNodoCompra(L);
}

void swapCompra(ListaCompra a, ListaCompra b, ListaCompra L){
	ListaCompra aAnt = ProcurarAnteriorCompra(a,L);
	ListaCompra bAnt = ProcurarAnteriorCompra(b,L);
	ListaCompra aux;

	aux = b->Prox;
	bAnt->Prox = a;
	b->Prox = a->Prox;
	a->Prox = aux;
	aAnt->Prox = b;
}

ListaCompra bubbleSortCompra(ListaCompra L){
	ListaCompra P = L;

	while (P->Prox!=NULL){
		if(P->quantidade < P->Prox->quantidade){
			swapCompra(P,P->Prox,L);
		}
		
		P=P->Prox;
	}

	return L;
}