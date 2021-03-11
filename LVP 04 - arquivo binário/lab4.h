#ifndef lab4_h
#define lab4_h

#include "definicoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Abre o arquivo cujo nome eh recebido por parametro ("arquivo") para leitura.
 * Retorna um ponteiro para o arquivo aberto.
 */
FILE *abre_arquivo(const char *arquivo);

/*
 * Fecha o arquivo recebido por parametro.
 * Retorna 0 caso consiga fechar o arquivo, qualquer outro valor caso contrario.
 */
int fecha_arquivo(FILE *arq);

/*
 * Le os times que estao dentro do "arquivo" e retorna um vetor contendo os times com seus jogadores.
 * Retorna dentro de "numero_de_times" a quantidade de times existentes dentro do arquivo lido.
 */
times_t *le_times(const char *arquivo, unsigned int *numero_de_times);

/* 
 * Encontra o jogador com a maior relacao entre cartao vermelho e numero de jogos (proporcao entre cartoes vermelhos e numero de jogos).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador com essa maior relacao deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_cartao_vermelho_e_jogos(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time);

/* 
 * Encontra o jogador artilheiro, aquele que fez mais gols. 
 * O ponteiro "times" contem o vetor com todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador artilheiro deve ser retornado dentro do ponteiro "jogador" e o time do artilheiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_artilheiro(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time);

/* 
 * Encontra o jogador mais eficiente, aquele que fez mais gols em menos jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador mais eficiente deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_eficiente(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time);

/* 
 * Encontra o time que possui mais titulos, sendo uma proporcao entre o numero de titulos (soma de todos os titulos) e o ano de fundacao (considere apenas o ano).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.  
 * O time com mais titulos deve ser retornado dentro do ponteiro "time".
 */
void encontra_time_com_mais_titulos(times_t *times, unsigned int num_times, times_t **time);

/* 
 * Encontra o goleiro que defendeu mais penaltis em funcao do numero de jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O goleiro que defendeu mais times deve ser retornado dentro do ponteiro "jogador" e o time desse goleiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_goleiro_que_defendeu_mais_penaltis(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time);

/*
 * Encontra o jogador mais agressio, considerando peso 5 para cartao vermelho, 1 para amarelo e 0.2 para faltas cometidas.
 * O ponteiro "times" contem o vetor contendo todos os timese a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador mais agressivo deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_agressivo(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time);

#endif
	 	  	 	      	   	  		 	      	   	 	
