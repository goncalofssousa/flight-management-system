
#ifndef FLIGHTS_H
#define FLIGHTS_H

#include "managers/managerAircrafts.h"
#include "utils/geral.h"
#include "verification.h"
#include <glib.h>

typedef struct flight Flight;
typedef enum state State;


/**
  @brief Define o estado do voo ("On Time", "Delayed", "Cancelled").
  @param flight Ponteiro para a estrutura Flight.
  @param state  Estado do voo em formato string.

  @return 0 se o estado for válido,
          -1 se o voo estiver cancelado,
          1 se o estado for inválido.
*/
void setState(Flight *flight, char *state);


// int addAircraftToFlight(Flight *flight, char *code);
// int addAirline(Flight *flight, char *airline);
// int addTracking(Flight *flight, char *tracking);

/**
  @brief Retorna uma cópia do aeroporto de destino.
  @param flight Ponteiro para a estrutura Flight.

  @return String alocada dinamicamente com o aeroporto de destino.
*/
char *getDestination(const Flight *flight);
/**
  @brief Retorna uma cópia do aeroporto de origem.
  @param flight Ponteiro para a estrutura Flight.

  @return String alocada dinamicamente com o aeroporto de origem.
*/
char *getOrigin(const Flight *flight);
/**
  @brief Retorna uma cópia da data/hora de partida prevista.
  @param flight Ponteiro para a estrutura Flight.

  @return String alocada dinamicamente com a data/hora de partida prevista.
*/
char *getDeparture(const Flight *flight);
/**
  @brief Retorna uma cópia da data/hora de chegada prevista.
  @param flight Ponteiro para a estrutura Flight.

  @return String alocada dinamicamente com a data/hora de chegada prevista.
*/
char *getArrival(Flight *flight);
/**
  @brief Retorna uma cópia da data/hora de partida atual.
  @param flight Ponteiro para a estrutura Flight.

  @return String alocada dinamicamente com a data/hora de partida atual.
*/
char *getAcDeparture(Flight *flight);
/**
  @brief Retorna uma cópia da data/hora de chegada atual.
  @param flight Ponteiro para a estrutura Flight.

  @return String alocada dinamicamente com a data/hora de chegada atual.
*/
char *getAcArrival(Flight *flight);
int getFlightState(const Flight *flight);
char *getFlightAircraftId(Flight *flight);
/**
  @brief Retorna o aeroporto de destino de um voo.
  @param f Ponteiro para a estrutura Flight.

  @return Ponteiro para a string do aeroporto de destino,
          ou NULL se o voo for inválido.
*/
char* getFlightDestination(Flight *f);
/**
  @brief Cria e inicializa um novo voo.

  @param code   Identificador do voo.
  @param status Estado do voo.
  @param origin Código do aeroporto de origem.
  @param departure Data de partida.
  @param dest   Código do aeroporto de destino.

  @return Ponteiro para o voo criado.
*/
Flight *allocateFlight(char *code, char *departure, char *status,char *origin, char *dest); 
/**
  @brief Liberta a memória associada a um voo.
  @param f Ponteiro para a estrutura Flight a libertar.
*/
void freeFlight(Flight *f);
#endif
