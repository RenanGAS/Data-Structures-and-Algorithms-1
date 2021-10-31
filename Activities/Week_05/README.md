# Etapa 4 - Refatoração

## Passo 4.1 - Compilação das unidades sintáticas: TAD e testes

- Criar um arquivo {nome}_TAD.h ;
- Transferir toda a parte que se refere ao tipo abstrato para esse arquivo. (restando apenas a função main, em main.c)
* Importar o novo arquivo no main.c .

## Passo 4.2 - Divisão do conceito e da implementação do TAD

- Criar um arquivo {nome}_TAD.c ;
- Transferir a parte de implementação do TAD para esse arquivo.
* Importar nesse novo arquivo, o {nome}_TAD.h .
* Para testar o funcionamento nessa etapa, temos que compilar o arquivo {nome}_TAD.c :
    - `gcc -c {nome}_TAD.c` ;
    * E em seguida, gerar um "output" do arquivo main e do arquivo compilado juntos:
        - `gcc main.c {nome}_TAD.o -o main` .
* Concluímos nessa etapa, que um usuário precisa somente do arquivo {nome}_TAD.h e {nome}_TAD.o para utilizar o TAD.

## Passo 4.3 - Automatizar a utilização do TAD

- Criar um arquivo makefile e adicionar nos campos:
    - all: comandos para compilar o {nome}_TAD.c, e gerar o "output" do main.c junto com o compilado {nome}_TAD.o ;
    - run: comando para executar o "output" ;
    - clean: comandos para excluir o arquivo compilado e o "output".
* Usar variáveis para tornar o arquivo makefile reutilizável.

## Passo 4.4 - Encapsular a struct

- Em {nome}_TAD.h deixaremos apenas: 
    - `typedef struct {nome} {Nome} ;`
- Desse modo, inserimos em {nome}_TAD.c :
    - `struct {nome} { tipo1 dado1; tipo2 dado2 ...};`
* Feito isso, o usuário não terá acesso aos elementos do TAD:
    - O comando `{nome}->` não apresenta as variáveis da struct.
* Também temos que, pelo main.c ter somente acesso ao {nome}_TAD.h "normalmente", qualquer função a mais que acrescentarmos em
{nome}_TAD.c não será acessível pelo usuário.
* Após esse passo, devemos substituir os testes no main.c, por uma simulação do uso da TAD. Isso porque, devido ao encapsulamento, não
teremos mais acesso às variáveis da struct, limitando os testes.

## Passo 4.5 - Incluir um "Guard" (guardião) em {nome}_TAD.h

- Quando incluímos {nome}_TAD.h no main.c, ocorre o ctrl+c ctrl+v do arquivo, incluindo algumas bibliotecas mais de uma vez. Isso
faz com que ocorra sobreposições que podem gerar problemas, quando em larga escala, sendo necessário o uso da estrutura de guardiões:
    - `#ifndef _{NOME}_TAD_H_`
    - `#define _{NOME}_TAD_H_` 
    - `// code` 
    - `#endif` 
* Assim, finalizamos a etapa de refatoração.


