#include "livraria.h"

Encomenda newEncomenda(int ISBM, int NIF, int quantidade, double preco, Data enc, Data venda){
    Encomenda new;
    new.ISBMLivro = ISBM;
    new.NIFCliente = NIF;
    new.numUnidades = quantidade;
    new.preco = preco;
    new.enc = enc;
    new.venda = venda;

    return new;
}

Data newDate(int dia, int mes, int ano){
    Data new;
    new.dia = dia;
    new.mes = mes;
    new.ano = ano;

    return new;
}

void printEncomenda(Encomenda o){
    printf(" Livro (ISBM): %d\n Cliente (NIF): %d\n Numero de Unidades: %d\n Preço Total: %le\n Data Encomenda: %d/%d/%d\n Data Venda: %d/%d/%d\n\n",
            o.ISBMLivro, o.NIFCliente, o.numUnidades, o.preco, o.enc.dia, o.enc.mes, o.enc.ano, o.venda.dia, o.venda.mes, o.venda.ano);
}