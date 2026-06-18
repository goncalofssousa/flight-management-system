#ifndef FLIGHTS_MAN_H
#define FLIGHTS_MAN_H

#include "entity/flight.h"
#include "glib.h"

typedef struct manager ManagerFlights;
typedef struct flighDelay FlighDelay;

/**
 * @brief Inicializa o manager dos voos.
 * @return Ponteiro para ManagerFlights inicializado.
 */
ManagerFlights *initFlights();

/**
 * @brief Atualiza ou insere o atraso de uma companhia aérea.
 *
 * Calcula o atraso entre a hora prevista e real, acumula total e incrementa o número de voos.
 *
 * @param manFlights Ponteiro para o manager de voos.
 * @param airlineCode Código da companhia aérea.
 * @param predicted Hora prevista do voo (formato "YYYY-MM-DD hh:mm").
 * @param real Hora real do voo (formato "YYYY-MM-DD hh:mm").
 */
void insertAirlineDelay(ManagerFlights *manFlights, char *airlineCode,
                        char *predicted, char *real);

/**
 * @brief Insere um voo na hash table de voos.
 *
 * @param manFlights Ponteiro para o manager de voos.
 * @param flight Ponteiro para o voo a inserir.
 * @param code Código do voo (chave da hash table).
 */                        
void insertFlight(ManagerFlights *manFlights, Flight *flight, char *code);

/**
 * @brief Obtém o atraso de uma companhia aérea pelo código.
 *
 * @param manFlights Ponteiro para o manager de voos.
 * @param airlineCode Código da companhia aérea.
 * @return Ponteiro para a estrutura FlighDelay da companhia, ou NULL se não existir.
 */
FlighDelay *getAirlineDelay(ManagerFlights *manFlights, char *airlineCode);



/**
 * @brief Retorna o código da companhia aérea pelo índice no array ordenado.
 *
 * @param manFlights Ponteiro para o manager de voos.
 * @param index Índice do array `sortedDelays`.
 * @return Código da companhia aérea, ou NULL se índice inválido.
 */
char *getAirlineByIndex(ManagerFlights *manFlights, int index);

/**
 * @brief Ordena o array de companhias aéreas pelo atraso médio.
 * @param manFlights Ponteiro para o manager de voos.
 */
void sortAirlineDelays(ManagerFlights *manFlights);

/**
 * @brief Função de comparação para ordenar as companhias aéreas pelo atraso médio.
 *
 * @param a Ponteiro para o primeiro elemento (char **).
 * @param b Ponteiro para o segundo elemento (char **).
 * @param ht Ponteiro para a hash table de atrasos (gpointer).
 * @return Valor negativo se a < b, positivo se a > b, 0 se iguais.
 */
int compareAirlineDelays(const void *a, const void *b, gpointer ht);

/**
 * @brief Obtém um voo pelo ID.
 *
 * @param manFlights Ponteiro para o manager de voos.
 * @param id Código do voo.
 * @return Ponteiro para o voo, ou NULL se não existir.
 */
const Flight *getFlightById(ManagerFlights *manFlights, char *id);

/**
 * @brief Liberta toda a memória associada ao manager de voos.
 *
 * Destrói as hash tables e libera a memória do manager.
 *
 * @param manFlights Ponteiro para o manager de voos.
 */
void freeAllFlights(ManagerFlights *manFlights);
#endif