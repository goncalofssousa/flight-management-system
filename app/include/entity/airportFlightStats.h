#ifndef AIRPORTS_FLIGHT_STATS_H
#define AIRPORTS_FLIGHT_STATS_H

#include "aircraft.h"
#include "verification.h"
#include <glib.h>

typedef struct info AirportInfo; 

/**
 * @brief Cria e inicializa a estrutura AirportInfo.
 * @param numFlights Número de voos.
 * @param code Código do aeroporto.
 * @return Ponteiro para a estrutura AirportInfo criada.
 */
AirportInfo *createAirportInfo(int numFlights, const char *code);

char *getCodeFromAirportInfo(AirportInfo *airportInfo); 

/**
 * @brief Retorna o número de voos de um aeroporto.
 * @param airportInfo Ponteiro para a estrutura AirportInfo.
 * @return Número de voos.
 */
int getNumFlightFromAirportInfo(AirportInfo *airportInfo) ; 

/**
 * @brief Liberta a memória ocupada por uma estrutura AirportInfo.
 * @param info Ponteiro para a estrutura AirportInfo a ser libertada.
 */
void freeAirportInfo(AirportInfo *info); 
#endif