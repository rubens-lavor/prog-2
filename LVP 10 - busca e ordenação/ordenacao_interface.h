#ifndef ordenacao_interface_h
#define ordenacao_interface_h

#include "lista_interface.h"

/*
 * Implementa o algoritmo de ordenacao quicksort. Ordena o vetor de elementos em "vetor" de forma crescente. 
 * tamanho especifica o numero de elementos do vetor. tamanho_elemento especifica o tamanho de cada elemento.
 * Os argumentos inicio e fim definem a parte que esta sendo classificada (ordenada) no momeneto e inicialmente devem ser 0 e tamanho - 1.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario: deve retornar -1 se "a" menor que "b", 0 se
 * forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: vetor a ser ordenado deve existir. A funcao de comparacao deve ser valida.
 * Pos-condicoes: o vetor estara ordenado de forma crescente apos a execucao da funcao. Retorna 1 caso conseguir ordenar, 0 caso contrario.
 */
int quicksort(void *vetor, unsigned int tamanho, unsigned int tamanho_elemento, unsigned int inicio, unsigned int fim, int (*comparar)(const void *a, const void *b));

/*
 * Ordena de forma crescente a lista especificada em "l" usando o metodo de ordenacao bolha.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario que compara dois elementos armazenados na lista. 
 * Deve retornar -1 se "a" menor que "b", 0 se forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: a lista deve existir e nao deve estar vazia
 * Pos-condicoes: a lista "l" estara ordenada apos a execucao da funcao. Retorna 1 caso conseguir ordenar, 0 caso contrario
 */
int bolha_lista(lista_t *l, int (*comparar)(const void *a, const void *b));

#endif
	 	  	 	      	      		 	      		    	 	
