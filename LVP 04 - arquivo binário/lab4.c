#include "lab4.h"




FILE *abre_arquivo(const char *arquivo){
	if(arquivo == NULL){
		return NULL;
	}
	
	FILE *pont;
	
	pont = fopen(arquivo, "r");
	
	if(pont == NULL){
		return NULL;
	}
	
	return pont;
}


int fecha_arquivo(FILE *arq){
	
	if(arq == NULL){
		return 4;
	}
	
	int pont = fclose(arq);
	
	return pont;
	
}

/*
 * Le os times que estao dentro do "arquivo" e retorna um vetor contendo os times com seus jogadores.
 * Retorna dentro de "numero_de_times" a quantidade de times existentes dentro do arquivo lido.
 */
times_t *le_times(const char *arquivo, unsigned int *numero_de_times){	 	  	 	      	   	  		 	      	   	 	

	if(arquivo == NULL){
		return NULL;
	}
	
	if(numero_de_times == NULL){
		return NULL;
	}
	
	*numero_de_times = 0;
	
	FILE *pont = abre_arquivo(arquivo);
	
	if(pont == NULL){
		return NULL;
	}
	
	times_t *times;
	
	if(fscanf(pont, "%i", &times)==EOF){
	    fclose(pont);
	    return NULL;
	}
	
	rewind(pont);
	
	times = (times_t*) malloc(sizeof(times_t));
	
	if(times == NULL){
		return NULL;
	}
	
	int tam, cont = 1;
	
	tam = fread(&times[0], sizeof(times_t), 1, pont);
	
	while(tam != 0){	 	  	 	      	   	  		 	      	   	 	
	
		cont = cont + 1;
		times = (times_t*) realloc(times, sizeof(times_t) * cont);
		
		tam = fread(&times[cont -1], sizeof(times_t), 1, pont);
		
		if(times == NULL){
			return NULL;
		}	
	
	}
	
	*numero_de_times = cont-1;
	
	return times;


}

/* 
 * Encontra o jogador com a maior relacao entre cartao vermelho e numero de jogos (proporcao entre cartoes vermelhos e numero de jogos).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador com essa maior relacao deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_cartao_vermelho_e_jogos(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	
	if(times == NULL){
		return;
	}
	
	if(jogador == NULL){
		return;
	}
	
	if(time == NULL){
		return;
	}	 	  	 	      	   	  		 	      	   	 	
	
	
	int i, j, k = 0, posicao, pos_time, pos_jogador;
	double cartao[num_times * NUM_JOGADORES], qtd_jogos, qtd_cartao;
	
	for(i=0; i<num_times; i++){
		for(j=0; j<21 ; j++){
			qtd_jogos = times[i].jogadores[j].numero_jogos;
			qtd_cartao = times[i].jogadores[j].cartoes_vermelhos;
			cartao[k+j] = qtd_cartao / qtd_jogos;
			//printf("%lf ", cartao[k+j]);	
	
		}
		k = j + k;
	}
	
	for(i=1; i<k ; i++){
		if(cartao[0] < cartao[i]){
			cartao[0] = cartao[i];
			posicao = i;
			
		}
	}

	pos_time = posicao / NUM_JOGADORES;
	
	pos_jogador = posicao - (pos_time*NUM_JOGADORES);
	*jogador = &times[pos_time].jogadores[pos_jogador];
	*time = &times[pos_time];
	
	
}	 	  	 	      	   	  		 	      	   	 	

/* 
 * Encontra o jogador artilheiro, aquele que fez mais gols. 
 * O ponteiro "times" contem o vetor com todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador artilheiro deve ser retornado dentro do ponteiro "jogador" e o time do artilheiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_artilheiro(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	
	if(times == NULL){
		return;
	}
	
	if(jogador == NULL){
		return;
	}
	
	if(time == NULL){
		return;
	}
	
	int i, j, k=0, posicao, pos_time, pos_jogador;
	double gols[num_times*NUM_JOGADORES];
	
	for(i=0; i<num_times; i++){
		for(j=0; j<21 ; j++){
			gols[k+j] = times[i].jogadores[j].gols_marcados;	
	
		}
		k = j + k;
	}
	
	for(i=1; i<num_times*NUM_JOGADORES; i++){
		if(gols[0] < gols[i]){
			gols[0] = gols[i];
			posicao = i;
		}	 	  	 	      	   	  		 	      	   	 	
	}
	
	pos_time = posicao / NUM_JOGADORES;
	pos_jogador = posicao - (pos_time*NUM_JOGADORES);
	
	*jogador = &times[pos_time].jogadores[pos_jogador];
	*time = &times[pos_time];	

}

/* 
 * Encontra o jogador mais eficiente, aquele que fez mais gols em menos jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador mais eficiente deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_eficiente(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	
	if(times == NULL){
		return;
	}
	
	if(jogador == NULL){
		return;
	}
	
	if(time == NULL){
		return;
	}
	
	int i, j, k = 0, posicao, pos_time, pos_jogador;
	double eficiencia[num_times*NUM_JOGADORES], qtd_gols, qtd_jogos;
	
	for(i=0; i<num_times; i++){
		for(j=0; j<21 ; j++){
			
			qtd_jogos = times[i].jogadores[j].numero_jogos;
			qtd_gols = times[i].jogadores[j].gols_marcados;
			eficiencia[k+j] = qtd_gols / qtd_jogos;
	
		}	 	  	 	      	   	  		 	      	   	 	
		k = j + k;
	}
	
	for(i=1; i<num_times*NUM_JOGADORES; i++){
		if(eficiencia[0] < eficiencia[i]){
			eficiencia[0] = eficiencia[i];
			posicao = i;
		}
	}
	
	pos_time = posicao / NUM_JOGADORES;
	pos_jogador = posicao - (pos_time*NUM_JOGADORES);
	
	*jogador = &times[pos_time].jogadores[pos_jogador];
	*time = &times[pos_time];
	
	
}

/* 
 * Encontra o time que possui mais titulos, sendo uma proporcao entre o numero de titulos (soma de todos os titulos) e o ano de fundacao (considere apenas o ano).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.  
 * O time com mais titulos deve ser retornado dentro do ponteiro "time".
 */
void encontra_time_com_mais_titulos(times_t *times, unsigned int num_times, times_t **time){
	if(times == NULL){
		return;
	}
	
	
	if(time == NULL){
		return;
	}
	
	int  i, j, posicao;
	double titulos[num_times], tit;
	
	for(i=0; i<num_times; i++){	 	  	 	      	   	  		 	      	   	 	
	   	tit = times[i].numero_tit_brasileiros + times[i].numero_copas_brasil + times[i].numero_tit_libertadores + times[i].numero_tit_estadual;
		titulos[i] = tit / (2017 - times[i].ano_fundacao);
		//printf("%s\n", times[i].nome);
		//printf("%lf\n", titulos[i]);
	}
	
	for(i=1; i<num_times; i++){
		if(titulos[0] < titulos[i]){
			titulos[0] = titulos[i];
			posicao = i;
		}
	}
	
	*time = &times[posicao];
	

}

/* 
 * Encontra o goleiro que defendeu mais penaltis em funcao do numero de jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O goleiro que defendeu mais times deve ser retornado dentro do ponteiro "jogador" e o time desse goleiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_goleiro_que_defendeu_mais_penaltis(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	
	if(times == NULL){
		return;
	}
	
	if(jogador == NULL){
		return;
	}
	
	if(time == NULL){
		return;
	}	 	  	 	      	   	  		 	      	   	 	
	
	double penaltis[num_times*NUM_JOGADORES], qtd_penaltis, qtd_jogos;
	int i, j, k=0, posicao, pos_time, pos_jogador;
	
	for(i=0; i<num_times; i++){
		for(j=0; j<21 ; j++){
			
			qtd_jogos = times[i].jogadores[j].numero_jogos;
			qtd_penaltis = times[i].jogadores[j].penalti_defendidos;
			penaltis[k+j] = qtd_penaltis / qtd_jogos;
			//printf("%lf ", cartao[k+j]);	
	
		}
		k = j + k;
	}
	
	for(i=1; i<num_times*NUM_JOGADORES; i++){
		if(penaltis[0] < penaltis[i]){
			penaltis[0] = penaltis[i];
			posicao = i;
		}
	}
	
	pos_time = posicao / NUM_JOGADORES;
	pos_jogador = posicao - (pos_time*NUM_JOGADORES);
	
	*jogador = &times[pos_time].jogadores[pos_jogador];
	*time = &times[pos_time];
	

}

/*
 * Encontra o jogador mais agressio, considerando peso 5 para cartao vermelho, 1 para amarelo e 0.2 para faltas cometidas.
 * O ponteiro "times" contem o vetor contendo todos os timese a variavel inteira "num_times" contem o numero total de times do vetor. 
 * O jogador mais agressivo deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_agressivo(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){	 	  	 	      	   	  		 	      	   	 	
	
	if(times == NULL){
		return;
	}
	
	if(jogador == NULL){
		return;
	}
	
	if(time == NULL){
		return;
	}
	
	double agressivo[num_times*NUM_JOGADORES], falt = 0.2, cAma = 1.0, cVer = 5.0;
	int i, j, k=0, posicao, pos_time, pos_jogador;
	
	for(i=0; i<num_times; i++){
		for(j=0; j<21 ; j++){
			agressivo[k+j] = (times[i].jogadores[j].faltas_cometidas * falt) + (times[i].jogadores[j].cartoes_vermelhos * cVer) + (times[i].jogadores[j].cartoes_amarelos * cAma);
			//printf("%lf ", cartao[k+j]);	
	
		}
		k = j + k;
	}
	
	for(i=1; i<num_times*NUM_JOGADORES; i++){
		if(agressivo[0] < agressivo[i]){
			agressivo[0] = agressivo[i];
			posicao = i;
		}
	}
	
	pos_time = posicao / NUM_JOGADORES;
	pos_jogador = posicao - (pos_time*NUM_JOGADORES);
	
	*jogador = &times[pos_time].jogadores[pos_jogador];
	*time = &times[pos_time];
}	 	  	 	      	   	  		 	      	   	 	
