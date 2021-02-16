#ifndef COM111___EXERCICIOS_LIBRARY_H
#define COM111___EXERCICIOS_LIBRARY_H

typedef struct elemento Elemento;

typedef struct elemento * Lista;

typedef struct produto Produto;

//Funções para alocar e liberar memória
Lista* criarLista ();

Elemento* criaEle ();

void criaProd (Lista *li);

int destruirLista (Lista *li);

//Função para inserir elementos a lista
int inserirListaFinal (Lista *li, int cod, int qnt, float val);

//Função para imprimir lista na tela
void imprimeLista (Lista *li);

//Função para atualizar preços
int aplicaDesconto (Lista *li, float x);


#endif //COM111___EXERCICIOS_LIBRARY_H

