## Atividades Práticas

1. Utilizando a TAD de Pilha com Ponteiro, escreva uma função para converter um número decimal para binário. Lembre-se de:

- Dividir por 2 e anotar o resto (da direita para a esquerda);
- Pegar a parte inteira;
- Dividir por 2 e anotar o resto.

  Exemplo:

* 13/2 = 6			Resto **1**
* 6/2 = 3			Resto **0**
* 3/2 = 1			Resto **1**
* 1/2 = 0			Resto **1**
* 0				**Fim**

  Resultado: **1101**

2. Elabore duas funções para consultar em uma pilha dinâmica a existência de um item. Considere que o item possa ser pesquisado por id (primeira função) ou nome (segunda função), utilizando a TAD vista em aula.

   void ConsultaPorID(TipoPilha *pilha, int id);

   void ConsultaPorNome(TipoPilha *pilha, char nome[]);
