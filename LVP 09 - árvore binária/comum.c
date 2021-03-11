#include "comum.h"

const char* codigo_erro_cstr(codigo_erro erro_n) {
    switch (erro_n) {
    case ERRO:
        return "ERRO";
    case SUCESSO:
        return "SUCESSO";
    case INVALIDO:
        return "INVALIDO";
    case BAD_ALLOCATION:
        return "BAD_ALLOCATION";
    case POSICAO_INVALIDA:
        return "POSICAO_INVALIDA";
    case ESTADO_INVALIDO:
        return "ESTADO_INVALIDO";
    case OVER_FLOW:
        return "OVER_FLOW";
    case UNDER_FLOW:
        return "UNDER_FLOW";
    case DUPLICADO:
        return "DUPLICADO";
    case VALOR_INVALIDO:
        return "VALOR_INVALIDO";
    default:
        return "CODIGO DESCONHECIDO";
    }
}	 	  	 	      	      		 	      		    	 	
