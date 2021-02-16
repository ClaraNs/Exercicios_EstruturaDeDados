#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista_alunos.h"

//Definição da estrutura aluno
struct aluno {
    char nome[20];
    float nf;
};

struct elemento{

    Aluno dado;
    Elemento *prox;
    Elemento *ante;

};

//Função para alocar dinamicamente uma lista
Lista* criaLista (){
    Lista *li;

    li=(Lista*) malloc (sizeof(Lista));

    if( li != NULL)
        *li=NULL;

    return li;
}

//Função para liberar a memória usada para lista
int liberaLista (Lista *li){

    if (li==NULL || *li==NULL)
        return 0;

    Elemento *aux;

    do{

        aux=*li;
        *li=(*li)->prox;

        free(aux);

    } while ( *li != NULL );

    free(li);

    return 1;
}

//Função responsável por receber o nome e a nota e passá-los como parâmetro para a função inserir
void preencheDado(Lista *li){
    int ok;
    char nome[20];
    float nota;

    printf("\nNome do aluno:");
    scanf(" %19[^\n]", nome);

    printf("\nNota final:");
    scanf(" %f", &nota);

    ok=insereLista(li, nome, nota);

    if(ok==0){
      printf("\nErro.");
    }
    else{
      printf("\nAluno cadastrado com sucesso");
    }

}

//Função que insere o novo elemento no fim da lista
int insereLista (Lista *li, char n[], float nf){

    if( li==NULL )
        return 0;

    Elemento *no, *aux;

    no=(Elemento*)malloc(sizeof(Elemento));

    strcpy(no->dado.nome, n);
    no->dado.nf= nf;

    //O novo elemento será adicionado ao fim da fila
    no->prox=NULL;

    //Verifica se alista está vazia
    if( *li == NULL){

        *li=no;
        no->ante=NULL;
    }

    else{

    aux=*li;

    //laço percorre a lista até seu último elemento ser apontado
    while ( aux->prox != NULL ){

        aux= aux->prox;

    }
    
    //Insere o novo elemento no final "convencional" da lista
    no->ante= aux;
    aux->prox=no;

    }

    return 1;
}

//Função para imprimir a lista
void imprimeLista (Lista *li){

    if(li==NULL || *li==NULL){
        printf("\n\nLista Vazia ou inexistente");
    }

    Elemento *aux;

    aux=*li;

    while( aux != NULL ){

        printf("\nNome: %s", aux->dado.nome);
        printf("\nNota: %2.f", aux->dado.nf);
        printf("\n");

        aux=aux->prox;
    }
}

//função que imprime o nome dos aprovados
void imprimeAprovados (Lista *li){

    if(li==NULL || *li==NULL){
        printf("\n\nLista Vazia ou inexistente");
    }

    Elemento *aux;
    int cnt=0;

    aux=*li;

    printf("\nAlunos aprovados:");

    while( aux != NULL ){

        if( aux->dado.nf >= 7 ){

        printf("\n%s", aux->dado.nome);

        cnt ++;
        }


        aux=aux->prox;
    }

    if( cnt == 0 )
        printf("\nNão há");
}