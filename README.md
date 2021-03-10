# Programação 2

Atividades propostas por meio de LVPs (Laboratório virtual de programação), da disciplina de Programação 2 - Estrutura de dados. 

Os arquivos de cabeçalho ".h" contém o protótipo de cada função e comentários com a descrição detalhada de como elas devem ser implementadas dentro do arquivo correspondente ".c"

---

## 📂 LVP 2 arquivo sequencial


Considere um arquivo de acesso sequencial (i.e., arquivo texto plano) que contenha dois numeros reais por linha. 

A tarefa desse laboratório virtual de programação é implementar funções para o processamento dos números contidos no arquivo. 

As funções implementadas foram:

  - Encontrar o maior número.
  - Encontrar o menor número.
  - Calcular a média dos números.
  - Calcular o desvio-padrão dos números.
  - A amplitude dos números (diferença entre o maior e o menor número).
  - Encontrar o número que mais se repete e quantas vezes ele aparece (em caso de igualdade, o primeiro encontrado tem preferência)
  - Encontrar o número que está na n-esíma posição

Além de outras 3 funções auxiliares:

  - Uma função que retorna um array unidimensional contendo todos os valores lidos de um arquivo, bem como o número total de valores lidos.
  - Uma função que realiza a abertura de um arquivo.
  - Uma função que realiza o fechamento de um arquivo.

O arquivo "lab3.h" contém a descrição e o protótipo de cada função que deverá ser implementada dentro do arquivo "lab3.c".


Esse laboratório envolve os tópicos:

  - Entrada e Saída: Arquivos.
  - Alocação Dinâmica de Memória.
  - Funções


---

## 📂 LVP 3 - recursão


---

## 📂 LVP 4 - arquivo binário

Considere um arquivo de acesso aleatório (i.e., arquivo binário) que contenha informações sobre times de futebol e seus respectivos jogadores. As informações armazenadas de cada time são:
- Nome, estado do time, dia, mes e ano da fundação do time;
- Número de títulos do campeonato brasileiro, da copa do brasil, da libertadores da américa e estaduais;
Além disso, cada time possui 21 jogadores, sendo que para cada jogador existe as seguintes informações:
- Nome do jogador;
- Posição do jogador, sendo do tipo inteiro (0 para goleiro, 1 zagueiro, 2 lateral, 3 volante, 4 meio e 5 atacante),
- Número de gols marcados, de bolas roubadas, de jogos disputados, finalizações certas, finalizações erradas, faltas recebidas, faltas cometidas, cartões vermelhos, cartões amarelos, penaltis defendidos e defesas realizadas.

A tarefa desse laboratório virtual de programação é implementar funções para o processamento de informações sobre os times e sobre os seus jogadores. As seguintes funções são requisitadas:

- Encontrar o jogador que tem o maior número de cartões vermelhos no menos número de jogos.
- Encontrar o jogador artilheiro, aquele que tem o maior número de gols.
- Encontrar o jogador mais eficiente, aquele que fez mais gols em menos jogos.
- Encontrar time com mais títulos, sendo uma proporcao entre o numero de titulos (soma de todos os titulos) e o ano de fundacao (considere apenas o ano).
- Encontrar o goleiro que defendeu mais penaltis.
- Encontrar o jogador mais agressivo, considerando peso 5 para cartao vermelho, 1 para amarelo e 0.2 para faltas cometidas.

Além dessas funções, são necessárias também 3 funções auxiliares:

- Uma função que retorna uma estrutura contendo todos os times lidos de um arquivo, bem como o número de times.
- Uma função que realiza a abertura de um arquivo.
- Uma função que realiza o fechamento de um arquivo.

O arquivo "lab4.h" contém a descrição e o protótipo de cada função que deverá ser implementada dentro do arquivo "lab4.c". O arquivo "definicoes.h" contém duas estruturas, times_t e jogador_t, que devem ser usadas pelas funções.
Um arquivo contendo alguns times, que servirá de modelo, está disponível para download. Você pode usar esse arquivo modelo para testar a sua implementação. Entretanto, lembre-se o número de times pode (e irá) variar (o arquivo de entrada poderá inclusive estar vazio). Os nomes de times, jogadores e valores de cada estatística foram gerados de forma aleatória, portanto, serão strings de texto que provavelmente não fazem sentido quando lidas.

Esse laboratório envolve os tópicos:
  - Entrada e Saída: Arquivos
  - Alocação Dinâmica de Memória
  - Estruturas e Estruturas Aninhadas
  - Funções

---

## 📂 LVP 5 - TAD conjunto

Neste VLP você deverá construir um Tipo Abstrato da Dados (TAD) para manipulação de conjuntos. O arquivo "conjunto_privado.h" contém a definição da estrutura para os conjuntos, chamada de "conjunto_t".
As operações implementadas são:
- Criar um conjunto;
- Destruir um conjunto;
- Retornar o número de elementos dentro do conjunto;
- Inicializar um conjunto como conjunto vazio;
- Realizar a união entre dois conjuntos;
- Realizar a intersecção entre dois conjuntos;
- Realizar a diferença entre dois conjuntos;
- Verificar se um elemento pertence ou não a um conjunto;
- Inserir um elemento em um conjunto;
- Remover um elemento em um conjunto;
- Atribuir um conjunto a outro (exemplo: conjunto a = conjunto b);
- Verificar se dois conjuntos são iguais;
- Retornar o valor do menor elemento dentro de um conjunto;
- Retornar o valor do maior elemento dentro de um conjunto;
- Imprimir todos os elementos do conjunto;

Os seguintes arquivos estão disponíveis:
- "conjunto_privado.h": possui a declaração da estrutura interna do TAD conjunto, conjunto_t, bem como possíveis funções internas ao TAD. Define ELEMENTOS com o valor 10, sendo que esta constante deverá ser utilizada para criar um conjunto que poderá conter inicialmente o número de 10 ELEMENTOS. Note que o tamanho do conjunto poderá aumentar conforme forem inseridos elementos, podendo ultrapassar o valor de ELEMENTOS. Certifique-se de controlar esse caso na sua implementação.
- "conjunt_interface.h": contém as declarações das operações do TAD conjunto, contendo uma descrição, pré-condições e pós-condições para cada operação.
- "conjunto.c": deve conter a implementação das funções da interface do TAD conjunto.

Esse laboratório envolve os tópicos:
- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TAD

A dinâmica desse laboratório segue o estilo dos laboratórios 2 e 3.


---

## 📂 LVP 6a - lista duplamente encadeada

Este LVP trata da implementação de uma Lista de nós duplamente encadeada de ponteiros genérica, com as seguintes operações:
- Criação da lista;
- Destruição da lista;
- Verificar se a lista está vazia;
- Retornar o tamanho da lista, ou seja, quantos elementos estão armazenados na lista;
- Retornar a célula cabeça da lista;
- Retornar a célula cauda da lista;
- Retornar o dado armazenado em uma célula;
- Retornar a próximo célula, recebendo uma célula como parâmetro;
- Retornar a célula anterior, recebendo uma célula como parâmetro;
- Verificar se uma dada célula é cabeça da lista;
- Verificar se uma dada célula é cauda da lista;
- Inserir um elemento após uma dada célula da lista;
- Inserir um elemento antes de uma dada célula da lista;
- Inserir um elemento em uma dada posição da lista;
- Inserir um elemento na lista de forma ordenada (ordem crescente);
- Remover uma célula da lista;
- Imprimir a lista;
- Retornar a célula que conter um determinado elemento de forma recursiva;
- Separar uma lista em duas e retornar a nova lista;
- Concatenar duas listas e retornar a nova lista criada (concatenada) e destruir as duas listas recebidas.

Para a implementação do TDA Lista duplamente encadeada genérico, os seguintes arquivos estão disponíveis:

- "lista_interface.h": Arquivo contendo a declaração das operações da lista, com pré e pós condições para cada operação e uma pequena descrição do comportamento esperado da operação;
- "lista_privado.h": Arquivo contendo as declaraçãos das estruturas de dados lista e celula. As estruturas de dados não devem ser modificadas em hipótese alguma;
- "lista.c": Arquivo que deverá conter a implementação das operações.

Esse laboratório envolve os tópicos:
- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TDA
- TDA Lista duplamente encadeada genérico
A dinâmica desse laboratório segue o estilo dos laboratórios anteriores.

---
## 📂 LVP 8 - fila

Este LVP trata da implementação de uma Fila encadeada (ou ligada) de ponteiros genérica, com as seguintes operações:

- Criação da fila;
- Destruição da fila;
- Verificar se a fila está vazia;
- Retornar o tamanho da fila, ou seja, quantos elementos estão armazenados na fila;
- Enfileirar um elemento na fila;
- Enfileirar um elemento na fila de forma ordenada (ordem crescente);
- Desenfileirar um elemento na fila;
- Retornar o elemento da cabeça da fila;
- Retornar o elemento da cauda da fila;
- Imprimir a fila;

Para a implementação do TDA fila genérico, os seguintes arquivos estão disponíveis:

- "fila_interface.h": Arquivo contendo a declaração das operações da fila, com pré e pós condições para cada operação e uma pequena descrição do comportamento esperado da operação;

- "fila_privado.h": Arquivo contendo as declaraçãos das estruturas de dados fila_t e celula_t. As estruturas de dados não devem ser modificadas em hipótese alguma;

- "fila.c": Arquivo que deverá conter a implementação das operações;

Esse laboratório envolve os tópicos:

Alocação Dinâmica de Memória
Estruturas
Funções
Organização no formato de TDA
TDA fila


---
## 📂 LVP 9 - árvore binária

Este LVP trata da implementação de uma árvore binária de busca (ABB) de ponteiros genérica.
A ABB deverá deverá ter as seguintes operações:
- Criação;
- Destruição;
- Verificar se a árvore está vazia;
- Inserir um elemento na árvore;
- remove um elemento
- Criar uma árvore a partir de um vetor
- Retorna a raiz
- Retorna o tamanho
- Valor pertence a árvore
- Se o nó é folha
- Retorna o filho esquerdo ou direito de um nó
- Altura da árvore

Para a implementação do TDA ABB genérico, os seguintes arquivos estão disponíveis:
- "abb_interface.h": Arquivo contendo a declaração das operações da ABB, com pré e pós condições para cada operação e uma pequena descrição do comportamento esperado da operação;
- "abb_privado.h": Arquivo contendo as declaraçãos das estruturas de dados abb e no. As estruturas de dados não devem ser modificadas em hipótese alguma;
- "abb.c": Arquivo que deverá conter a implementação das operações;
- "comum.h" : declaraçãoo de funções e do tipo enum codigo_erro que deverá ser utilizada para indicar erro de acordo com as funções da abb interface
- "comum.c" : implementaçao das funções comuns (não é necessário implementar a função)

Esse laboratório envolve os tópicos:
- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TDA
- TDA ABB genérico

---
## 📂 LVP 10 - busca e ordenação

Este LVP trata da prática com algoritmos de ordenação e busca.
Deverão ser implementados os seguintes algoritmos:
- Quicksort genérico
- Bolha em uma lista duplamente encadeada
- Pesquisa binária

Use a mesma lista duplamente encadeada implementada no LVP 7. É permitido inserir novas operações na lista caso seja necessário.
Lembrem-se que operações privadas aos algoritmos devem ser implementadas dentro dos seus respectivos arquivos privados.

Esse laboratório envolve os tópicos:
- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TDA
- Uso do TDA Lista duplamente encadeada genérico
- Pesquisa e ordenação de dados