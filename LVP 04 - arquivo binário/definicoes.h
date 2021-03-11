#ifndef definicoes_h
#define definicoes_h

#define TAM_NOME 50
#define NUM_JOGADORES 21

typedef struct {
	char nome[TAM_NOME];
	//0 goleiro, 1 zagueiro, 2 lateral, 3 volante, 4 meio, 5 atacante
	unsigned int posicao; 
	unsigned int gols_marcados;
	unsigned int bolas_roubadas;
	unsigned int numero_jogos;
	unsigned int finalizoes_certas;
	unsigned int finalizoes_erradas;
	unsigned int faltas_recebidas;
	unsigned int faltas_cometidas;
	unsigned int cartoes_vermelhos;
	unsigned int cartoes_amarelos;
	unsigned int penalti_defendidos;
	unsigned int defesas;
} jogador_t;

typedef struct {
	char nome[TAM_NOME];
	char estado[3];
	unsigned int dia_fundacao;
	unsigned int mes_fundacao;
	unsigned int ano_fundacao;
	unsigned int numero_tit_brasileiros;
	unsigned int numero_copas_brasil;
	unsigned int numero_tit_libertadores;
	unsigned int numero_tit_estadual;
	jogador_t jogadores[NUM_JOGADORES];
} times_t;

#endif
	 	  	 	      	   	  		 	      	   	 	
