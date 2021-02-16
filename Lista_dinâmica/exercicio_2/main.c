/*
Programa: Cadastro de funcionários
Autora: Ana Clara N. dos Santos
Concluido em: 15/01/2021
Descricao: O programa cadastra 8 funcionários em uma lista, por ordem decrescente de salário, após  isso imprime o nome do(s) funcionário(s) com maior salário, calcula a média salarial, e por último retorna o número de pessoas que recebem acima do valor fornecido pelo usuário.
*/

#include<stdio.h>
#include<stdlib.h>
#include"cadastro.h"

// Função principal do programa
int main (){
    int ok, i;
    float sal, x;
    Lista *li;

    li=criaLista();

      for(i=0; i<4; i++){
      
        coletaDados(li);

    }
    
    system("clear");

    imprimeLista(li);

    maiorSal(li);

    sal=mediaSAl(li);

    printf("\nMédia salarial: %f\n", sal);

    printf("\nInsira o salário a ser buscado no registro dos funcionários:");
    scanf(" %f", &x);

    ok= buscaSal(li, x);

    if( ok==0 ){

    printf("\nNenhum funcionário ganha acima do valor consultado.");
    }

    else{

    printf("\n%d funcionário têm o salário acima de %2.f.", ok, x);

    }

    liberaLista(li);

    printf("\nPrograma encerrando");

    return 0;

}
