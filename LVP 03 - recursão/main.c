//Seu programa para resolver o problema (incluindo uma main).

#include <stdio.h>
#include <stdlib.h>

int escaneia(char matriz_entrada[][11], int posicaoX, int posicaoY){

    int soma=0;

    if(posicaoX <0 || posicaoY <0){
        return 0;
    }else{
        if(matriz_entrada[posicaoX][posicaoY] != ' '){
            return 0;
        }else{
            soma++;
            matriz_entrada[posicaoX][posicaoY]='.';

            soma +=
            escaneia(matriz_entrada,posicaoX+1,posicaoY)+
            escaneia(matriz_entrada,posicaoX-1,posicaoY)+
            escaneia(matriz_entrada,posicaoX,posicaoY+1)+
            escaneia(matriz_entrada,posicaoX,posicaoY-1);

            return soma;
        }
    }

    return 0;

    //se n for espaço livre, se for fora
    //se for espaço, vai chama a funçao return 1
    // jogar alg dkfetente de espaço no espaço caso ja tenha lido(antes do return 1);

}

int main()
{	 	  	 	      	      		 	      		    	 	

    char matriz_entrada[10][11];

    //escaneia o tabuleiro e tranforma numa string 10x10
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<11;j++){
            scanf("%c", &matriz_entrada[i][j]);
            if(j==10){
                matriz_entrada[i][j]='\0';
            }
        }
    }

    int vetor_final[110]; // o quadrado será 10x10 mas pra garantir por 110.
    int regioes=0; //variavel que guarda quantas regioes tem.
    int posicao=0;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            regioes = escaneia(matriz_entrada,i,j);

            if(regioes>0){
                vetor_final[posicao]=regioes;
                posicao++;
            }
        }
    }
    
    //ordena o VETOR_FINAL em ordem crescente
    int temp;
    for (i = 0; i < posicao - 1; i++){
        for (j = (i+1); j < posicao; j++){
            if (vetor_final[j] < vetor_final[i]){
                temp = vetor_final[i];
                vetor_final[i] = vetor_final[j];
                vetor_final[j] = temp;
            }	 	  	 	      	      		 	      		    	 	
        }
    }

    printf("O tabuleiro possui %i regioes, de tamanhos:\n",posicao);

    for(i=0;i<posicao;i++){
        printf("%i",vetor_final[i]);
        if(i!=posicao-1){
            printf(",");
        }
    }
    printf(".");

    return 0;
}
