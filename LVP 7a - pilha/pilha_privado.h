#ifndef pilha_privado_h
#define pilha_privado_h

#include "pilha_interface.h"

struct pilha {
	void *elementos; // vetor para armazenar os elementos que estao na pilha
	unsigned int tamanho_elemento; //tamanho de um elemento armazenado no vetor
	unsigned int topo; //indice do topo da pilha
	unsigned int capacidade; //capacidade atual da pilha
	void (*imprime)(const void *); //ponteiro para uma funcao de impressao dos elementos armazenados na pilha
};

//coloque aqui funcoes privadas ao TDA

#endif
