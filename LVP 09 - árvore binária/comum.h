#ifndef _COMUM_H
#define _COMUM_H

typedef enum {  BAD_ALLOCATION=-20, POSICAO_INVALIDA,
                ESTADO_INVALIDO,    OVER_FLOW,
                UNDER_FLOW,          DUPLICADO,
                VALOR_INVALIDO,     INVALIDO=-1,
                ERRO,               SUCESSO } codigo_erro;

/* funcao utilizada para converter codigo de erro para string */              
const char* codigo_erro_cstr(codigo_erro erro_n);

#endif