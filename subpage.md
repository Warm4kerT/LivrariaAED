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
Explicação: Função de procura de compras num dado mês e ano. A função vai iterando na lista de Clientes e verifica cada lista de compras que o cliente contem. Se essa compra pertencer a esse mês e ano então adiciona a uma lista de Compras e no final devolve-a.

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
Explicação: Esta função procura a mais recente compra de um Livro especificado pelo utilizador. Tal como a função alterior procura em cada lista de Compras de cada Cliente. Se encontrar alguma compra com o ISBN dado pelo Utilizador então guarda essa Data, até encontrar uma mais recente com esses critérios. No final apresenta a data.

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
Explicação: Função simples de interpeção, conta o numero de Livros que um Cliente comprou. É invocada um função de pesquisa do Cliente dado pelo Utilizador e esse Cliente e guardado num apontador. Depois iteramos na lista de Compras contando o numero de livros. No final esse valor é apresentado.

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
Explicação: Nesta função recebemos já uma lista de Compras do mês e ano especificos e depois fazemos uma "condensação" dessa lista. Isto é removemos compras dos mesmos Livros guardando numa so compra a quantidade total de Livros vendidos numa so compra. Após esse processo organizamos a lista através de um BubbleSort e apresentamos k Livros através do ISBN da Compra. 

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
Explicação: Estas duas funções trabalham em conjunto para determinar a memória desperdiçada pelas estruturas de dados dos Livros e Clientes. Como o espaço reservado para cada String é a mesma, este calculo é simples de fazer. A primeira função calcula o espaço desperdiçado pela árvore e o segundo calcula o desperdicio dos Clientes e junta os dois valores e devolve a quantidade de bytes desperdiçados.

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
Explicação: Esta função procura faz o somatório de valor gasto dos Clientes num dado mês e ano, guardando sempre o maior valor gasto e o Cliente em questão. No final devolve o Cliente que mais gastou nesse período de tempo.

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
Explicação: Estas duas funções trabalham juntas para determinar que Cliente mais Livros comprou. A primeira determina o numero de Livros comprados por um Cliente expecifico. A segunda é o loop pela Lista de Clientes invocando a primeira função, guardando sempre o maior numero de livros e os eu respetivo Cliente. No final devolve o Cliente com mais Livros comprados.

8.  Algoritmo Número 8:
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
Explicação: Novamente duas funções que trabalham juntas para atingir um fim. A primeira faz a contagem de Livros num dado ano. A segunda vai verificar a quantidade de Livros para cada ano desde 2010 até 2021, devolvendo no final o ano com mais publicações.






