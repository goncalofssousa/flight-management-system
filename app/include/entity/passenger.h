#ifndef PASSENGERS_H
#define PASSENGERS_H

#include "verification.h"
#include <glib.h>

typedef struct passenger Passenger;

/**
  @brief Retorna o primeiro nome do passageiro.
  @param p Ponteiro para a estrutura Passenger.
  
  @return String alocada dinamicamente com o primeiro nome do passageiro.
*/
char *getPassengerFirstName(const Passenger *p);

/**
  @brief Retorna o último nome do passageiro.
  @param p Ponteiro para a estrutura Passenger.

  @return String alocada dinamicamente com o último nome do passageiro.
*/
char *getPassengerLastName(const Passenger *p);

/**
  @brief Retorna a data de nascimento do passageiro.

  @param p Ponteiro para a estrutura Passenger.

  @return String alocada dinamicamente com a data de nascimento do passageiro.
*/
char *getPassengerDOB(const Passenger *p);

/**
 * @brief Obtém a nacionalidade de um passageiro.
 * @param p Ponteiro para a estrutura Passenger.
 *
 * @return String com a nacionalidade do passageiro.
 */
char *getPassengerNacionality(const Passenger *p);

/**
  @brief Cria e inicializa um passageiro.

  @param documentNumber Número de documento.
  @param firstName      Primeiro nome.
  @param lastName       Último nome.
  @param dob            Data de nascimento.
  @param nacionality    Nacionalidade.

  @return Ponteiro para o passageiro criado.
*/
Passenger *allocatePassenger(char *documentNumber, char *firstName,
                             char *lastName, char *dob, char *nacionality);

/**
  @brief Liberta a memória associada a um passageiro.
  @param p Ponteiro para a estrutura Passenger a libertar.
*/
void freePassenger(Passenger *p);
#endif