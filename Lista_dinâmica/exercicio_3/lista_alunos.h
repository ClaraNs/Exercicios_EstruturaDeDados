#ifndef COM111___LISTA_ALUNOS_H
#define COM111___LISTA_ALUNOS_H

typedef struct aluno Aluno;

typedef struct elemento Elemento;

typedef Elemento* Lista;

//Funções para alocar e liberar memória
Lista * criaLista ();

int liberaLista (Lista *li);


//Funções para ler os dados e inserir na lista
void preencheDado(Lista *li);

int insereLista (Lista *li, char nome[], float nf);


//Funções para imprimir a lista na tela
void imprimeLista (Lista *li);

void imprimeAprovados (Lista *li);

#endif //COM11_LISTA_ALUNOS.H