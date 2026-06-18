#ifndef AIRPORTS_H
#define AIRPORTS_H

#include "aircraft.h"
#include "verification.h"
#include <glib.h>

typedef struct airport Airport;

/**
 * @brief Retorna uma cópia do código do aeroporto.
 * @param airport Ponteiro para a estrutura Airport.

 * @return String alocada dinamicamente com o código do aeroporto,
 *         ou NULL se o aeroporto for inválido.
 */
char *getCode(const Airport *airport);

/**
 * @brief Retorna uma cópia do nome do aeroporto.
 * @param airport Ponteiro para a estrutura Airport.

 * @return String alocada dinamicamente com o nome do aeroporto.
 */
char *getName(const Airport *airport);

/**
 * @brief Retorna uma cópia da cidade do aeroporto.
 * @param airport Ponteiro para a estrutura Airport.
 
 * @return String alocada dinamicamente com a cidade do aeroporto.
 */
char *getCity(const Airport *airport);

/**
 * @brief Retorna uma cópia do país do aeroporto.
 * @param airport Ponteiro para a estrutura Airport.

 * @return String alocada dinamicamente com o país do aeroporto.
 */
char *getCountry(const Airport *airport);

/**
 * @brief Retorna o id do aeroporto.
 * @param airport Ponteiro para a estrutura Airport.

 * @return id interno do aeroporto.
 */

/**
 * @brief Retorna o tipo do aeroporto em formato string.
 * @param airport Ponteiro para a estrutura Airport.

 * @return String alocada dinamicamente com o tipo do aeroporto.
 */
char *getType(const Airport *airport);

/**
 * @brief Retorna o número de passageiros que chegaram ao aeroporto.
 * @param airport Ponteiro para a estrutura Airport.

 * @return Número de passageiros em chegadas.
 */
int getArrivalCount(const Airport *airport);

/**
 * @brief Retorna o número de passageiros que partiram do aeroporto.
 * @param airport Ponteiro para a estrutura Airport.

 * @return Número de passageiros em partidas.
 */
int getDepartureCount(const Airport *airport);

void setType(Airport *airport, char *type);

void incFlightDateCount(Airport *a, int date); 
/**
 * @brief Incrementa o número de passageiros em partidas.
 * @param a Ponteiro para a estrutura Airport.
 */
void incPassengerDeparture(Airport *a);

/**
 * @brief Incrementa o número de passageiros em chegadas.
 * @param a Ponteiro para a estrutura Airport.
 */
void incPassengerArrival(Airport *a);

/**
 * @brief Cria e inicializa um novo aeroporto.

 * @param code    Código do aeroporto.
 * @param name    Nome do aeroporto.
 * @param city    Cidade do aeroporto.
 * @param country País do aeroporto.
 * @param type    Tipo do aeroporto.
 * @param id      id.

 * @return Ponteiro para o aeroporto criado.
 */
Airport *allocateAirport(char *code, char *name, char *city, char *country, char *type); 

void hashTableToSortArrayAirports(Airport *a); 
int getCountFromDateInterval(int date1, int date2, Airport *a); 

/**
 * @brief Liberta a memória associada a um aeroporto.

 * @param a Ponteiro para a estrutura Airport a libertar.
 */
void freeAirport(Airport *a);
#endif