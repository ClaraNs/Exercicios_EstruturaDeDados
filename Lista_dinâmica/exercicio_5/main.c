/*
Programa: 
Autora: Ana Clara N. dos Santos
Concluido em: /01/2021
Descricao: O programa cadastra 20 números, e os armazena em duas listas, de acordo com sua classifcação (par ou impar), depois insere todos os números em uma lista de forma crescente, por fim os imprime em ordem crescente e decrescente.
*/

#include<stdio.h>
#include"lista.h"

#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main (){
  int i;
  Lista *lpar, *limpar, *li;

  lpar=criaLista();
  limpar=criaLista();

  if( lpar == NULL || limpar == NULL)
  {
    printf("\nListas não foram alocadas corretamente!");
  }

  for( i=0; i<20; i++){

    defineLista(lpar, limpar);

  }

  printf("\nLista par:");
  imprimeLista(lpar);

  printf("\nLista impar:");
  imprimeLista(limpar);

  li=criaLista();

  if( li == NULL)
  {
    printf("\nLista não foi alocadas corretamente!");
  }

  //Chama função para inserir elementos da lista atual para a final
  insereListaPrincipal(li, lpar);
  insereListaPrincipal(li, limpar);

  //Imprime lista de fforma crescente e decrescente
  imprimeCrescenteDecrescente(li);
  
  return 0;
}
