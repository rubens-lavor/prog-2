#include "pilha_privado.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Coloque aqui a implementacao das funcoes do TDA pilha generico
pilha_t *pilha_cria(int cap, int tam_elemento, void (*imp)(const void *)){
    
    if(cap < 0 || tam_elemento < 0){
        return NULL;
    }
    
    pilha_t *dados = (pilha_t *) malloc(sizeof(pilha_t));
    if(dados == NULL){
        return NULL;
    }
    
    dados->capacidade = cap;
    dados->elementos = (void *) malloc(cap*tam_elemento);
    if(dados->elementos == NULL){
        return NULL;
    }
    
    dados->tamanho_elemento = tam_elemento;
    dados->topo = 0;
    dados->imprime = imp;
    
    return dados;
}

void pilha_destroi(pilha_t **p){
    if(p == NULL || *p == NULL){
        return;
    }
    
    free((*p)->elementos);
    (*p)->elementos = NULL;
    
    free(*p);
    (*p) = NULL;
}

int pilha_vazia(pilha_t *p){
    if(p == NULL) return -1;
    
    if(p->topo == 0){	 	  	 	      	      	   	     	  	     	  	 	
        return 1;
    }else{
        return 0;
    }
}

int pilha_cheia(pilha_t *p){
    if(p == NULL) return -1;
    
    if(p->topo >= p->capacidade){
        return 1;
    }else{
        return 0;
    }
}

int pilha_tamanho(pilha_t *p){
    if(p == NULL) return -1;
    
    return (p->topo);
}

int pilha_empilha(pilha_t *p, void *elem){
    if(p == NULL || elem == NULL){
        return 0;
    }
    
    if(p->topo >= p->capacidade){
        return 0;
    }else{
        
    char *ptr= (char *) p->elementos;
    memcpy(ptr + (p->topo)*(p->tamanho_elemento), elem, p->tamanho_elemento);
    p->topo++;
    
    return 1;
    
    }
}

int pilha_desempilha(pilha_t *p, void *elem){
    if(p == NULL || elem == NULL){
        return 0;
    }
    
    if(p->topo  <= 0){
        return 0;
    }else{
        
        char *ptr= (char *) p->elementos;
        memcpy(elem, ptr + ((p->topo)-1)*(p->tamanho_elemento), p->tamanho_elemento);
        p->topo--;
        
        return 1;
    }
}

int pilha_topo(pilha_t *p, void *elem){
    if(p == NULL || elem == NULL){
        return 0;
    }
    
    if(p->topo  <= 0){
        return 0;
    }else{
        
        char *ptr= (char *) p->elementos;
        memcpy(elem, ptr + ((p->topo)-1)*(p->tamanho_elemento), p->tamanho_elemento);
        
        return 1;
    }
}

void pilha_imprime(pilha_t *p){
    if(p == NULL || p->imprime == NULL){
        return;
    }
    
    if(pilha_vazia(p) == 1){
        return;
    }
    
    void *temporariof = malloc(p->tamanho_elemento);
    
    pilha_t *salva = pilha_cria(p->capacidade, p->tamanho_elemento, NULL);
    
    for(int i = p->topo; i > 0; i--){
        
        pilha_desempilha(p, temporariof);
        (*p->imprime)(temporariof);
        pilha_empilha(salva,temporariof);
    }
    
    //voltar elementos para pilha
    for(int i = salva->topo; i > 0; i--){	 	  	 	      	      	   	     	  	     	  	 	
        pilha_desempilha(salva,temporariof);
        pilha_empilha(p,temporariof);
    }
    free(temporariof);
    pilha_destroi(&salva); 
    
}