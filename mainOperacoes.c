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

                if( aux.ano > final.ano ){
                    final = aux;
                }else if( aux.ano == final.ano){
                    if( aux.mes > final.mes ){
                        final = aux;
                    }else if( aux.mes == final.mes ){
                        if( aux.dia > final.dia ){
                            final = aux;
                        }else if( aux.dia == final.dia ){
                            final = aux;
                        }
                    }
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

int wastedLoopTree(Tree T){

    if(T==NULL){
        return 0;
    }

    int count = 0;

    count = count + (30 - strlen(T->book.titulo));
    count = count + (30 - strlen(T->book.primAutor));
    count = count + (30 - strlen(T->book.secAutor));
    count = count + (30 - strlen(T->book.editora));
    count = count + (30 - strlen(T->book.area));
    count = count + (30 - strlen(T->book.idioma));

    return wastedLoopTree(T->left) + wastedLoopTree(T->right) + count;
}

int wastedMemory(){
    Lista P = mainLista;
    Tree T = mainTree;

    int total, clientes = 0, livros = 0;


    while (P!=NULL){
        clientes = clientes + (30 - strlen(P->Cli.Nome));
        clientes = clientes + (30 - strlen(P->Cli.MinhaMorada.Casa));
        clientes = clientes + (30 - strlen(P->Cli.MinhaMorada.Cidade));

        P = P->Prox;
    }

    livros = wastedLoopTree(T);
    
    total = livros*sizeof(char) + clientes*sizeof(char);
    
    return total;
}

Cliente bigSpender(int ano, int mes){
    Lista P = mainLista;
    ListaCompra C = NULL;
    Cliente bigTimeSpender;
    float shmoney = 0, aux = 0;

    while (P!=NULL){
        C = P->Cli.lista;

        if(C!=NULL){
            while(C!=NULL){
                if(C->dataVenda.ano == ano && C->dataVenda.mes == mes){
                    aux = aux + C->precoTotal;
                }
                
                C = C->Prox;
            }
            printf("%s\n", P->Cli.Nome);
            if(aux > shmoney){
                shmoney = aux;
                bigTimeSpender = newCliente(0,0,"NULL",newMorada("NULL","NULL",0000,000));
                bigTimeSpender = newCliente(P->Cli.NIF,P->Cli.telefone,P->Cli.Nome,P->Cli.MinhaMorada);
            }
        }
        
        P = P->Prox;
    } 

    return bigTimeSpender;
}

int numLivrosComprados(Cliente P){
    ListaCompra C = P.lista;
    int numL = 0;

    while(C != NULL){
        numL = numL + C->quantidade;
        C = C->Prox;
    }
    
    return numL;
}

Cliente maisLivrosComprados(){
    Lista P = mainLista;
    Cliente cli;
    int aux = 0, final = 0;

    while(P != NULL){
        aux = numLivrosComprados(P->Cli);
        if(final < aux){
            final = aux;
            cli = P->Cli;
        }

        P = P->Prox;
    }

    return cli;
}
