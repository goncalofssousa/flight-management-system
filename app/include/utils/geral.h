#ifndef GERAL_H
#define GERAL_H

#include <glib.h>
#include <stdio.h>
#include <time.h>

#define MAX_STRING 200

/**
 * @brief Divide uma linha CSV em colunas.
 * @param line Linha CSV de entrada.
 * @param columns Matriz onde cada coluna será armazenada.
 * @param N Ponteiro para o número de colunas encontradas.
 */
void splitString(char *line, char columns[][MAX_STRING], int *N);

/**
  @brief Mostra uma mensagem no console e espera que o utilizador pressione
  Enter.
  @param message Ponteiro para a string de mensagem a exibir.
*/
void consoleMessage(char *message);

/**
  @brief Calcula a data do domingo anterior ou igual à data fornecida.
  @param date Data no formato YYYY-MM-DD.

  @return Data do domingo no formato YYYYMMDD.
*/
int getSundayDate(char *date);
int getIntDate(char *date); 
int getSundayDateInt(int dateInt); 

/**
  @brief Converte todas as chaves de uma hash table para um array.

  @param table Ponteiro para a GHashTable.
  @param arr   Ponteiro para o GArray onde as chaves serão armazenadas.
*/
void hashTableToSorterArray(GHashTable *table, GArray *arr);

/**
  @brief Calcula o atraso em minutos entre a hora prevista e a hora real.

  @param predicted Data e hora prevista no formato "YYYY-MM-DD hh:mm".
  @param real      Data e hora real no formato "YYYY-MM-DD hh:mm".

  @return Atraso em minutos.
*/
double calculateDelay(char *predicted, char *real);
#endif
