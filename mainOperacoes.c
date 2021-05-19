#include "livraria.h"

void vendasNumPeriodo(int mes, int ano){
    Lista P = mainLista;
    Compra C = NULL;

    while(P!=NULL){
        C = P->Cli.lista;
        while(C!=NULL){
            if((C->dataVenda.mes == mes) && (C->dataVenda.ano == ano)){
                printCompra(C);
            }
        }
        P = P->Prox;
    }
}

void ultimaVendaLivro(int ISBM){
    Lista P = mainLista;
    Compra C = NULL;
    Data final = newData(0,0,0);
    Data aux;

    while(P!=NULL){
        C = P->Cli.lista;
        while(C!=NULL){
            if(C->ISBM == ISBM){
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
        printf("Ultima compra do Livro %d : %d/%d/%d\n\n",ISBM,final.dia,final.mes,final.ano);
    }

    
}

void quantidadeVendidaCliente(int NIF){
    Lista search = PesquisaPorm(mainLista,NIF);

    if(search == NULL){
        printf("Cliente não encontrado\n\n");
        return;
    }

    Compra C = search->Cli.lista;
    int total = 0;

    while(C!=NULL){
        total = total + C->quantidade;
        C = C->Prox;
    }

    printf("Quantidade vendida ao Cliente %d : %d\n\n",NIF,total);

}