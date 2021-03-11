#ifndef _ABB_PRIV_H
#define _ABB_PRIV_H

#include "abb_interface.h"

struct nodearv{
    void* info;
    /*vários outros dados*/
    node_t* esquerda;
    node_t* direita;
};

struct arvorebb{
    long tamanho;
    node_t* raiz;
    void (*destroi)(void **data);
    void (*imprime)(const void *data);
    int (*compara)(const void *key1, const void* key2); //Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo
};

#endif