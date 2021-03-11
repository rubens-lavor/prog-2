#ifndef _ABB_H
#define _ABB_H

#include <stdbool.h>
#include "comum.h"


typedef struct nodearv  node_t;
typedef struct arvorebb abb_t;

/**
 * Criar árvore binária de busca e a inicializa como arvore vazia.
 *
 * Pre: nenhuma
 * Pos: Retorna um ponteiro para uma arvore vazia se houver memoria disponivel
 *
 * @param imprimir um ponteiro para uma funcao de impressao dos dados armazenados dentro da arvore.
 * @param destruir fornece uma maneira de liberar dinamicamente os dados dentro da celula quando "abb_destroi" eh chamada.
 * Para uma arvore onde os dados nao devem ser liberados, esse ponteiro deve ser NULL.
 * @param compara  um ponteiro para funcao de comparacao entre dois dados armazenados na lista.
 * Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo
 *
 * @return um ponteiro para uma arvore nova
 */
abb_t*      abb_criar       (void (*imprimir)(const void *data),
                             void (*destruir)(void **data),
                             int (*compara)(const void *key1, const void* key2));

/**
 * Criar árvore binária de busca e a inicializa com os valores do vetor.
 *
 * Pre: nenhuma
 * Pos: Retorna um ponteiro para uma arvore com os valores se houver memoria disponivel
 *
 * @param imprimir um ponteiro para uma funcao de impressao dos dados armazenados dentro da arvore.
 * @param destruir fornece uma maneira de liberar dinamicamente os dados dentro da celula quando "abb_destroi" eh chamada.
 * Para uma arvore onde os dados nao devem ser liberados, esse ponteiro deve ser NULL.
 * @param compara  um ponteiro para funcao de comparacao entre dois dados armazenados na lista.
 * Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo
 *
 * @return um ponteiro para uma arvore nova
 */
abb_t*      abb_criar_de_vetor (void* vetor, int tamanho_vetor, int tamanho_elemento,
                             void (*imprimir)(const void *data),
                             void (*destruir)(void **data),
                             int (*compara)(const void *key1, const void* key2));

/**
 * Destrói a árvore binária de busca.
 * Nenhuma operação é permitida após a função, a nao ser que a árvore seja criada novamente.
 * Destrói todos os elementos armazenados na árvore se o ponteiro "destruir" for válido.
 *
 * Pre: "arv" deve ser uma árvore válida criada previamente atraves da função de criação
 * Pos: os recursos da árvore foram liberados com sucesso e a ela tornou-se nula.
 *
 * @param arv ponteiro de ponterio para uma arvore válida a ser destruída.
 * @return SUCESSO se conseguiu destruir toda a árvore.
 *         INVALIDO se a árvore não for válida.
 */
codigo_erro abb_destroi    (abb_t** arv);

/**
 * Verifica se a árvore está vazia.
 *
 * @param arv arvore para avaliação
 * @return  verdadeiro para árvore vazia
 *          falso caso contrario
 */
bool        abb_vazia       (const abb_t* arv);

/**
 * Consulta o tamnho da árvore, em quantidades de itens inseridos e não repetidos.
 *
 * @param arv arvore para consulta.
 * @return número de itens e não repetidos na árvore, caso árvore for invalida retorna o valor -1.
 *
 */
long        abb_tamanho     (const abb_t* arv);

/**
 * Insere um item na árvore.
 *
 * @param arv arvore para a operacao
 * @param data dado compativel com a arvore para ser inserido
 * @return SUCESSO se conseguiu inserir na árvore.
 *         INVALIDO se a árvore não for válida.
 *         ESTADO_INVALIDO se a arvore nao possuir uma funcao de comparacao
 *         DUPLICADO se o dado a ser inserido já está presenta na árvore
 *
 */
codigo_erro abb_insere      (abb_t* arv, void* data);

/**
 * Remove um item da árvore (se ele existir).
 *
 * @param arv arvore para a operacao
 * @param data informacao para remover
 * @return SUCESSO se existir o valor e remover ele
 * 		   UNDER_FLOW se arvore invalida ou vazia
 * 		   VALOR_INVALIDO se data nao existir
 * 		   INVALIDO para outra condicao encontrada
 */
codigo_erro abb_remove      (abb_t* arv, const void* data);

/**
 * Consulta se um determinado valor pertence a arvore.
 *
 * @param arv arvore para a operacao
 * @param info valor a buscar
 *
 * @return verdadeiro para valor na arvore e falso caso contrario.
 */
bool        abb_busca_bin   (const abb_t* arv, void* info);

/**
 * Consulta o no raiz da arvore.
 *
 * @param arv arvore para a operacao
 *
 * @return no raiz da arvore ou NULL caso arvore invalida ou vazia
 */
const node_t*     abb_raiz(const abb_t* arv);

/**
 * Consulta a subarvore esquerda da arvore.
 *
 * @param raiz raiz da arvore para a operacao
 *
 * @return no raiz da subarvore esquerda do no raiz ou NULL caso a subarvore nao exista
 */
const node_t*     abb_esq(const node_t* raiz);

/**
 * Consulta a subarvore direita da arvore.
 *
 * @param raiz raiz da arvore para a operacao
 *
 * @return no raiz da subarvore direita do no raiz ou NULL caso a subarvore nao exista
 */
const node_t*     abb_dir(const node_t* raiz);

/**
 * Consulta a informacao contida no no.
 *
 * @param node no para a operacao
 *
 * @return informacao contida no no, NULL caso no seja invalido.
 */
const void* 	  abb_info(const node_t* node);

/**
 * Consulta se um determinado no e folha.
 *
 * @param node no para a operacao
 *
 * @return verdadeiro se no for folha e falso caso contrario.
 *
 */
bool        abb_node_ehfolha(const node_t* node);

/**
 * Consulta a altura da arvore
 *
 * @param arv arvore para a operacao
 * @param altura ponteiro para armazenar a altura da arvore como resultado da funcao
 *
 * @return SUCESSO se o calculo for realizado com sucesso e o valor estara armazenado no parametor altura
 * 		   INVALIDO caso a arvore seja invalida
 */
codigo_erro abb_altura(abb_t* arv, unsigned long *altura);

//extras

node_t* destroi_no(abb_t* arv,node_t* extra);

bool repetido(const abb_t* arv, node_t* no, void* info);

unsigned long int altura_arv(abb_t* arv, node_t* node);

#endif	 	  	 	      	      		 	      		    	 	
