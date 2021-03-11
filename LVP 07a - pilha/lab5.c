#include "lab5.h"
//coloque aqui a solucao para o problema do estacionamento

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_interface.h"

FILE *abre_arquivo(const char *arquivo){
     FILE *P_arquivo;
     if(arquivo == NULL)
         return NULL;
    P_arquivo = fopen(arquivo, "r");
    return (P_arquivo);
}

int fecha_arquivo(FILE *arq){
     if(!arq) return 1;
     if(fclose(arq) == 0)
         return 0;
}

void imprimi(const void *dado ){
    const carro_t *aux = (const carro_t*) dado;
    
    printf("%s e manobras: %d\n",aux->placa,aux->manobras);
}

//coloque aqui a solucao para o problema do estacionamento
void estacionamento(const char *arquivo, void (*entrada)(carro_t *), void (*saida)(carro_t *)){
    FILE *arq = abre_arquivo(arquivo);
    if(arq == NULL || entrada == NULL || saida == NULL){
        return;
    }
    
    //criando pilha para alocar carro_t
    pilha_t *pilha = pilha_cria(10, sizeof(carro_t), &imprimi);
    pilha_t *pilha_copia = pilha_cria(10, sizeof(carro_t), NULL);
    carro_t *extra = malloc(sizeof(carro_t));
    if(extra == NULL){
        return;
    }
    
    extra->manobras = 0;
    carro_t *extra1 = malloc(sizeof(carro_t));
    if(extra1 == NULL){
        return;
    }
    
    extra1->manobras = 0;
    char acao, Cplaca[8];
    
    rewind(arq);
    while(fscanf(arq, "%c %[^\n]%*c",&acao,Cplaca) != EOF){	 	  	 	      	      	   	     	  	     	  	 	
        if(acao == 'F'){
            break;
        }
        
        strcpy(extra->placa, Cplaca);
        printf("\n%c %s\n",acao,extra->placa);
        
        if(acao == 'E'){
            
            if(pilha_cheia(pilha) != 1){ //se pilha nao estiver cheia
                pilha_empilha(pilha,extra);
                (*entrada)(extra);
            }else{

                (*entrada)(extra);
                (*saida)(extra);
            }
        }else if(acao == 'S'){
            
            if(pilha_topo(pilha,extra1) == 1){ //se conseguiu ler o topo, retornar valor do topo em extra1:
                if(strcmp (extra1->placa, extra->placa) == 0){//se a placa do topo for igual a placa que ira sair
                    pilha_desempilha(pilha,extra1); //retorna em extra1 o carro_t (com placa) do carro removido que ja estava na saida do estacionamento
                    (*saida)(extra1);
                    }else{
                        while(strcmp (extra1->placa, extra->placa) != 0){
                            pilha_desempilha(pilha,extra1); // retorna valor desempilhado em extra1
                            extra1->manobras++;
                            
                            pilha_empilha(pilha_copia,extra1); //empilha em PILHA_COPIA valor desempilhado de PILHA
                            pilha_topo(pilha,extra1); //atualiza extra1 com carro_t do topo de PILHA
                            
                        }
                        //achou o carro_t que queria e ele esta no topo de PILHA, logo vamos remove-lo e readicionar para a PILHA valores de PILHA_COPIA;
                        (*saida)(extra1);
                        pilha_desempilha(pilha,extra1); //destroi o elemento do topo de PILHA
                        while(pilha_desempilha(pilha_copia,extra1) != 0){ //extra1 fica armazenando elemento desempilhado de pilha_copia
                            
                            pilha_empilha(pilha,extra1);
                        }	 	  	 	      	      	   	     	  	     	  	 	
                    }
            }
            
        }
        pilha_imprime(pilha);
    }
    fecha_arquivo(arq);
    free(extra);
    free(extra1);
    pilha_destroi(&pilha_copia);
    pilha_destroi(&pilha);
}