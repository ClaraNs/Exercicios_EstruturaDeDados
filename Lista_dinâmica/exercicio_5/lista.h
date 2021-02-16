#ifndef COM111_LISTA_H
#define COM111_LISTA_H

typedef struct elemento Elemento;

typedef  Elemento* Lista;

//Funções para alocar e desalocar memória
Lista * criaLista ();

Elemento * criaElemento ();

int liberaLista (Lista *li);


//Função para definir qual lista inserir
void defineLista ( Lista *par, Lista *impar);


//Função para inserir novo elemento
int insereFinal (Lista *li, int nmr);

int insereOrdenado ( Lista *li, int dado);

void insereListaPrincipal(Lista *principal, Lista *li);


void imprimeLista (Lista *li);

void imprimeCrescenteDecrescente ( Lista *li);


#endif //COM111_LISTA_H