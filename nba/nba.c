#include "nba.h"

int le_cabecario(char *nome) {
    if (nome == NULL) {
        return -1;
    }

    FILE *pont = fopen(nome, "r");

    if (pont == NULL) {
        return 0;
    }

    /*ler a quantidde de jogadores*/
}

jogador_t *le_jogadores(char *nome, int *njogadores) {
    if (njogadores == NULL || nome == NULL) {
        return NULL;
    }

    FILE *ptr;

    ptr = abre_nome(nome);

    if (ptr == NULL) return NULL;

    double *armazena, aux;

    *njogadores = 0;

    if (fscanf(ptr, "%lf", &aux) == EOF) {
        fclose(ptr);
        return NULL;
    }

    rewind(ptr);

    fscanf(ptr, "%lf", &aux);

    while (!feof(ptr)) {
        *njogadores += 1;
        fscanf(ptr, "%lf", &aux);
    }

    armazena = (double *)malloc(sizeof(double) * *njogadores);

    if (armazena == NULL) return NULL;

    rewind(ptr);

    for (int i = 0; i < *njogadores; i++) {
        fscanf(ptr, "%lf", &aux);
        armazena[i] = aux;
    }

    return armazena;
}

int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo){}

int statj_mais_cestas(jogador_t *jogadores, int njogadores, char tipo){}

int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo){}

int statj_jogos(jogador_t *jogadores, int njogadores, char tipo){}

int statj_idade(jogador_t *jogadores, int njogadores, char tipo){}

int statj_minutos(jogador_t *jogadores, int njogadores, char tipo){}

int statj_pontos(jogador_t *jogadores, int njogadores, char tipo){}

int statt_soma_pontos(jogador_t jogadores, int njogadores, char time){}

float statt_media_pontos(jogador_t jogadores, int njogadores, char time){}

float statt_media_idade(jogador_t jogadores, int njogadores, char time) {}

int statt_posicao(jogador_t jogadores, int njogadores, char *time, char posicao) {}
