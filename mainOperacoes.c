#include "livraria.h"

ListaCompra vendasNumPeriodo(int mes, int ano){
    Lista P = mainLista;
    ListaCompra final = NULL;
    ListaCompra C = NULL;

    while(P!=NULL){
        C = P->Cli.lista;
        while(C!=NULL){
            if((C->dataVenda.mes == mes) && (C->dataVenda.ano == ano)){
                final = InserirInicioCompra(C->ISBN, C->quantidade, C->precoTotal, C->dataVenda, final);
            }
            C = C->Prox;
        }
        P = P->Prox;
    }
    
    return final;
}

void ultimaVendaLivro(int ISBN){
    Lista P = mainLista;
    ListaCompra C = NULL;
    Data final = newData(0,0,0);
    Data aux;

    while(P!=NULL){
        C = P->Cli.lista;
        while(C!=NULL){
            if(C->ISBN == ISBN){
                aux = C->dataVenda;

                if((aux.ano>=final.ano) && (aux.mes>=final.mes) && (aux.dia>=final.dia)){
                    final = aux;
                }
            }   
            C = C->Prox;
        }
        P = P->Prox; 
    }

    if(final.ano == 0 || final.dia == 0 || final.mes == 0){
        printf("Nunca foi vendido!\n\n");
    }else{
        printf("Ultima compra do Livro %d : %d/%d/%d\n\n",ISBN,final.dia,final.mes,final.ano);
    }

    
}

void quantidadeVendidaCliente(int NIF){
    Lista search = PesquisaPorm(mainLista,NIF);

    if(search == NULL){
        printf("Cliente não encontrado\n\n");
        return;
    }

    ListaCompra C = search->Cli.lista;
    int total = 0;

    while(C!=NULL){
        total = total + C->quantidade;
        C = C->Prox;
    }

    printf("Quantidade vendida ao Cliente %d : %d\n\n",NIF,total);

}


Tree LivrosMaisVendidosK(ListaCompra L, int k){
    ListaCompra P = L;
    ListaCompra T = NULL, searchL = NULL;
    Tree final, searchT;

    while(P!=NULL){
        if(PesquisaCompra(P->ISBN,T)==1){
            searchL = ProcurarAnteriorCompraISBN(P->ISBN,T)->Prox;
            searchL->quantidade = searchL->quantidade + P->quantidade;
        }else{
            T = InserirInicioCompra(P->ISBN, P->quantidade, P->precoTotal, P->dataVenda,T);
        }

        P = P->Prox;
    }

    T = bubbleSortCompra(T);

    for(int i = k+1; i>=0; i--){
        searchT = searchTreeISBN(mainTree,T->ISBN);
        final = addNodoTree(final,searchT->book);
        if(T->Prox == NULL){
            break;
        }
        T = T->Prox;
    }

    return final;
}

Tree AreaCientificaKRecentes(Tree t, int K){~
    K = 0;
    int i = 0;
    Livro l;
    char AC;
    printf(" Insira K Livros mais recentes: ");
    scanf("%i", K);
    while(i < K - 1){
        searchTreeAC(t, AC);
        }
    }
   
    