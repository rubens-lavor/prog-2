## VPL 2
---

Considere um arquivo de acesso sequencial (i.e., arquivo texto plano) que contenha dois numeros reais por linha. 

A tarefa desse laboratório virtual de programação é implementar funções para o processamento dos números contidos no arquivo. As seguintes funções são necessárias:


    • Encontrar o maior número.
    • Encontrar o menor número.
    • Calcular a média dos números.
    • Calcular o desvio-padrão dos números.
    • A amplitude dos números (diferença entre o maior e o menor número).
    • Encontrar o número que mais se repete e quantas vezes ele aparece (em caso de igualdade, o primeiro encontrado tem preferência)
    • Encontrar o número que está na n-esíma posição

Além dessas funções, são necessárias também 3 funções auxiliares:


    • Uma função que retorna um array unidimensional contendo todos os valores lidos de um arquivo, bem como o número total de valores lidos.
    • Uma função que realiza a abertura de um arquivo.
    • Uma função que realiza o fechamento de um arquivo.

O arquivo "lab3.h" contém a descrição e o protótipo de cada função que deverá ser implementada dentro do arquivo "lab3.c".


Esse laboratório envolve os tópicos:

    • Entrada e Saída: Arquivos.
    • Alocação Dinâmica de Memória.
    • Funções


```
/*
 * Abre o arquivo cujo nome eh recebido por parametro ("arquivo") para leitura.
 * Retorna um ponteiro para o arquivo aberto.
 */
FILE *abre_arquivo(const char *arquivo);

/*
 * Fecha o arquivo recebido por parametro.
 * Retorna 0 caso consiga fechar o arquivo, qualquer outro valor caso contrario.
 */
int fecha_arquivo(FILE *arq);

/*
 * Le os valores que estao dentro do "arquivo" e retorna um vetor contendo os valores.
 * Retorna dentro de "qtd_numeros" a quantidade de números existentes dentro do arquivo lido.
 * Caso não for possível ler o arquivo, "qtd_numeros" deve conter ZERO e retornar a constante NULL.
 * Se "qtd_numeros" for invalido, a leitura deve ser invalidade e retornar a constante NULL.
 */
double *le_valores(const char *arquivo, unsigned int *qtd_numeros);

/*
 * Essa função retorna o maior valor presente no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
 * */
double maior(double* valores, unsigned int qtd_numeros);

/*
 * Essa função retorna o menor valor presente no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
 * */
double menor(double* valores, unsigned int qtd_numeros);

/*
 * Essa função retorna a média dos valores presentes no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
 * */
double media(double* valores, unsigned int qtd_numeros);

/*
 * Essa função retorna o desvio padrão dos valores presentes no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
 * */
double desvio(double* valores, unsigned int qtd_numeros);

/*
 * Essa função retorna a mediana dos valores presentes no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
 * */
double mediana(double* valores, unsigned int qtd_numeros);

/*
 * Essa função retorna a amplitude(diferença entre o maior e o menor número) dos valores presentes no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
 * */
double amplitude(double* valores, unsigned int qtd_numeros);

/*
 * Essa função retorna o valor que está localizado em uma "posicao" do array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h).
 * Caso for posição invalida, retorna a constante HUGE_VAL (em math.h).
 * */
double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao);

/*
 * Essa função retorna o número que mais se repete e quantas vezes ele aparece (em caso de igualdade, o primeiro encontrado tem preferência) no array.
 * Retorna dentro de "qtd_repeticao" a quantidade de vezes que o determinado número se repete no array.
 * Caso for um array inválido, retorna a constante HUGE_VAL (em math.h) e ZERO em "qtd_repeticao".
*/
double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao);

```
