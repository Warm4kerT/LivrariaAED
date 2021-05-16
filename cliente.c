#include "livraria.h"

Cliente newCliente(int NIF, int Telefone, char *Nome, Morada morada){
    Cliente new;
    new.NIF = NIF;
    new.telefone = Telefone;
    new.Nome = Nome;
    new.MinhaMorada = morada;
    return new;
}

Morada newMorada(char *Casa, char *Cidade, int COD1, int COD2){
    Morada new;
    new.Casa = Casa;
    new.Cidade = Cidade;
    new.CODPostal[0] = COD1;
    new.CODPostal[1] = COD2;
    return new;
}


void printMorada(Morada b){
    printf("Morada: %s  %s  %d-%d \n", b.Casa, b.Cidade, b.CODPostal[0], b.CODPostal[1]);
}
void printCliente(Cliente b){
    printf( "Nome: %s\n NIF: %d\n Telefone: %d\n", b.Nome, b.NIF, b.telefone);
        printMorada(b.MinhaMorada);
}

int equalsMorada(Morada a, Morada b){
    if((strcmp(a.Casa,b.Casa)>0)&&(strcmp(a.Cidade,b.Cidade)>0)){
        if((a.CODPostal[0] == b.CODPostal[0]) && (a.CODPostal[1]==b.CODPostal[1])){
            return 1;
        }
    }
    return 0;
}
int equalsCliente(Cliente a, Cliente b){
    if ((a.NIF == b.NIF)&&(a.telefone == b.telefone)&& (strcmp(a.Nome, b.Nome)>0)){
        if(equalsMorada(a.MinhaMorada,b.MinhaMorada)==1){
            return 1;
        } 
    }
    return 0; //not equals
}