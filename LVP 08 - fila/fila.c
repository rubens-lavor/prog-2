#include "fila_privado.h"


/*
 * Cria uma fila e a inicializa como fila vazia. 
 * "imp" eh um ponteiro para uma funcao de impressao dos dados armazenados dentro da fila. Deve ser usado em "fila_imprime". 
 * o argumento "libera" prove uma maneira de liberar dinamicamente os dados dentro da celula quando "fila_destroi" eh chamada. 
 * Para uma fila onde os dados nao devem ser liberados, libera deve ser NULL 
 * "comparar" eh um ponteiro para funcao de comparacao entre dois dados armazenados na fila. 
 * Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo   
 * Pre: nenhuma
 * Pos: Retorna um ponteiro para uma fila vazia se houver memaria disponivel
 */
fila_t *fila_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){
    
    fila_t *f;
    
    f = (fila_t*) malloc(sizeof(fila_t));
    
    if(f == NULL){
        return NULL;
    }
    
    f->cabeca = NULL;
    f->cauda = NULL;
    f->tamanho = 0;
    f->destruir = libera;
    f->imprime = imp;
    f->compara = comparar;
    
    return f;
       
}

/*
 * Destroi a fila especificada em "f". Nenhuma operacao eh permitida apos a funcao, a nao ser que fila cria seja chamada novamente. 
 * Destroi todos os elementos armazenados na fila, se o ponteiro "destruir" for valido
 * Pre: "f" deve ser uma fila valida criada previamente atraves da funcao fila cria
 * Pos: os recursos da fila foram liberados com sucesso e a fila "f" torna-se nula
 */
void fila_destroi(fila_t **f){
    
    if(*f == NULL || f == NULL){
        return;
    }
    
    if((*f)->destruir == NULL){
        celula_t *c, *aux;
        
        c = (*f)->cabeca;
        
        while(c != NULL){
            aux = c;
            
            free(aux);
            (*f)->tamanho--;
            c = c->prox;
        }
        free(*f);
        *f = NULL;
    }else{
        
        celula_t *c, *aux;
        
        c = (*f)->cabeca;
        
        while(c != NULL){
            aux = c;
            (*f)->destruir(aux->dado);
            
            free(aux);
            (*f)->tamanho--;
            c = c->prox;
        }
        
        free(*f);
        *f = NULL;
        
    }
    
    
}

/*
 * Retorna 1 se a fila estiver vazia, 0 caso contrario
 * Pre: a fila deve existir
 * Pos: retorna 1 caso a fila estiver vazia, 0 se nao estiver. Retorna -1 caso a fila nao existir
 */
int fila_vazia(fila_t *f){
    if(f == NULL){
        return -1;
    }
    
    if(f->tamanho == 0){
        return 1;
    }
    
    return 0;
    
}

/*
 * Retorna o tamanho da fila
 * Pre: a fila deve existir
 * Pos: retorna o tamanho da fila. Retorna -1 caso a fila nao existir
 */
int fila_tamanho(fila_t *f){
    if(f == NULL){
        return -1;
    }
    
    return (f->tamanho);
}

/*
 * Enfileira um novo elemento na fila. O ponteiro "elem" eh inserido em uma celula da fila. 
 * Eh responsabilidade de quem chama o gerenciamento da memoria de "elem", onde ela devera permanecer valida enquanto estiver dentro da fila.
 * Retorna 1 caso conseguir enfileirar, 0 caso contrario
 * Pre: a fila deve existir e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh a nova cauda da fila
 */
int fila_enfileira(fila_t *f, void *elem){
    
    if(f == NULL || elem == NULL){
        return 0;
    }
    
    celula_t *c, *cauda;
    
    c = (celula_t*) malloc(sizeof(celula_t));
    
    if(c == NULL){
        return 0;
    }
    
    if(fila_vazia(f) == 1){
        c->dado = elem;
        f->cabeca = c;
        f->cauda = c;
        c->prox = NULL;

    }else{
        c->dado = elem;
        c->prox = NULL;
        cauda = f->cauda;
        cauda->prox = c;
        f->cauda = c;
        
    }
    f->tamanho++;
    return 1;
    
    
}


/*
 * Enfileira um novo elemento na fila de forma ordenada (crescente). Caso o ponteiro "elem" tenha um valor igual a um elemento que estiver na fila, a insercao de "elem" deve ser feita logo apos.
 * Eh responsabilidade de quem chama o gerenciamento da memoria de "elem", onde ela devera permanecer valida enquanto estiver dentro da fila.
 * Caso o ponteiro de funcao "compara" for NULL, a insercao de "elem" deve ser feita na cauda da fila.
 * Retorna 1 caso conseguir enfileirar, 0 caso contrario
 * Pre: a fila deve existir e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh inserido de forma ordenada (crescente)
 */
int fila_enfileira_ordenado(fila_t *f, void *elem){

	if(f==NULL || elem==NULL){
		return 0;
	}
	
	if(f->compara==NULL || f->tamanho==0){
		return fila_enfileira(f,elem);
		
	}
	
	celula_t * aux = f->cabeca;
    
    if(f->tamanho == 1){
        
        if(f->compara(elem,aux->dado) == 1 || f->compara(elem,aux->dado) == 0){	 	  	 	    	   	     	    		   	       	 	
            return fila_enfileira(f,elem);
        }else{
            
            celula_t *c_nova = (celula_t*) malloc(sizeof(celula_t));
        
            if(c_nova == NULL){
                return 0;
            }
            
            c_nova->prox = f->cabeca;
            c_nova->dado = elem;
            f->cabeca = c_nova;
            
        }
        f->tamanho ++;
        return 1;
    }
    aux = f->cabeca;
    if(f->compara(elem,aux->dado) == -1 ){
        
            celula_t *c_nova = (celula_t*) malloc(sizeof(celula_t));
        
            if(c_nova == NULL){
                return 0;
            }
            
            c_nova->prox = f->cabeca;
            c_nova->dado = elem;
            f->cabeca = c_nova;
            f->tamanho ++;
            return 1;
    }
    
    while(aux->prox!=NULL){
        
        if( (f->compara(elem,aux->dado)==1 || f->compara(elem,aux->dado)==0) && f->compara(elem,aux->prox->dado)== -1){	 	  	 	    	   	     	    		   	       	 	
            celula_t *c_nova = (celula_t*) malloc(sizeof(celula_t));
        
            if(c_nova == NULL){
                return 0;
            }
            
            c_nova->dado = elem;
            c_nova->prox = aux->prox;
            aux->prox = c_nova;
            f->tamanho ++;
            return 1;
            
        }else{
            aux = aux->prox;
        }
    }
	return fila_enfileira(f,elem);
}

/*
 * Desenfileira o elemento que estiver na cabeca da fila e retorna o seu valor em "elem". Eh responsabilidade de quem chama gerenciar a memoria de "elem".
 * Retorna 1 caso conseguir desenfileirar, 0 caso contrario
 * Pre: a fila deve existir e nao deve estar vazia. "elem" deve ser valido
 * Pos: a fila tera um elemento a menos e o valor da antiga cabeca eh retornado
 */
int fila_desenfileira(fila_t *f, void **elem){

	if(f==NULL || fila_vazia(f)==1 || elem==NULL){
		return 0;
	}
	
	celula_t *c=f->cabeca;
	*elem = c->dado;
	f->cabeca = c->prox;
	
	
	if (f->tamanho==1){
	    f->cauda = NULL;
	}
	free(c);
	f->tamanho--;
	return 1;
}	 	  	 	    	   	     	    		   	       	 	


/*
 * Retorna o valor do elemento na cabeca da fila em "elem". Retorna 1 caso a fila ter um valor na sua cabeca, 0 caso contrario
 * Pre: a fila deve existir e nao deve estar vazia. "elem" deve ser valido
 * Pos: o valor do elemento da cabeca eh retornado em uma variavel
 */
int fila_cabeca(fila_t *f, void **elem){
    
    if(f == NULL || elem == NULL || fila_vazia(f) == 1){
        return 0;
    }
    
    celula_t *c;
    c = f->cabeca;
    *elem = c->dado;
    
    return 1;
    
}

/*
 * Retorna o valor do elemento na cauda da fila em "elem". Retorna 1 caso a fila ter um valor na sua cauda, 0 caso contrario
 * Pre: a fila deve existir e nao deve estar vazia. "elem" deve ser valido
 * Pos: o valor do elemento da cauda eh retornado em uma variavel
 */
int fila_cauda(fila_t *f, void **elem){
    
    if(f == NULL || elem == NULL || fila_vazia(f) == 1){
        return 0;
    }
    
    celula_t *c;
    c = f->cauda;
    *elem = c->dado;
    
    return 1;
    
}

/*
 * Imprime os elementos da fila atraves do ponteiro de funcao "imprime", comecando pela cabeca da fila
 * Pre: a fila deve existir e o ponteiro "imprime" deve ser valido
 * Pos: Os elementos sao impressos usando o ponteiro "imprime"
 */
void fila_imprime(fila_t *f){
    
    if(f == NULL || f->imprime == NULL){
        return;
    }
    
    celula_t *c;
    c = f->cabeca;
    
    while(c != NULL){
        f->imprime(c->dado);
        c = c->prox;
    }
}