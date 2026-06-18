#ifndef RESERVATIONS_E_H
#define RESERVATIONS_E_H

#include <glib.h>
#include <stdbool.h>

typedef struct reservation Reservation;

/**
  @brief Retorna o número de documento associado à reserva.

  @param r Ponteiro para a estrutura Reservation.

  @return Ponteiro para a string com o número de documento,
          ou NULL se inválido.
*/
char *getReservationDocNumber(Reservation *r);

/**
  @brief Retorna o aeroporto de origem da reserva.

  @param r Ponteiro para a estrutura Reservation.

  @return String alocada dinamicamente com o aeroporto de origem.
*/
char *getReservationOrigin(Reservation *r);

/**
  @brief Retorna o aeroporto de destino da reserva.

  @param r Ponteiro para a estrutura Reservation.

  @return String alocada dinamicamente com o aeroporto de destino,
          ou NULL se não existir.
*/
char *getReservationDestiny(Reservation *r);

//Reservation *getReservation(int i);

/**
  @brief Define o id da reserva.

  @param reservations Ponteiro para a estrutura Reservation.
  @param reservation_id id da reserva.

  @return 0 em caso de sucesso.
*/
int setId(Reservation *reservations, char *reservation_id);

/**
  @brief Define o número de documento associado à reserva.

  @param reservations Ponteiro para a estrutura Reservation.
  @param docNumber Número de documento do passageiro.

  @return 0 em caso de sucesso.
*/
int setDocNumber(Reservation *reservations, char *docNumber);

/**
  @brief Define o preço da reserva.

  @param reservations Ponteiro para a estrutura Reservation.
  @param price Preço da reserva.

  @return 0 em caso de sucesso.
*/
int setPrice(Reservation *reservations, double price);


/**
  @brief Cria e inicializa uma reserva.

  @param id         ID da reserva.
  @param origin     Código do aeroporto de origem.
  @param destiny    Código do aeroporto de destino.
  @param docNumber  Número de documento do passageiro.
  @param priceS     Preço da reserva como string.

  @return Ponteiro para a reserva criada.
*/
Reservation *allocateReservations(char *id, char *origin, char *destiny,
                                  char *docNumber, char *priceS);

/**
  @brief Liberta a memória associada a uma reserva.

  @param r Ponteiro para a estrutura Reservation a libertar.
*/
void freeReservation(Reservation *r);
#endif