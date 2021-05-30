
/**
 * @file clienteLista.c
 * @brief Ficheiro com funções gerais para trabalhar sobre uma Lista simples (Cliente).
*/
#include "livraria.h"

Lista CriarNodoLista(Cliente CLI){
	Lista P;

	P = (Lista) malloc(sizeof(*P));

	if (P == NULL)
		return NULL;

    P->Cli = CLI;
	P->Prox = NULL;
	return P;
}	

Lista LibertarNodoLista(Lista L){	
	free(L);
	L = NULL;
    return L;
}
Lista InserirInicioLista(Cliente CLI,Lista L){
	Lista P = NULL;
	P = CriarNodoLista(CLI);

	if (P == NULL){
		printf("2\n");
		return L;
	}

	P->Prox = L;
	return P;
}

void ListarLista (Lista L){
	Lista P = L;
	while(P!=NULL){
		printCliente(P->Cli);
		
		if(P->Cli.lista!=NULL){
			printf("LISTA NAO NULL\n");
			ListarCompra(P->Cli.lista);
		}

		P = P->Prox;
	}
}

int PesquisaLista(int NIF,Lista L){
	while((L != NULL) && (L->Cli.NIF != NIF)){
        L = L->Prox;
	}
    
	if(L == NULL)
		return 0;
	else
		return 1;

}

Lista ProcurarAnteriorLista (Cliente X, Lista L){
  Lista  Ant = NULL; 
	while (L != NULL && equalsCliente(L->Cli, X) != 0){
	  Ant = L;
		L = L->Prox;
	} 
	return Ant;
}

// remover X da lista L, em que X está na lista
Lista RemoverNodoLista (Cliente X, Lista L){ 
  Lista P, PAnt;
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

Lista FreeLista(Lista L){
    if(L == NULL) return NULL;
    L->Prox = FreeLista(L->Prox);
    return LibertarNodoLista(L);
}

Lista PesquisaPorm(Lista L, int NIF){
    Lista p;
    p = L;
    if(L==NULL) 
        return NULL;
    while(p != NULL){
        if(p->Cli.NIF == NIF){
            return p;
        }
		p = p->Prox;
    } return NULL;
}

int getSizeClientes(Lista L){
	int i = 0;

	while(L != NULL){
		++i;
		L = L->Prox;
	}
	
	return i;
}

Lista swapCliente(Lista a, Lista b, Lista L){
	Cliente aux;

	aux = a->Cli;
	a->Cli = b->Cli;
	b->Cli = aux;

	return L;
}

Lista bubbleSortClientes(Lista L){
	Lista P = L;
	Cliente aux;
	int size = getSizeClientes(P);
	int numA, numB;

	for(int i=0; i < size-1; ++i){
		for(int j=0; j < size-i-1; ++j){
			numA = getSizeCompra(P->Cli.lista);
			numB = getSizeCompra(P->Prox->Cli.lista);
			printf("%d/%d\n",numA,numB);
			if(numA > numB){
				
				aux = P->Cli;
				P->Cli = P->Prox->Cli;
				P->Prox->Cli = aux;
			}else{
				P = P->Prox;
			}
		}
		P = L;
	}

	return L;

}
