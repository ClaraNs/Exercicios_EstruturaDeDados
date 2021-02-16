#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cadastro.h"


//Definição da struct funci
struct funci{
    char nome[20];
    float sal;
};

//Definição da struct elemento
struct elemento{
    Funci dado;
    Elemento *prox;
};

//Função para alocar dinamicamente uma lista na memória
Lista * criaLista (){
    Lista *li;

    li=(Lista *) malloc (sizeof(Lista));

    return li;
}

//Função responsável por alocar dinamicamente um elemento
Elemento * criaElemento (){
    Elemento *no;

    no=(Elemento*) malloc (sizeof(Elemento));

    return no;
}

//Função para liberar memória alocada
int liberaLista (Lista *li){

    if(li==NULL || (*li)==NULL )
        return 0;

    Elemento *aux;

    while( *li != NULL){
        
        aux=(*li);
       *li= (*li)->prox;

        free(aux);
    }

    free(li);

    return 1;
}

//Função responsável por ler o nome e o valor do salário e passá-los como paramêtro para função que insere um novo funcionário
void coletaDados (Lista *li){
    int ok;
    char n[20];
    float sal;

    printf("\nInsira o nome do funcionário:");
    scanf(" %19[^\n]", n);

    printf("\nInforme o salário:");
    scanf(" %f", &sal);

    //Chama a função responsável por inserir os funcionários
    ok=insereListaOrdenado(li, n, sal);

    //Verifica se houve falha ao inserir
    if(ok !=1 ){

    printf("\nErro ao iserir funcionário");
    }

    else{
    printf("\nFuncionário acrescentado.\n");
    }
        

}

int insereListaOrdenado (Lista *li, char n[], float sal){

    //verifica se a lista foi alocada
    if(li==NULL){
        printf("\nMemória não alocada");
        return 0;
    }

    Elemento *no;

    //Aloca dinamicamente o elemento
    no=(Elemento *) malloc (sizeof(Elemento));

    //Preenche o conteúdo do novo elemento
    strcpy(no->dado.nome, n);
    no->dado.sal= sal;

    //verifica se a lista está vazia
    if(*li==NULL){
        *li=no;
        no->prox=NULL;
    }

    //Se a lista não estiver vazia
    else{
    
    //Utiliza-se dois ponteiros de elemento para percorrer a lista
    Elemento *aux, *ant;

    //a variável aux é iniciada
    aux=*li;

    //Se o funcionário inserido for o de maior salário, ocupa o 1º lugar
    if( aux->dado.sal < sal){
      no->prox = aux;
      *li=no;
    }
    
    else {
    
    //o laço continua enquanto o próximo elemento for diferente de NULL e enquanto o próximo funcionário apresentar um salário maior que o que será inserido 
    while( aux->prox != NULL && (aux->prox)->dado.sal > sal){

        ant=aux;
        aux=aux->prox;

    }

    //verifica se o salário do novo elemento é maior que o aux atual
    if( aux->dado.sal < sal){

        // o novo elemento é inserido entre o anterior e o auxiliar
        no->prox= ant->prox;
        ant->prox= no;

    }

    else{
        
        //Caso o novo elemento tenha salário menor ou igual ao aux, é adicionado após ele
        no->prox = aux->prox;
        aux->prox=no;
        }
     }

    }

    return 1;
}

//Função que escreve na tela a lista
void imprimeLista (Lista *li){

    if( li==NULL || *li==NULL)
     printf("\nLista não alocada ou vazia");
    
    Elemento *aux;

    aux=(*li);

    //laço para percorrer a lista
    while ( aux->prox != NULL ){

        printf("\nNome: %s", aux->dado.nome);
        printf("\nSalário: %2.f", aux->dado.sal);
        printf("\n");

        aux=aux->prox;

    }

    printf("\nNome: %s", aux->dado.nome);
    printf("\nSalário: %f", aux->dado.sal);
    printf("\n");

    
}

//Imprime o nome do(s) funcionário(s) com maior salário
void maiorSal (Lista *li){
    float masal;

    if(*li==NULL || li==NULL)
     printf("\nLista vazia, impossível verifficar"); 
    
    Elemento *aux;

    aux=*li;

    //O primeiro da lista representa o maior salário
    masal=aux->dado.sal;

    printf("\nFuncionário(s) com maior salário:\n");

    //laço para percorrer a lista enquanto o elemento aux não for nulo e o salário for igual ao maior
    while( aux != NULL && aux->dado.sal == masal){

        printf("\n%s", aux->dado.nome);

        aux=aux->prox;
    }

}

//Retorna a média salarial
float mediaSAl (Lista *li){
    int cnt=0;
    float soma=0;

    if( li== NULL || *li==NULL)
     return 0;
    
    Elemento *aux;

    aux=*li;

    //laço que percorre a lista somando os salários de cada funcionária e adicionando um ao contador
    while ( aux != NULL ){

        soma = soma + aux->dado.sal;

        cnt++;

        aux= aux->prox;
    }

    return (soma / cnt );


}

//Retorna a quantidade de salários acima do valor fornecido pelo usuário
int buscaSal (Lista *li, float x){
    int cnt=0;

    if( li== NULL || *li==NULL){

        printf("\nLista vazia.");
        return 0;
    }

    Elemento *aux;

    aux=*li;

    while( aux != NULL ){

        //Se o salário for maior que o fornecido, é adicionado um ao contador
        if( aux->dado.sal > x){
            cnt++;
        }

        aux=aux->prox;

    }

    return cnt;
}