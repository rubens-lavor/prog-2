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

int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_mais_arremessos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '2':
            statj_mais_arremessos = jogadores[0].a2.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].a2.arremessos) {
                    statj_mais_arremessos = jogadores[i].a2.arremessos;
                    indice = i;
                }
            }

            break;

        case '3':
            statj_mais_arremessos = jogadores[0].a3.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].a3.arremessos) {
                    statj_mais_arremessos = jogadores[i].a3.arremessos;
                    indice = i;
                }
            }
            break;

        case 'T':
            statj_mais_arremessos = jogadores[0].aT.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].aT.arremessos) {
                    statj_mais_arremessos = jogadores[i].aT.arremessos;
                    indice = i;
                }
            }
            break;

        case 'L':
            statj_mais_arremessos = jogadores[0].aL.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].aL.arremessos) {
                    statj_mais_arremessos = jogadores[i].aL.arremessos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statj_mais_cestas(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_mais_cestas = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '2':
            statj_mais_cestas = jogadores[0].a2.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].a2.cestas) {
                    statj_mais_cestas = jogadores[i].a2.cestas;
                    indice = i;
                }
            }

            break;

        case '3':
            statj_mais_cestas = jogadores[0].a3.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].a3.cestas) {
                    statj_mais_cestas = jogadores[i].a3.cestas;
                    indice = i;
                }
            }
            break;

        case 'T':
            statj_mais_cestas = jogadores[0].aT.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].aT.cestas) {
                    statj_mais_cestas = jogadores[i].aT.cestas;
                    indice = i;
                }
            }
            break;

        case 'L':
            statj_mais_cestas = jogadores[0].aL.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].aL.cestas) {
                    statj_mais_cestas = jogadores[i].aL.cestas;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo) {
    float statj_melhor_percentual = 0.0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '2':
            statj_melhor_percentual = jogadores[0].a2.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].a2.percentual) {
                    statj_melhor_percentual = jogadores[i].a2.percentual;
                    indice = i;
                }
            }

            break;

        case '3':
            statj_melhor_percentual = jogadores[0].a3.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].a3.percentual) {
                    statj_melhor_percentual = jogadores[i].a3.percentual;
                    indice = i;
                }
            }
            break;

        case 'T':
            statj_melhor_percentual = jogadores[0].aT.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].aT.percentual) {
                    statj_melhor_percentual = jogadores[i].aT.percentual;
                    indice = i;
                }
            }
            break;

        case 'L':
            statj_melhor_percentual = jogadores[0].aL.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].aL.percentual) {
                    statj_melhor_percentual = jogadores[i].aL.percentual;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statj_jogos(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_jogos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_jogos = jogadores[0].jogos;

            for (i = 1; i < njogadores; i++) {
                if (statj_jogos < jogadores[i].jogos) {
                    statj_jogos = jogadores[i].jogos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_jogos = jogadores[0].jogos;

            for (i = 1; i < njogadores; i++) {
                if (statj_jogos > jogadores[i].jogos) {
                    statj_jogos = jogadores[i].jogos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statj_idade(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_idade = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_idade = jogadores[0].idade;

            for (i = 1; i < njogadores; i++) {
                if (statj_idade < jogadores[i].idade) {
                    statj_idade = jogadores[i].idade;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_idade = jogadores[0].idade;

            for (i = 1; i < njogadores; i++) {
                if (statj_idade > jogadores[i].idade) {
                    statj_idade = jogadores[i].idade;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statj_minutos(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_minutos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_minutos = jogadores[0].minutos;

            for (i = 1; i < njogadores; i++) {
                if (statj_minutos < jogadores[i].minutos) {
                    statj_minutos = jogadores[i].minutos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_minutos = jogadores[0].minutos;

            for (i = 1; i < njogadores; i++) {
                if (statj_minutos > jogadores[i].minutos) {
                    statj_minutos = jogadores[i].minutos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statj_pontos(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_pontos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_pontos = jogadores[0].pontos;

            for (i = 1; i < njogadores; i++) {
                if (statj_pontos < jogadores[i].pontos) {
                    statj_pontos = jogadores[i].pontos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_pontos = jogadores[0].pontos;

            for (i = 1; i < njogadores; i++) {
                if (statj_pontos > jogadores[i].pontos) {
                    statj_pontos = jogadores[i].pontos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

int statt_soma_pontos(jogador_t jogadores, int njogadores, char time) {
}

float statt_media_pontos(jogador_t jogadores, int njogadores, char time) {
}

float statt_media_idade(jogador_t jogadores, int njogadores, char time) {
}

int statt_posicao(jogador_t jogadores, int njogadores, char *time, char posicao) {
}
