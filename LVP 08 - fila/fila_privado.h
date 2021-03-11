#ifndef fila_privado_h
#define fila_privado_h

#include "fila_interface.h"

typedef struct celula {
	void *dado; //dado armazenado na celula. A alocacao de memoria eh responsabilidade do usuario
	struct celula *prox; //proxima celula na fila encadeada
} celula_t;

struct fila {
	celula_t *cabeca; //ponteiro para a celula cabeca da fila
	celula_t *cauda;  //ponteiro para a celula cauda da fila
	int tamanho;
	void (*destruir)(void *); //ponteiro de funcao usado na funcao de destruir a fila, caso seja valida
	void (*imprime)(const void *); //ponteiro de funcao para imprimir os dados armazenados na fila. Implementacao eh responsabilidade do usuario do TDA
	int (*compara)(const void *, const void *); //ponteiro de funcao para comparar dois dados armazenados na fila. Retorna -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo   
};

#endif