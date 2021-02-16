/* Programa: Listagem e atualização de estoque 
Autora: Ana Clara N. dos Santos
Concluido em: 14/01/2021
Descricao: O programa cadastra 5 produtos e atualiza seus preços, recebidos anteriormente, com base no 
desconto requerido pelo usuário.
*/

#include<stdio.h>
#include<stdlib.h>
#include"produto.h"

int main (){
    //Declaração das variáveis principais e auxiliares usadas no programa 
    Lista *li=NULL;
    int cod, qtd;
    int i, ok;
    float val, des;
    
    //aloca a lista dinamicamente
    li=criarLista();

    //Laço para inserir 5 produtos na lista
    for(i=0; i<5; i++){

      criaProd(li);

    }

    system("clear");

    printf("\nInsira a porcentagem a ser descontada:");
    scanf(" %f", &des);

    ok=aplicaDesconto(li, des);

    if( ok != 1){

      printf("\nPreços não foram atualizados");

    }

    else {

    printf("\nO desconto de %.2f%% foi aplicado ao estoque\n", des);

    imprimeLista(li);

    }

    //Libera a memória alocada
    destruirLista(li);

    printf("\nProcesso finalizado.");

    return 0;
}