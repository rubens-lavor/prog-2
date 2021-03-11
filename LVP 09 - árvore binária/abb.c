#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_privado.h"

//coloque aqui a implementacao das operacoes do TDA generico arvore binaria de busca

abb_t*      abb_criar       (void (*imprimir)(const void *data),
                             void (*destruir)(void **data),
                             int (*compara)(const void *key1, const void* key2)){

    if(compara == NULL){
        return NULL;
    }

    abb_t *ptr = (abb_t *) malloc(sizeof(abb_t));
    if(ptr == NULL){
        return NULL;
    }

    ptr->tamanho=0;
    ptr->raiz=NULL;
    ptr->destroi=destruir;
    ptr->imprime=imprimir;
    ptr->compara=compara;

    return ptr;

    }

abb_t*      abb_criar_de_vetor (void* vetor, int tamanho_vetor, int tamanho_elemento,
                             void (*imprimir)(const void *data),
                             void (*destruir)(void **data),
                             int (*compara)(const void *key1, const void* key2)){

    if(vetor == NULL || tamanho_vetor <= 0 || tamanho_elemento <= 0 || compara == NULL) return NULL;

    abb_t * ptr = abb_criar(imprimir,destruir,compara);
    if(ptr == NULL) return NULL;

    for(int i = 0; i < tamanho_vetor; i++){	 	  	 	      	      		 	      		    	 	
        abb_insere(ptr, (vetor + tamanho_elemento*i));
    }

    return ptr;

    }

codigo_erro abb_destroi(abb_t** arv){   //VERIFICAR
    if(arv == NULL || *arv == NULL) return INVALIDO;

    while((*arv)->raiz != NULL){
        abb_remove(((*arv)),((*arv)->raiz->info));
    }
    free(*arv);
    *arv = NULL;

    return (SUCESSO);
}

bool        abb_vazia       (const abb_t* arv){

    if(arv == NULL){
        return true;
    }

    if(arv->tamanho == 0){
        return true;
    }

    return false;

    }

long        abb_tamanho     (const abb_t* arv){

    if(arv == NULL){	 	  	 	      	      		 	      		    	 	
        return -1;
    }

    return arv->tamanho;

    }

codigo_erro abb_insere(abb_t* arv, void* data){
    
    if(arv == NULL) return INVALIDO;
    if(arv->compara == NULL) return ESTADO_INVALIDO;
    if(data == NULL) return VALOR_INVALIDO;

    node_t *extra = (node_t *) malloc(sizeof(struct nodearv));
    extra->info = data;
    extra->direita = NULL;
    extra->esquerda = NULL;

    if(arv->tamanho == 0){
        arv->raiz = extra;
        arv->tamanho++;
        return (SUCESSO);
    }else{
        node_t *father = NULL;
        node_t *son = arv->raiz;

        while(son != NULL){
            if(arv->compara(son->info, extra->info) == -1){
                father = son;
                son = son->direita;
            }else if(arv->compara(son->info, extra->info) == 0){
                free(extra);
                return (DUPLICADO);
            } else{
                father = son;
                son = son->esquerda;
            }	 	  	 	      	      		 	      		    	 	
        }
        
        if(arv->compara(father->info,extra->info) == 1){
            father->esquerda = extra;
        }else{
            father->direita = extra;
        }
        arv->tamanho++;
        return (SUCESSO);
    }
}

node_t* destroi_no(abb_t* arv,node_t* extra){
    if(extra == NULL) return NULL;
    node_t *no1 = NULL,*no2 = NULL;

    if(extra->esquerda == NULL){
        no2 = extra->direita;
        if(arv->destroi != NULL){
            arv->destroi(&extra->info);
        }
        free(extra);
        return no2;
    }else{
        no1 = extra;
        for(no2 = extra->esquerda; no2->direita != NULL; no2 = no2->direita){
            no1 = no2;
        }
        if(no1 != extra){
            no1->direita = no2->esquerda;
            no2->esquerda = extra->esquerda;
        }
        no2->direita = extra->direita;

        free(extra);
        return (no2);
    }	 	  	 	      	      		 	      		    	 	
}

codigo_erro abb_remove(abb_t* arv, const void* data){
    if(arv == NULL || arv->tamanho <= 0) return (UNDER_FLOW);
    if(data == NULL) return (VALOR_INVALIDO);
    

    node_t *extra = arv->raiz;
    node_t *father = NULL;


    
    if(arv->compara != NULL){
        while(extra != NULL){

            if(arv->compara(extra->info,data) == 0){
                
		        if(extra == arv->raiz){
		            arv->raiz = destroi_no(arv,extra); 
		            
                    arv->tamanho--;
                    extra = NULL;
                    return (SUCESSO);
		        }else if(father->direita == extra){
                    father->direita = destroi_no(arv,extra);
                  
                    arv->tamanho--;
                    extra = NULL;
                    return (SUCESSO);
		        }else{
                
                    father->esquerda = destroi_no(arv,extra);
                    arv->tamanho--;
                    extra = NULL;
                    return (SUCESSO);
                }	 	  	 	      	      		 	      		    	 	
            }else if(arv->compara(extra->info,data) == 1){
                father = extra;
                extra = extra->esquerda;
            }else if(arv->compara(extra->info,data) == -1){
                father = extra;
                extra = extra->direita;
            } 
        }
        return (VALOR_INVALIDO);
    }else return (INVALIDO);//ALGO ERRADO
}

bool abb_busca_bin(const abb_t* arv, void* info){
    if(arv == NULL || arv->tamanho == 0) return false;

    if(repetido(arv,arv->raiz,info) == true){
        return true;
    }else return false;
}

const node_t*     abb_raiz(const abb_t* arv){

    if(arv == NULL || arv->tamanho == 0){
        return NULL;
    }

    return arv->raiz;

}

const node_t*     abb_esq(const node_t* raiz){

    if(raiz == NULL){
        return NULL;
    }

    return raiz->esquerda;

}	 	  	 	      	      		 	      		    	 	

const node_t*     abb_dir(const node_t* raiz){

    if(raiz == NULL){
        return NULL;
    }

    return raiz->direita;

}

const void* 	  abb_info(const node_t* node){

    if(node == NULL){
        return NULL;
    }

    return node->info;

}

bool        abb_node_ehfolha(const node_t* node){

    if(node == NULL){
        return true;
    }
    if(node->direita == NULL && node->esquerda == NULL){
        return true;
    }

}

codigo_erro abb_altura(abb_t* arv, unsigned long *altura){
    if(arv == NULL || altura == NULL || arv-> tamanho == 0){
        *altura = (-1);
        return (INVALIDO);
    }	 	  	 	      	      		 	      		    	 	
    unsigned long int x = (altura_arv(arv,(arv)->raiz)-1);
    *altura = x;
   
    return(SUCESSO);
}

unsigned long int altura_arv(abb_t* arv, node_t* node){

    if(arv == NULL || node == NULL) return (0);
    else if (altura_arv(arv, node->direita) > altura_arv(arv, node->esquerda)){
        return (1+altura_arv(arv, node->direita));
    }
    else return (1+altura_arv(arv, node->esquerda));
}

bool repetido(const abb_t* arv, node_t* no, void* info){
    if(arv == NULL || arv->raiz == NULL || info == NULL || no == NULL) return false;

    if(arv->compara(no->info,info) == 0) return true;
    else if(arv->compara(no->info,info) == 1){
        return repetido(arv,no->esquerda,info);
    }else if(arv->compara(no->info,info) == -1){
        return repetido(arv,no->direita,info);
    }
    return false;
}	 	  	 	      	      		 	      		    	 	
