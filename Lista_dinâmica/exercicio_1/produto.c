#include<stdio.h>
#include<stdlib.h>
#include"produto.h"


//// definição do struct produto
struct produto{
    int cod;
    int qnt;
    float val;
};

//// definição do struct elemento
struct elemento {
    Produto dados;
    Elemento *prox;
} ;

//Função que aloca dinamicamente uma lista na memória
Lista *criarLista (){
  Lista *li;
  
  li=(Lista *) malloc (sizeof(Lista));
  
  //Se a lista foi alocada corretamente, é inicializada com o primeiro elemento vazio 
  if(li!=NULL){
    *li=NULL;
  }

  return li;
}

//Função responsável por liberar a memória anteriormente alocada
int destruirLista (Lista *li){

  if(li==NULL)
   return 0;

  Elemento *no;

  while(*li!=NULL){
    
    
    no=*li;
    *li=(*li)->prox;

    free(no);
  }

  free(li);

  return 1;
} 


//Função que aloca dinamicamente um elemento na memória
Elemento* criaEle (){
    Elemento *no;
    no = (Elemento *) malloc (sizeof(Elemento));

    return no;
}

//Função responsável por ler as informações de cada produto e chamar a função que de fato irá  inseri-lô na lista
void criaProd (Lista *li){
  int cod, qtd, ok;
  float val;

  printf("\nInsira seu código:");
  scanf(" %d", &cod);

  printf("\nA quantidade no estoque:");
  scanf(" %d", &qtd);

  printf("\nValor unitário:");
  scanf(" %f", &val);

  ok = inserirListaFinal(li, cod, qtd, val);

  if( ok != 1)
  printf("\nErro ao inserir novo produto na lista.");

  else
    printf("\nInserção feita com sucesso");
        
}

//Função que acrescenta um elemento ao fim da lista
int inserirListaFinal (Lista *li, int cod, int qnt, float val){

    if(li==NULL)
     return 0;

    Elemento *no;

    no=criaEle();
    
    if(no==NULL)
     return 0;

    no->dados.cod=cod;
    no->dados.qnt=qnt;
    no->dados.val=val;
    no->prox=NULL;
    
    //se a lista estiver vazia, insere no início
    if(*li==NULL){

        *li=no;
        
    }
    else {

        Elemento *aux;
        
        aux = *li;

        //Percorre a lista até seu último elemento
        while(aux->prox != NULL){

            aux = aux->prox;
        }

        aux->prox= no;
    }

    return 1;
     

}


//Função que imprime na tela todas os elementos da lista, com suas informações
void imprimeLista (Lista *li){
  
  if(li == NULL || (*li) == NULL){
    
    printf("\nLista vazia ou não alocada.\n");
    return;
  }
    
  Elemento *aux;
  int cnt=0;

  aux=*li;

  while(aux != NULL){
    
    printf("\n");
    printf("\nCódigo: %d", aux->dados.cod);
    printf("\nQuantidade: %d", aux->dados.qnt);
    printf("\nValor: %f", aux->dados.val);
    printf("\n");

    if( aux->dados.qnt > 500)
    {
      cnt++;
    }

    aux = aux->prox;
  }

  printf("\n%d produtos têm mais de 500 unidades estocadas!", cnt);
  
}

//Função responsável por aplicar o desconto aos produtos 
int aplicaDesconto (Lista *li, float x){
  float des;

  //Verifica se a lista foi alocada e se está vazia 
  if(li == NULL || (*li) == NULL)
    return 0;
  

  Elemento *aux;

  aux=*li;

  //Determina a porcentagem do preço a ser mantida após o desconto
  des= 1 - (x/100);

  //Percorre a lista aplicando o desconto
  while( aux != NULL){

    aux->dados.val= ((aux->dados.val)* des);

    aux= aux->prox;

  }

  return 1;
}