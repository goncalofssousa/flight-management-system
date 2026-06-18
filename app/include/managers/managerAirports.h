#ifndef AIRPORTS_MAN_H
#define AIRPORTS_MAN_H

#include "entity/airport.h"
#include "entity/airportFlightStats.h"
#include <glib.h>

typedef struct range RangeArgs; 
typedef struct manager ManagerAirports; 

/**
 * @brief Inicializa o gestor de aeroportos.
 * @return Ponteiro para o manager de aeroportos inicializado.
 */
ManagerAirports *initAirports();


/**
 * @brief Adiciona um voo à árvore de voos por data.
 *
 * @param date Data do voo (YYYY-MM-DD).
 * @param origin Código do aeroporto de origem.
 * @param airportsManager Ponteiro para o manager de aeroportos.
 */
void insertInAirporDateHash(int date, char *origin, ManagerAirports *airportsManager); 

void sortAllHashTables(ManagerAirports *manager); 
AirportInfo *getMaxFromDateInterval(ManagerAirports *manager, int dateIn, int dateFin); 

/**
 * @brief Incrementa o número de passageiros que partiram de um aeroporto.
 *
 * @param manAirports Ponteiro para o manager de aeroportos.
 * @param codeAirportOrigin Código do aeroporto de origem.
 */
void incPassengerDepartureAirport(ManagerAirports *manAirports,char *codeAirportOrigin);

/**
 * @brief Incrementa o número de passageiros que chegaram a um aeroporto.
 *
 * @param manAirports Ponteiro para o manager de aeroportos.
 * @param codeAirportDestination Código do aeroporto de destino.
 */
void incPassengerArrivalAirport(ManagerAirports *manAirports,char *codeAirportDestination);

/**
 * @brief Adiciona um aeroporto ao gestor.
 * @param manager Ponteiro para o manager de aeroportos.
 * @param airport Ponteiro para o aeroporto a adicionar.
 * @param code Código do aeroporto.
 */
void insertAirport(ManagerAirports *manager, Airport *airport,char *code); 

/**
 * @brief Obtém um aeroporto pelo id.
 *
 * @param manager Ponteiro para o manager de aeroportos.
 * @param id Código do aeroporto.
 * @return Ponteiro para o aeroporto, ou NULL se não existir.
 */
const Airport *getAirportById(ManagerAirports *manager, char *id); 

/**
 * @brief Liberta toda a memória associada aos aeroportos e à árvore de datas dos voos.
 *
 * @param airports Ponteiro para o manager de aeroportos.
 */
void freeAllAirports(ManagerAirports *airports); 



#endif