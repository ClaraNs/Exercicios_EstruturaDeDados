#ifndef COM111___FUNCIONARIO_H
#define COM111___FUNCIONARIO_H

typedef struct funci Funci ;

typedef struct elemento Elemento;

typedef Elemento * Lista;

//Funções para alocar e desalocar memória
Lista * criaLista ();

int liberaLista (Lista *li);


//Funções para ler informações e inserir na lista
void preencheDado(Lista *li);

int insereOrdenado (Lista *li, char n[], float sal);


//Funções para receber char e buscar elementos a partir dele
void avaliaChar ( Lista *li, char x);

void buscaFunci (Lista *li, char x, char y);



//Funções para imprimir a lista
void imprimeLista (Lista *li);

void imprimeCrescenteDecrescente ( Lista *li);


#endif //COM11_fUNCIONARIO.H