#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcionario.h"

//Definição da estrutura funci
struct funci{
    
    char nome[20];
    float sal;
    float impo;
};

//Definição da estrutura elemento
struct elemento{
    Elemento *ante;
    Funci dado;
    Elemento *prox;
};

//Função que aloca uma lista dinamicamente 
Lista * criaLista (){
    Lista *li;

    li=(Lista *) malloc (sizeof(Lista));

    //verifica se a memória foi alocada
    if( li != NULL){
        *li=NULL;
    }

    return li;
}

//Função para liberar o espaço de uma lista
int liberaLista (Lista *li){

    if( *li == NULL)
        return 0;

    Elemento *aux;

    while( *li != NULL){

        aux= *li;
        *li=(*li)->prox;
        free(aux);

    }

    free(li);

    return 1;
        
}


float defineImposto (float sal){

    if( sal <= 850){
        return 0;
    }

    if( sal > 850 && sal < 1200 ){

        return ( 0.1 * sal);
    }

    if( sal >= 1200){

        return (0.2 * sal);
    }
}

int insereOrdenado (Lista *li, char n[], float sal){

    //Verifica se a lista foi alocada
    if( li == NULL){
        return 0;
    }

    Elemento *no, *ante, *atual;

    no=(Elemento*) malloc (sizeof(Elemento));

    strcpy( no->dado.nome, n);
    no->dado.impo= defineImposto(sal);
    no->dado.sal= sal - (no->dado.impo);

    //Se a lista estiver vazia é inserido como 1º elementi
    if( *li == NULL ){

        no->ante=NULL;
        *li=no;
        no->prox=NULL;
    }

    else{

        atual=*li;

        while ( atual != NULL && atual->dado.sal < sal){
            
            ante= atual;
            atual= atual->prox;

        }
        
        if( atual == *li){

            no->ante=NULL;
            (*li)->ante= no;//Encadeia o novo elemento antes do primeiro
            no->prox=*li;
            *li= no;

        }

        else{

            no->prox = ante->prox;
            no->ante = ante;
            ante->prox = no;
            
            //Verifica se o novo elemento está no meio da lisa
            if( atual != NULL ){

                atual->ante=no;
                
            }

        }
    }

    return 1;
      
}

//Função que recebe as informações do funcionário e as passa como parâmetro para função que o insere na lista
void preencheDado(Lista *li){
    int ok;
    char nome[20];
    float sal;

    printf("\nNome:");
    scanf(" %19[^\n]", nome);

    printf("\nSalário:");
    scanf(" %f", &sal);

    ok=insereOrdenado(li, nome, sal);

    if(ok==0){
      printf("\nErro.");
    }
    else{
      printf("\nFuncionário cadastrado com sucesso\n");
    }

}

//Função para imprimir na tela a lista com nome, valor do imposto e valor a receber de cada funcionário
void imprimeLista (Lista *li){

    if(li==NULL || *li==NULL){
        printf("\n\nLista Vazia ou inexistente");
    }

    Elemento *aux;

    aux=*li;

    while( aux != NULL ){

        printf("\nNome: %s", aux->dado.nome);
        printf("\nImposto: %2.f", aux->dado.impo);
        printf("\nSalário: %2.f", aux->dado.sal);
        printf("\n");

        aux=aux->prox;
    }
}

//Função responsável por identificar se a letra inserida é maiúscula ou minúscula, e gerar sua correspondente para que a busca na função posterior seja completa
void avaliaChar ( Lista *li, char x){
    char y;

    //verifica se a letra é maiúscula
    if( x > 64 && x < 91){

        //sua correspondente minúscula segundo a tabela ascii
        y = x + 32;

        buscaFunci(li, x, y);
    }

    else{

        //verifica se a letra e minúscula
        if( x > 96 && x< 123){

            //Correspondente maiúscula (ascii)
            y= x - 32;

            buscaFunci(li, x, y);
        }

        else{

            //Caso não tenha sido achado nos intervalos o char não configura uma letra, portando uma mensagem é exibida
            printf("\nCaracter inválido.");

         }

    }



}


//Função que busca o funcinário pela primeira letra de seu nome e o imprime juntamente com o salário
void buscaFunci (Lista *li, char x, char y){

    if(li == NULL  || *li== NULL){
        
        printf("\nNão é possível analisar.");
        return ;

    }

    int cnt=0;
    char z;
    Elemento *aux;

    aux=*li;

    while ( aux != NULL){

        z= aux->dado.nome[0];

        if( z == x || z == y){

            printf("\n%s \n%f\n", aux->dado.nome, aux->dado.sal);
            cnt++;
        }

        aux=aux->prox;
    }

    if(cnt==0){
        printf("\nNenhum funcionário com a inicial %c encontrado\n", x);
    }

    
}


//Imprime os dados dos funcionários 1º por ordem crescente e em seguida por ordem decrescente
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

        printf("\nNome: %s", aux->dado.nome);
        printf("\nSalário: %2.f", aux->dado.sal);
        printf("\n");

        aux= aux-> prox;
    }

    printf("\nNome: %s", aux->dado.nome);
    printf("\nSalário: %2.f", aux->dado.sal);
    printf("\n");

    printf("\nOrdem decrescente:");

    //laço é iniciado quando o auxiliar é o último elemento e termina quando chega ao começo da lista
    while ( aux->ante != NULL){

        printf("\nNome: %s", aux->dado.nome);
        printf("\nSalário: %2.f", aux->dado.sal);
        printf("\n");

        aux= aux->ante;
    }

    printf("\nNome: %s", aux->dado.nome);
    printf("\nSalário: %2.f", aux->dado.sal);
    printf("\n");



}

