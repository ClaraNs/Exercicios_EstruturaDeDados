/*Programa: Cadastro e avaliação de notas
Autora: Ana Clara N. dos Santos
Concluido em: /01/2021
Descricao: O programa cadastra 5 alunos em uma lista duplamente encadeada e retorna o nome dos aprovados
*/

#include<stdio.h>
#include"lista_alunos.h"
	
int main (){
    int i;
    Lista *li;

    li=criaLista();

    for (i=0; i<5; i++){

        preencheDado(li);
    }

    imprimeLista(li);

    imprimeAprovados(li);

    liberaLista(li);

    return 0;
}
