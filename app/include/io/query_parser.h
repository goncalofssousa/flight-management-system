#ifndef QUERY_PARSER_H
#define QUERY_PARSER_H
#define _DEFAULT_SOURCE

#include <glib.h>


typedef struct query Query; 

/**
  @brief Cria e inicializa uma nova estrutura Query.
  @return Ponteiro para a nova estrutura Query alocada dinamicamente.
*/
Query *query_new(); 

/**
  @brief Liberta a memória associada a uma estrutura Query.
  @param q Ponteiro para a estrutura Query a libertar.
*/
void query_free(Query *q); 

/**
  @brief Retorna o código da query.
  @param q Ponteiro para a estrutura Query.

  @return Inteiro correspondente ao código da query.
*/
int getCommand(Query *q);

/**
  @brief Retorna o número de argumentos da query.
  @param q Ponteiro para a estrutura Query.

  @return Número de argumentos.
*/
int getNargs(Query *q);

/**
  @brief Retorna o argumento na posição especificada.
  @param q     Ponteiro para a estrutura Query.
  @param index Índice do argumento (0 a n_args-1).

  @return Ponteiro para a string do argumento, ou NULL se índice inválido.
*/
char *getArg(Query *q, int index);

//int getFlag(Query *q);

/**
  @brief Retorna o separador definido para a query.
  @param q Ponteiro para a estrutura Query.

  @return Carácter separador da query.
*/
char getSeparador(Query *q);

/**
  @brief Analisa uma linha de input e preenche a estrutura Query.

  Divide a linha em código da query e argumentos, define o separador
  e o número de argumentos.

  @param linha Ponteiro para a linha de texto a analisar.
  @param query Ponteiro para a estrutura Query a preencher.
*/
void parse_query_line(char *linha, Query *query); 

#endif