/*
Programa: Cadastro e busca de funcionários por salário
Autora: Ana Clara N. dos Santos
Concluido em: 24/01/2021
Descricao: o programa insere os funcionários numa lista duplamente encadeada em ordem crescente de salário, calcula o imposto baseado no ganho do indivíduo, imprime todas essas informações, e a própria lista, tanto de ordem crescente como decrescente*/

#include<stdio.h>
#include"funcionario.h"

int main () {
    int i;
    char x;
    Lista *li;

    //Alocação dinâmica da lista
    li=criaLista();

    //laço para cadastrar 6 funcionários
    for(i=0; i<6; i++){

        preencheDado(li);

    }

    imprimeLista(li);

   
    printf("\n\nLetra inicial a ser buscada:");
    scanf(" %c", &x);

    //Passa o char como parâmetro para a função que gera seu correspondente ( maiúsculo ou minúsculo) e posteriormente chama a função de busca
    avaliaChar (li, x);

    imprimeCrescenteDecrescente(li);

    //Libera a memória anteriormente alocada
    liberaLista(li);

    return 0;
}