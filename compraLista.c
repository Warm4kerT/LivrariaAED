
/**
 * @file compraLista.c
*/
#include "livraria.h"

void printCompra(ListaCompra b){
	printf("ISBN: %d\n", b->ISBN);
	Tree livroaux = searchTreeISBN(mainTree, b->ISBN);
	printf( " ISBN: %d\n Nome: %s\n quantidade: %d\n Preço Total: %f\n Data de Venda: %d/%d/%d\n\n", b->ISBN, livroaux->book.titulo, b->quantidade, b->precoTotal, b->dataVenda.dia, b->dataVenda.mes, b->dataVenda.ano);
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
	ListaCompra P = (ListaCompra) malloc(sizeof(*P));

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
	ListaCompra P = NULL;
	P = CriarNodoCompra(ISBN, quantidade, precoTotal, data);
	if (P == NULL)
		return L;

	if(L == NULL){
		return P;
	}

	P->Prox = L;
	L = P;
	return L;
}

void ListarCompra(ListaCompra L){
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

ListaCompra ProcurarAnteriorCompraISBN (int ISBN, ListaCompra L){
  ListaCompra Ant = NULL; 
	while (L != NULL){
		Ant = L;
		L = L->Prox;
		if(L->ISBN == ISBN){
			break;
		}
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

int getSizeCompra(ListaCompra L){
	int i=0;
	while (L!=NULL){
		++i;
		L = L->Prox;
	}
	
	return i;
}

ListaCompra swapCompra(ListaCompra a, ListaCompra b, ListaCompra L){
	ListaCompra aAnt;
	
	if(equalsCompra(a,L)==1){
		a->Prox=b->Prox;
		b->Prox=a;
		L = b;
	}else{
		aAnt = ProcurarAnteriorCompra(a,L);
		aAnt->Prox = b;
		a->Prox = b->Prox;
		b->Prox = a;
	} 

	return L;
}

ListaCompra bubbleSortCompra(ListaCompra L){
	ListaCompra P = L;
	int size = getSizeCompra(P);

	for(int i=0;i < size-1;++i){

		for(int j=0; j< size-i-1; ++j){
			if(P->quantidade > P->Prox->quantidade){
				L = swapCompra(P,P->Prox,L);
			}else{
				P=P->Prox;
			}
		}
		P = L;
	}

	return L;
}