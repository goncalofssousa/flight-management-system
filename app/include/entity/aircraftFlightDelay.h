#ifndef AIRCRAFT_FLIGHT_DELAY_H
#define AIRCRAFT_FLIGHT_DELAY_H
#include "managers/managerFlights.h"
typedef struct flighDelay FlightDelay; 

FlightDelay *createFlightDelay(int delay, int flights); 

/**
 * @brief Retorna o atraso médio de uma companhia aérea.
 *
 * @param delay Ponteiro para a estrutura FlighDelay.
 * @return Atraso médio da companhia aérea.
 */
double getAirlineAvgDelay(FlighDelay *delay);

/**
 * @brief Retorna o número de voos contabilizados para uma companhia aérea.
 *
 * @param delay Ponteiro para a estrutura FlighDelay.
 * @return Número de voos.
 */
int getAirlineFlightCount(FlighDelay *delay);

/**
 * @brief Adiciona um atraso ao total de atrasos.
 *
 * @param currentDelay Ponteiro para a estrutura FlightDelay.
 * @param delay Valor do atraso a adicionar.
 */
void addFlightDelay(FlightDelay *currentDelay, double delay); 

/**
 * @brief Incrementa o contador de voos associados a um atraso.
 *
 * @param currentDelay Ponteiro para a estrutura FlightDelay.
 */
void incFlightCountToDelay(FlightDelay *currentDelay); 

/**
 * @brief Calcula e define o atraso médio a partir do total de atrasos.
 *
 * @param value Ponteiro para a estrutura FlightDelay.
 */
void addAvgDelay(FlightDelay *value); 

/**
 * @brief Retorna o atraso médio armazenado.
 *
 * @param value Ponteiro para a estrutura FlighDelay.
 *
 * @return Valor do atraso médio.
 */
int getAvgDelay(FlighDelay *value); 
#endif