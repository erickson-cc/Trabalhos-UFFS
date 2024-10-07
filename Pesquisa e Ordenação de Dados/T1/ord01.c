/*
 *
 *		Trabalho T1
 *	Pesquisa e Ordenação de Dados
 *	Erickson G. Müller
 *	Mat: 20230001178
 *	01 - Implemente uma ordenação ineficiente a sua escolha:
 *	Ordenação: Selection Sort
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

				/* 
	---Lista--- 
.Estrutura dos nodes da lista
..Sentinela da lista
...Append_to_List
				*/
				//Declaração Lista
struct tlist{
	int valor;
	struct tlist* next;
};
typedef struct tlist nodelist;


struct listSent{
	nodelist *head, *tail;
};
typedef struct listSent list;

				//Operações Lista
void createList(list *sent){
	sent->head = NULL;
	sent->tail = NULL;
}
void appendtoList(list *sent, int i){
	nodelist *aux;
	aux = (nodelist *)malloc(sizeof(nodelist));
	aux->valor = i;
	aux->next = NULL;

	if(sent->head==NULL){
		sent->head = aux;
		sent->tail = aux;
	}
	else{
		sent->tail->next = aux;
		sent->tail = aux;
	}
}
void printList(list *sent){
	nodelist *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		printf(" %d ", aux->valor);
	}
}
///////////////////////////////////


				/*
	---Fila--- 
.Estrutura dos nodes da fila
..Sentinela da fila
...Enqueue (direto da lista)
....Dequeue
				*/
				// Declaração Fila
struct tqueue{
	int valor; 
	struct tqueue *next;
};
typedef struct tqueue nodefila;

struct queueSent{
	nodefila *head, *tail;
};
typedef struct queueSent fila;
				//Operações Fila
///////////////////////////////////

				//Operações Vetor
void generateVector(int randomMin, int randomMax, int *vector, int vectorLen){
	int randomNumber;
	int i;
	for(i=0;i<vectorLen;i++){
		randomNumber = randomMin+rand() % (randomMax-randomMin+1);
		vector[i] = randomNumber;
	}
}
void vectorizeList(list *sent, nodelist *listVector){
	listVector[0].valor = sent->head->valor;
	nodelist *aux;
	int i=0;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		listVector[i].valor = aux->valor;
		listVector[i].next = aux->next;
		i++;
	}
}
void printVector(int *vector, int vectorLen){
	int i;
	for(i=0;i<vectorLen;i++){
		printf(" %d ", vector[i]);
	}
}

///////////////////////////////////
					/*
	--Selection Sort--
				 */
void selectionSort(nodelist *listVector){
	int i;
	nodelist menor;
	for(i=0;i<sizeof(listVector)/sizeof(listVector[0]);i++){
		menor.valor = listVector[i].valor;
		menor.next = listVector[i].next;
	}
}	

int main(){
	int vectorLen;
	vectorLen = 20;
	int vector[vectorLen];
	nodelist listVector[vectorLen];
	
	generateVector(-100, 100, vector, vectorLen);
//	printf("\nVetor Inicial:\n");
//	printVector(vector, vectorLen);

	list sent;	
	createList(&sent);
	int i;
	for(i=0;i<vectorLen;i++){
		// o loop está fora da função pois appendtoList não é uma função de transformar vetor em lista
		appendtoList(&sent,vector[i]);
	}
	printf("\nLista encadeada não ordenada:\n");
	printList(&sent);
	
	printf("\n Lista encadeada ordenada:\n");
	printList(&sent);
	vectorizeList(&sent, listVector);
	selectionSort(listVector);
	return 0;
}
