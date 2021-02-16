#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

//Definição struct elemento
struct elemento
{

    Elemento *ante;
    int dado;
    Elemento *prox;

};

//Aloca uma lista dicamicamente
Lista * criaLista ()
{

    Lista *li;

    li=(Lista*) malloc (sizeof(Lista));

    return li;
}

//Aloca um elemento dicamicamente
Elemento * criaElemento ()
{
    Elemento *no;
    no=(Elemento *) malloc (sizeof(Elemento));

    return no;
}

//Libera memória
int liberaLista (Lista *li)
{
    
    if( li== NULL || *li==NULL)
    {
        return 0;
    }

    Elemento *aux;

    while(*li != NULL )
    {
        aux=*li;
        (*li)=(*li)->prox;
        free(aux);
    }

    free(li);

    return 1;
}

// Insere elemento o fim da lista
int insereFinal (Lista *li, int dado)
{

    if( li== NULL)
    {
        return 0;
    }

    Elemento *no=criaElemento();

    if(no==NULL)
    return 0;

    no->dado=dado;
    no->prox=NULL;

    if( *li== NULL)
    {
        *li= no;
    }

    else
    {
    
    Elemento *aux;

    aux=*li;

    while( aux->prox!= NULL)
    {
        aux= aux->prox;
    }

    aux->prox= no;
    }

    return 1;

}

//Classifica o elemento em par ou impar e chama a função de iserir na lista correspondente
void defineLista ( Lista *par, Lista *impar)
{   
    int ok, nmr;

    printf("\nInsira o número:\n");
    scanf(" %d", &nmr);

    //Verifica se o número é par
    if( nmr%2==0)
    {
        ok=insereFinal( par, nmr);
    }

    else
    {
        ok=insereFinal(impar,nmr);
    }

    if(ok == 0)
    {
        printf("\nErro na alocação de memória.\n");
    }

    else
    {
        printf("\nNovo elemento inserido com sucesso.\n");
    }
    
}

//Função para inserir elemento em ordem crescente
int insereOrdenado ( Lista *li, int dado)
{
    if( li == NULL)
    {
        return 0;
    }

    Elemento *no;
    no=criaElemento();

    if( no == NULL)
    {
      return 0;
    }

    no->dado = dado;

    //Verifica se a lista está vazia
    if( *li == NULL)
    {
        no->prox=NULL;
        no->ante=NULL;
        *li=no;
    }

    else
    {
        Elemento *ante, *atual;

        atual = *li;

        //Percorre a lista enquanto não atingir seu final e o valor for menor que o novo
        while( atual != NULL && atual->dado < no->dado )
        {
            ante = atual;
            atual = atual->prox;
        }

        //Verifica se o novo elemento será inserido no começo da lista
        if(atual == *li)
        {
            no->ante = NULL;
            (*li)->ante = no;
            no->prox = *li;
            *li = no;
        }

        else 
        {
            no->prox = ante->prox;
            no->ante = ante;
            ante->prox = no;

            //Verifica se o novo elemento será inserido no meio da lista
            if ( atual != NULL)
            {
                atual->ante=  no;
            }
        }
    }

    return 1;

}


void insereListaPrincipal(Lista *principal, Lista *li)
{   
    //Verifica se as listas foram alocadas
    if( principal == NULL )
    {
        printf("\nErro na alocação da lista principal.");
    }

    Elemento *no;
    int ok;

    //Inicializa o elemento auxiliar
    no=*li;

    //laço que percorre a lista até seu fim, chamando uma função para inserir cada um de seus elementos de forma ordenada em uma terceira lista
    while( no != NULL)
    {
        ok = insereOrdenado( principal, no->dado);

            if(ok == 0)
        {
            printf("\nErro na alocação de memória.");
        }

            if(ok == 1)
        {
            printf("\nNovo elemento inserido com sucesso.\n");
        }

        no = no->prox;
    }

}

void imprimeLista (Lista *li)
{
    if(li == NULL || *li == NULL)
    {
        printf("\nLista vazia ou não alocada\n");
    }

    Elemento *aux;

    aux=*li;

    while( aux != NULL)
    {
        printf("\n%d\n", aux->dado);

        aux=aux->prox;
    }
}

void imprimeCrescenteDecrescente ( Lista *li){

    if( li == NULL || *li == NULL){

        printf("\nLista vazia ou não alocada");
        
        return ;
    }

    Elemento *aux;

    //Inicializa o auxiliar no começo da lista
    aux=*li;

    printf("\nOrdem crescente:");

    //Percorre a lista até o último elemento
    while( aux->prox != NULL){

        printf("\n%d", aux->dado);
        printf("\n");

        aux= aux-> prox;
    }

    printf("\n%d", aux->dado);
    printf("\n");

    printf("\nOrdem decrescente:");

    //laço é iniciado quando o auxiliar é o último elemento e termina quando chega ao começo da lista
    while ( aux->ante != NULL){

        printf("\n%d", aux->dado);
        printf("\n");

        aux= aux->ante;
    }

    printf("\n%d", aux->dado);
    printf("\n");

}