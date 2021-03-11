#include "conjunto_privado.h"

conjunto_t *conjunto_cria(void){
	
	conjunto_t *pont;
	
	pont = (conjunto_t *) malloc(sizeof(conjunto_t));
	
	if(pont != NULL){
		pont->numero = 0;
		pont->capacidade = ELEMENTOS;
		pont->vetor = (elem_t *) malloc(ELEMENTOS * sizeof(elem_t));
		
		if(pont->vetor == NULL){
			free(pont);
			return NULL;
		}
		
		return pont;
	}else{
		return NULL;	
	}
	
}

/*
 * Destroi o conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: o conjunto passado por parametro nao eh mais valido, nao podera mais ser utilizado e devera apontar para NULL
 */
void conjunto_destroi(conjunto_t **a){

	if(!a) return;
	if(!(*a)) return;
    if((*a)->vetor!=NULL){
	    free((*a)->vetor);
    }
	free(*a);
	*a=NULL;

}


/*
 * Retorna o numero de elementos que estao no conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: 
 */
int conjunto_numero_elementos(conjunto_t *a){
	
	if(a == NULL){
		return -1;
	}
	
	return a->numero;
}

/*
 * Recebe um conjunto como parametro e o inicializa como conjunto vazio
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a ser um conjunto vazio
 */
void conjunto_inicializa_vazio(conjunto_t *a){

	if(a == NULL){
		return;
	}		
	
	a->numero = 0;
	//a->vetor = NULL;
}

/*
 * Recebe os conjuntos "a e "b" e retorna a uniao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a uniao entre os conjuntos "a" e "b"
 */
void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	
	
	if(a == NULL || b == NULL || c == NULL){
		return;
	}
	
	conjunto_inicializa_vazio(c);
	
    //c->capacidade = a->capacidade + b->capacidade;
	//c->vetor = (elem_t *) realloc(c->vetor, sizeof(elem_t)*c->capacidade);
	//c->numero = 0;
	
	

	int i, x;
	int aux = 0, cont = 0;
	
	int k=0, j;
	
	
	//conjunto_insere_elemento(elem_t x, conjunto_t *a)

    for(i=0; i<a->numero; i++){
        x = conjunto_insere_elemento(a->vetor[i], c);
    }
    
    for(i=0; i<b->numero; i++){
        x = conjunto_insere_elemento(b->vetor[i], c);
    }
	
	
}

/*
 * Recebe os conjuntos "a e "b" e retorna a interseccao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a interseccao entre os conjuntos "a" e "b"
 */
void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){

	if(a == NULL || b == NULL || c == NULL){
		return;
	}
	
	conjunto_inicializa_vazio(c);
	
	//c->capacidade = a->capacidade + b->capacidade;
	//c->vetor = (elem_t *) realloc(c->vetor, sizeof(elem_t)*c->capacidade);
	//c->numero = 0;
	
	int k = 0, x;
	
	for(int i=0; i<a->numero ; i++){
		if(conjunto_membro(a->vetor[i], b) == 1){
		    x = conjunto_insere_elemento(a->vetor[i], c);
		}
	}
	
	for(int i=0; i<b->numero ; i++){
		if(conjunto_membro(b->vetor[i], a) == 1){
		    x = conjunto_insere_elemento(b->vetor[i], c);
		}
	}
	
	
}

/*
 * Recebe os conjuntos "a" e "b" e retorna a diferenca entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos, criados pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "c" contera a diferenca entre os conjuntos "a" e "b"
 */
void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	
	if(a == NULL || b == NULL || c == NULL){
		return;
	}
	
	conjunto_inicializa_vazio(c);
	
	//c->capacidade = a->capacidade + b->capacidade;
	//c->vetor = (elem_t *) realloc(c->vetor, sizeof(elem_t)*c->capacidade);
	//c->numero = 0;
	
	
	int k = 0, aux = 0, dif, i, x;
	
	for(int i=0; i<a->numero ; i++){
		if(conjunto_membro(a->vetor[i], b) != 1){
		    x = conjunto_insere_elemento(a->vetor[i], c);
		}
	}
	

	
	


}

/*
 * Retorna 1 se o elemento "x" pertence ao conjunto "a", 0 caso contrario
 * Pre-condicao: o conjunto A deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o valor retornado sera 0 ou 1
 */
int conjunto_membro(elem_t x, conjunto_t *a){
	
	if(a==NULL){
		return 0;
	}

	if(a->numero==0){
		return 0;
	}

	for(int i=0;i<a->numero;i++){
		if(a->vetor[i]==x){
			return 1;
		}
	}

	return 0;
}

int conjunto_insere_elemento(elem_t x, conjunto_t *a){
 
	if(a==NULL){
		return 0;
	}

	if(conjunto_membro(x,a)==1){
	    return 1;
	}
	
	if(a->capacidade==a->numero){
	    a->vetor=(elem_t*) realloc(a->vetor,sizeof(elem_t)*a->capacidade*2);
	    if(a->vetor==NULL){
	        return 0;
	        
	    }	 	  	 	    	   	     	    		   	       	 	
	    a->capacidade=a->capacidade*2;
	    
	}

	a->vetor[a->numero]=x;	
	a->numero=a->numero+1;
	return 1;

}

void conjunto_remove_elemento(elem_t x, conjunto_t *a){

	if(a==NULL){
		return;
	}
	
	
	if(conjunto_membro(x,a)==0){
		return;
	}

    int i,posicao=0;
	elem_t aux[a->numero-1];
	
	for(i=0;i<a->numero;i++){
	    if(x==a->vetor[i]){
	        posicao=i;
	        i=a->numero;
	    }
	}
	
	for(i=posicao;i<(a->numero-1);i++){
	    aux[i]=a->vetor[i+1];
	}

	a->numero=a->numero-1;
	
	for(i=posicao;i<a->numero;i++){	 	  	 	    	   	     	    		   	       	 	
	    a->vetor[i]=aux[i];
	    
	}
}
/*
 * Atribui o conjunto "a" ao "b" (a = b)
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
void conjunto_atribui(conjunto_t *a, conjunto_t *b){

	if(a == NULL){
		return;
	}
	
	if(b == NULL){
		return;
	}
	
	b->capacidade = a->capacidade;
	
	b->numero = a->numero;
	
	for(int i=0; i<ELEMENTOS ; i++){
		b->vetor[i] = a->vetor[i];
	}

}

/*
 * Retorna 1 caso o conjunto "a" seja igual ao conjunto "b", 0 caso contrario
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
int conjunto_igual(conjunto_t *a, conjunto_t *b){
	
	if(a == NULL){
		return 0;
	}
	
	if(b == NULL){
		return 0;
	}
	
	if(b->capacidade != a->capacidade){
		return 0;
	}
	
	if(b->numero != a->numero){
		return 0;
	}
	
	int aux = 0;
	
	for(int i=0; i<b->numero ; i++){
		if(b->vetor[i] == a->vetor[i]){
			aux = aux + 1;
		}
	}
	
	if(b->numero == aux){
		return 1;
	}else{
		return 0;
	}

}

/*
  * Retorna o valor minimo dentro do conjunto "a", retorne ELEM_MAX caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
elem_t conjunto_minimo(conjunto_t *a){
	
    if(a == NULL){
	    return ELEM_MAX;
    }
	
	for(int i=1; i<a->numero; i++){
		if(a->vetor[0] > a->vetor[i]){
			a->vetor[0] = a->vetor[i];
		}
	}
	
	return a->vetor[0];

}

/*
 * Retorna o valor maximo dentro do conjunto "a", retorne ELEM_MIN caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
elem_t conjunto_maximo(conjunto_t *a){
	    
    if(a == NULL){
	    return ELEM_MIN;
    }
	
	for(int i=1; i<a->numero; i++){
		if(a->vetor[0] < a->vetor[i]){
			a->vetor[0] = a->vetor[i];
		}
	}
	
	return a->vetor[0];
}


/*
 * Imprime o conjunto "a", sendo os elementos separados por espaço. Se for o ultimo elemento, nao deve ser impresso o ultimo espaco. Quebra de linha no final.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
void conjunto_imprime(conjunto_t *a){
	
	if(a == NULL){
		return;
	}
	
	int cont = 0;
	
	for(int i=0; i<a->numero; i++){
		printf("%i", a->vetor[i]);
		cont = cont + 1;
		
		if(cont <= (a->numero - 1)){
			printf(",");
			
		}else if(cont == (a->numero)){
			printf("\n");
		}
	}
	
}

