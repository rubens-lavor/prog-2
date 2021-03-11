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


Esse laboratório envolve os tópicos:

  - Entrada e Saída: Arquivos.
  - Alocação Dinâmica de Memória.
  - Funções


---

## 📂 LVP 3 - recursão

Preenchimento de um tabuleiro por recursividade

---

## 📂 LVP 4 - arquivo binário

Considere um arquivo de acesso aleatório (i.e., arquivo binário) que contenha informações sobre times de futebol e seus respectivos jogadores.

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

Esse laboratório envolve os tópicos:
- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TAD

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

Esse laboratório envolve os tópicos:
- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TDA
- TDA Lista duplamente encadeada genérico
A dinâmica desse laboratório segue o estilo dos laboratórios anteriores.

---
## 📂 LVP 7a - pilha

Fuções implementadas:

- cria pilha
- destroi pilha
- pilha vazia 
- pilha cheia 
- tamanho pilha
- empilha
- desempilha
- topo pilha 
- imprime pilha 

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

Esse laboratório envolve os tópicos:

- Alocação Dinâmica de Memória
- Estruturas
- Funções
- Organização no formato de TDA
- TDA fila


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