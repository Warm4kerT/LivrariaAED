#include "livraria.h"

Encomenda newEncomenda(int numEnc, int ISBN, int NIF, int quantidade, float preco, Data enc, Data venda){
    Encomenda new;
    new.numEnc = numEnc;
    new.ISBNLivro = ISBN;
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
    printf(" Numero de Encomenda: %d\n Livro (ISBN): %d\n Cliente (NIF): %d\n Numero de Unidades: %d\n Preço Total: %f\n Data Encomenda: %d/%d/%d\n Data Venda: %d/%d/%d\n\n",
            o.numEnc, o.ISBNLivro, o.NIFCliente, o.numUnidades, o.preco, o.enc.dia, o.enc.mes, o.enc.ano, o.venda.dia, o.venda.mes, o.venda.ano);
}