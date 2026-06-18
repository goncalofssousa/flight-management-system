#ifndef OUTPUT_H
#define OUTPUT_H
#include <stdio.h>
#include <glib.h>


typedef struct output Output; 

/**
  @brief Fecha um ficheiro.
  @param f Ponteiro para o ficheiro a fechar.

  @return 0 em caso de sucesso, 1 se o ficheiro for NULL.
*/
int closeFile(FILE *f); 

/**
  @brief Cria o ficheiro dos resultados dos datasets com erros.
  @param header Cabeçalho ou nome do dataset para criar o ficheiro.
  
  @return Ponteiro para o ficheiro criado.
*/
FILE *createErrorFile(char *header); 

/**
  @brief Cria um ficheiro de output com base no contador global NFiles.
  @return Ponteiro para o ficheiro criado.
          NULL se ocorrer algum erro ao abrir o ficheiro.
*/
FILE *createOutputFile(); 

/**
  @brief Cria um ficheiro de output para uma query específica.
  @return Ponteiro para a estrutura Output inicializada.
*/
Output *createOutput(); 

/**
  @brief Adiciona um token do tipo string a uma estrutura Output.

  @param out   Ponteiro para a estrutura Output.
  @param token Token em formato string a adicionar.
*/
void addToken(Output *out, char *token); 

/**
  @brief Adiciona um token do tipo inteiro a uma estrutura Output.

  @param out   Ponteiro para a estrutura Output.
  @param value Valor inteiro a adicionar como token.
*/
void addIntToken(Output *out, int value); 

/**
  @brief Escreve os tokens armazenados num ficheiro de output.

  @param out       Ponteiro para a estrutura Output.
  @param flag      Indica o destino do output.
  @param separador Carácter separador entre tokens.
*/
void writeOutput(Output *out, char separador, int flag); 

/**
  @brief Liberta a memória associada a uma estrutura Output.

  @param out Ponteiro para a estrutura Output a libertar.
*/
void freeOutput(Output *out); 
#endif