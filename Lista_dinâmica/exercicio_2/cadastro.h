#ifndef COM111___CADASTRO_H
#define COM111___CADASTRO_H

typedef struct funci Funci;

typedef struct elemento Elemento;

typedef struct elemento * Lista;


//Funções para alocar e desalocar memória
Lista * criaLista ();

Elemento * criaElemento ();

int liberaLista (Lista *li);


//Função que recebe uma string e um float para o regristo do funcionário
void coletaDados (Lista *li);


//Função para inserir os funcionários, baseado em seu salário
int insereListaOrdenado (Lista *li, char n[], float sal);


//Função para imprimir na tela a lista
void imprimeLista (Lista *li);


//Funções para obter informações da lista

void maiorSal (Lista *li);

float mediaSAl (Lista *li);

int buscaSal (Lista *li, float x);



#endif // COM111___CADASTRO_H