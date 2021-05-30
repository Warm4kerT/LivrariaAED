@page sum Page − Descrição de Algoritmos

1. Algoritmo Número 1:
 @code 
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
@endcode
Explicação: 

2. Algoritmo Número 2:
@code 
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
@endcode
Explicação: 

3.  Algoritmo Número 3:
@code 
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
@endcode
Explicação: 

4.  Algoritmo Número 4:
@code 
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
@endcode
Explicação: 

5.  Algoritmo Número 5:
@code 
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
@endcode
Explicação: 

6.  Algoritmo Número 6:
@code 
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
@endcode
Explicação: 

7.  Algoritmo Número 7:
@code
int numLivrosComprados(Cliente P){
    ListaCompra C = P.lista;
    int numL = 0;

    while(C != NULL){
        numL = numL + C->quantidade;
        C = C->Prox;
    }
    
    return numL;
}
@endcode
Explicação:

8.  Algoritmo Número 8:
@code
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
@endcode
Explicação:

9.  Algoritmo Número 9:
@code
Tree KRecentesAC (Tree T, Livro l){
    int K = 0, i;
    Tree AC = T;
    char AreaC[allocSize];
    printf("Área Científca a ser pesquisada -> ");
    scanf("%s", &AreaC[allocSize]);
    printf("\nIntroduza o valor 'k' Livros mais recentes da Área pretendida");
    scanf("%i", K);
    while(i < K - 1){
        if(T==NULL)
            return NULL;
    
        if(strcmp(l.area , AreaC[allocSize])==0){
            printLivro(T->book);
            i++; 
        }

        AC = searchTree(l, T->left);
        if(AC!=NULL)
            return AC;

        return searchTree(l, T->right);
    }
}
@endcode
Explicação:

10.  Algoritmo Número 10:
@code
int contagemPorAno(Tree T, int ano){
    if(T==NULL){
        return 0;
    }

    if(T->book.anoPub == ano){
        return contagemPorAno(T->left,ano)+contagemPorAno(T->right,ano)+1;
    }

    return contagemPorAno(T->left,ano)+contagemPorAno(T->right,ano);
}

int anoMaisPublicacoes(){
    int aux = 0, num, anoFinal, anoInicial = 2010;

    while (anoInicial<=2021){
        num = contagemPorAno(mainTree,anoInicial);

        if(num>aux){
            aux = num;
            anoFinal = anoInicial;
        }

        ++anoInicial;
    }


    return anoFinal;
}
@endcode
Explicação:

11.  Algoritmo Número 11:
@code
int contagemAreaCientifica(Tree T, char *area){
    if(T==NULL){
        return 0;
    }

    if(strcmp(T->book.area,area)==0){
        return contagemAreaCientifica(T->left,area)+contagemAreaCientifica(T->right,area)+1;
    }

    return contagemAreaCientifica(T->left,area)+contagemAreaCientifica(T->right,area);
}

void getAreas(Tree T, char **areas, int *size){

    int flag = 0;
    int i = 0;
    printf("%d\n",size);
    if(T==NULL){
        return;
    }

    if(size!=0){
        for(i = 0; i < (size-1);++i){
            printf("size!=0 %s\n",areas[i]);
            if(strcmp(areas[i],T->book.area)==0){
                flag = 1;
            }
        }
    }
    

    if(flag == 1){
        getAreas(T->left,areas,size);
        getAreas(T->right,areas,size);
    }else{
        printf("NOVA AREA\n");
        areas[i+1] = (char *) malloc(allocSize*sizeof(char));
        areas[i+1] = T->book.area;
        size = size+1;
        getAreas(T->left,areas,size);
        getAreas(T->right,areas,size);
    }
}

char *areaMaisLivros(){
    char **areas = (char**) malloc(allocSize*sizeof(char*));
    char *areaFinal = (char*) malloc(allocSize*sizeof(char));
    int size = 0, aux, final = 0;
    getAreas(mainTree,areas,size);


    printf("%d\n",size);

    for(int i = 0; i < (size-1); ++i){
        aux = contagemAreaCientifica(mainTree,areas[i]);
        printf("%s\n",areas[i]);
        if(aux > final){
            final = aux;
            areaFinal = areas[i];
        }
    }

    return areaFinal;
}
@endcode
Explicação:





