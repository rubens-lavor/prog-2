#include <stdio.h>
#include <stdlib.h>

#include "ordenacao_privado.h"

//coloque a implementacao de quicksort e bolha aqui

/*
 * Implementa o algoritmo de ordenacao quicksort. Ordena o vetor de elementos em "vetor" de forma crescente. 
 * tamanho especifica o numero de elementos do vetor. tamanho_elemento especifica o tamanho de cada elemento.
 * Os argumentos inicio e fim definem a parte que esta sendo classificada (ordenada) no momeneto e inicialmente devem ser 0 e tamanho - 1.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario: deve retornar -1 se "a" menor que "b", 0 se
 * forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: vetor a ser ordenado deve existir. A funcao de comparacao deve ser valida.
 * Pos-condicoes: o vetor estara ordenado de forma crescente apos a execucao da funcao. Retorna 1 caso conseguir ordenar, 0 caso contrario.
 */
int quicksort(void *vetor, unsigned int tamanho, unsigned int tamanho_elemento, unsigned int inicio, unsigned int fim, int (*comparar)(const void *a, const void *b)) {
    if (vetor == NULL || comparar == NULL) {
        return 0;
    }

    if (tamanho == 0 || tamanho_elemento == 0) {
        return 0;
    }

    inicio = 0;
    fim = tamanho - 1;
    qsort(vetor, tamanho, tamanho_elemento, comparar);
}

/*
 * Ordena de forma crescente a lista especificada em "l" usando o metodo de ordenacao bolha.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario que compara dois elementos armazenados na lista. 
 * Deve retornar -1 se "a" menor que "b", 0 se forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: a lista deve existir e nao deve estar vazia
 * Pos-condicoes: a lista "l" estara ordenada apos a execucao da funcao. Retorna 1 caso conseguir ordenar, 0 caso contrario
 */
int bolha_lista(lista_t *l, int (*comparar)(const void *a, const void *b)) {
    if (l == NULL || comparar == NULL) {
        return 0;
    }

    if (lista_tamanho(l) == 0) {
        return 0;
    }

    if (lista_tamanho(l) <= 1) {
        return 1;
    }

    int tam = lista_tamanho(l);
    celula_t *aux1;
    celula_t *aux2;

    int i, j;
    for (i = 0; i < tam - 1; i++) {
        aux1 = lista_cabeca(l);
        aux2 = lista_proximo(aux1);

        for (j = 0; j < tam - 1 - i; j++) {
            if (comparar(lista_dado(aux1), lista_dado(aux2)) == 1) {
                lista_inverte_dado(aux1, aux2);
            }
            aux2 = lista_proximo(aux2);
            aux1 = lista_proximo(aux1);
        }
    }

    return 1;
}
