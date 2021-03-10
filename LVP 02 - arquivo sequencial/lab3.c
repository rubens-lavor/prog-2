#include "lab3.h"


FILE *abre_arquivo(const char *arquivo){
	if(arquivo == NULL){
		return NULL;
	}
	
	FILE* pont = fopen(arquivo,"r");
	
	if(pont == NULL){
		return NULL;
	}
	return pont;
}

int fecha_arquivo(FILE *arq){
    if(arq==NULL){
    return 1;
    }
    
	return fclose(arq);
	
}


double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
	
	if(qtd_numeros==NULL||arquivo==NULL){
		return NULL;
	}
	
	FILE *ptr;
	
	ptr = abre_arquivo(arquivo);
	
	if(ptr == NULL) return NULL;
	
	double *armazena, aux;

	
	*qtd_numeros = 0;
	
	if(fscanf(ptr, "%lf", &aux)==EOF){	 	  	 	      	   	  		 	      	   	 	
	    fclose(ptr);
	    return NULL;
	}
	
	rewind(ptr);
	
	fscanf(ptr, "%lf", &aux);
	
	
	
	while(!feof(ptr)){
		*qtd_numeros += 1;
		fscanf(ptr, "%lf", &aux);
		
	}
	
	armazena = (double*) malloc(sizeof(double)**qtd_numeros);
	
	if(armazena == NULL) return NULL;
	
	rewind(ptr);
	
	for(int i =0; i<*qtd_numeros; i++){
		fscanf(ptr, "%lf", &aux);
		armazena[i] = aux;
	}
	
	return armazena;


}

double maior(double* valores, unsigned int qtd_numeros){
	
	double maior;
	int i;
	
	if(valores == NULL){	 	  	 	      	   	  		 	      	   	 	
	 	return HUGE_VAL;
	}
	
	maior = valores[0];
	
	for(i = 1; i<qtd_numeros; i++){
		if(maior < valores[i]){
			maior = valores[i];
	
		}
	}
	
	return maior;
	
}

double menor(double* valores, unsigned int qtd_numeros){
	
	double menor;
	int i;
	
	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	menor = valores[0];
	
	for(i = 1; i<qtd_numeros; i++){
		if(menor > valores[i]){
			menor = valores[i];
	
		}
	}
	
	return menor;

}	 	  	 	      	   	  		 	      	   	 	

double media(double* valores, unsigned int qtd_numeros){
	
	double soma = 0.0, media = 0.0, div = 0.0;
	int i;
	
	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	for(i = 0; i<qtd_numeros ; i++){
		soma = soma + valores[i];
		div = div + 1.0;
	}
	
	media = soma / div;
	
	return media;

}

double desvio(double* valores, unsigned int qtd_numeros){

	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	double desvio, med, modulo, soma = 0.0, aux_div;
	int i;
	
	med = media(valores, qtd_numeros);
	
	for(i = 0; i<qtd_numeros ; i++){
	
		modulo = valores[i] - med;
		
		if(modulo < 0){	 	  	 	      	   	  		 	      	   	 	
			modulo = modulo * -1;
		}
		modulo = pow(modulo,2);
		soma = modulo + soma;
	}
	
	aux_div = soma / (qtd_numeros-1);
	
	desvio = sqrt(aux_div);
	
	return desvio;
	
}

double mediana(double* valores, unsigned int qtd_numeros){
	
	
	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	double valor[qtd_numeros], aux, med;
	int i, j, posicao;
	
	for(i=0; i<qtd_numeros ; i++){
		valor[i] = valores[i];
	}
	
	
	
	for(i=0; i<qtd_numeros ; i++){
		for(j=1+i; j<qtd_numeros ; j++){
			if(valor[i] > valor[j]){
				aux = valor[i];
				valor[i] = valor[j];
				valor[j] = aux;
			
			}	 	  	 	      	   	  		 	      	   	 	
			
		}
	}
	
	
	
	if(qtd_numeros % 2 != 0){
		med = valor[qtd_numeros/2];
		
	}else if(qtd_numeros % 2 == 0){
		posicao = qtd_numeros / 2;
		med = (valor[posicao] + valor[posicao - 1]) / 2.0;
		
	}
	
	
	return med;
	

}

double amplitude(double* valores, unsigned int qtd_numeros){

	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	double mai, men, amplitude;
	
	mai = maior(valores, qtd_numeros);
	men = menor(valores, qtd_numeros);
	
	amplitude = mai - men;
	
	return amplitude;
	
}	 	  	 	      	   	  		 	      	   	 	

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
	
	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	if(posicao > qtd_numeros-1){
	    return HUGE_VAL;
	}
	
	if(posicao < 0){
	    return HUGE_VAL;
	}
	
	
	/*if(posicao > qtd_numeros-1){
		return NULL;
	}
	*/
	
	
	double valor;
	
	valor = valores[posicao];
	
	return valor;
}

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
	
	if(valores == NULL){
	 	return HUGE_VAL;
	}
	
	if(qtd_repeticao == NULL){	 	  	 	      	   	  		 	      	   	 	
	 	return HUGE_VAL;
	}
	
	int i, j, cont = 1, repetido[qtd_numeros], posicao;

	for(i=0; i<qtd_numeros; i++){
		for(j=0; j<qtd_numeros; j++){
			if(j != i){
				if(valores[i] == valores[j]){
					cont++;
				}
				
			}
		}
		repetido[i] = cont;
		cont = 1;
	}

	
	for(i=0 ; i<qtd_numeros ; i++){
		if(repetido[0] < repetido[i]){
			repetido[0] = repetido[i];
			posicao = i;
		}
	}

	*qtd_repeticao = repetido[posicao];
	return valores[posicao];
}


	 	  	 	      	   	  		 	      	   	 	
