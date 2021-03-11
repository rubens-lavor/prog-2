# LVP 04 - arquivo binário

 As informações armazenadas de cada time são:
- Nome, estado do time, dia, mes e ano da fundação do time;
- Número de títulos do campeonato brasileiro, da copa do brasil, da libertadores da américa e estaduais;
Além disso, cada time possui 21 jogadores, sendo que para cada jogador existe as seguintes informações:
- Nome do jogador;
- Posição do jogador, sendo do tipo inteiro (0 para goleiro, 1 zagueiro, 2 lateral, 3 volante, 4 meio e 5 atacante),
- Número de gols marcados, de bolas roubadas, de jogos disputados, finalizações certas, finalizações erradas, faltas recebidas, faltas cometidas, cartões vermelhos, cartões amarelos, penaltis defendidos e defesas realizadas.


O arquivo "lab4.h" contém a descrição e o protótipo de cada função que deverá ser implementada dentro do arquivo "lab4.c". O arquivo "definicoes.h" contém duas estruturas, times_t e jogador_t, que devem ser usadas pelas funções.

Um arquivo contendo alguns times, que servirá de modelo, está disponível para download. Você pode usar esse arquivo modelo para testar a sua implementação. Entretanto, lembre-se o número de times pode (e irá) variar (o arquivo de entrada poderá inclusive estar vazio). Os nomes de times, jogadores e valores de cada estatística foram gerados de forma aleatória, portanto, serão strings de texto que provavelmente não fazem sentido quando lidas.
