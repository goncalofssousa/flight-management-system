#ifndef VERIFICATION_H
#define VERIFICATION_H

#include "regex.h"
#include <ctype.h>

/**
 * @brief Verifica se uma string representa uma data/hora válida no formato YYYY-MM-DD hh:mm.
 *
 * @param date String com a data/hora a verificar.
 * @return 0 se válida, 1 se inválida.
 */
int verifyDate(char *date);


/**
 * @brief Verifica se uma string representa uma data de nascimento válida (YYYY-MM-DD).
 *
 * @param date String com a data de nascimento.
 * @return 0 se válida, 1 se inválida.
 */
int verifyDOB(char *date);

/**
 * @brief Verifica se uma string representa uma latitude válida (-90.0 a 90.0).
 *
 * @param coord String com a latitude.
 * @return 0 se válida, 1 se inválida.
 */
int verifyLatitude(char *coord); 

/**
 * @brief Verifica se uma string representa uma longitude válida (-180.0 a 180.0).
 *
 * @param coord String com a longitude.
 * @return 0 se válida, 1 se inválida.
 */
int verifyLongitude(char *coord); 

/**
 * @brief Verifica se um código de aeroporto é válido (3 letras maiúsculas).
 *
 * @param code Código do aeroporto.
 * @return 0 se válido, 1 se inválido.
 */
int verifyAirport(char *code);

/**
 * @brief Verifica se um código de voo é válido (ex.: AA1234 ou AA123456).
 *
 * @param code Código do voo.
 * @return 0 se válido, 1 se inválido.
 */
int verifyFlightId(char *code);

/**
 * @brief Verifica se uma reserva é válida (R + 9 dígitos).
 *
 * @param reservation Código da reserva.
 * @return 0 se válido, 1 se inválido.
 */
int verifyReservation(char *reservation);

/**
  @brief Verifica se um email é válido usando expressão regular.

  @param email Ponteiro para a string do email a verificar.
  @return 0 se o email for válido, valor diferente de 0 caso contrário.
*/
int verifyEmail(char *email);

/**
  @brief Verifica se o número de documento é válido.

  @param document Ponteiro para a string do documento a verificar.
  @return 0 se o documento for válido, 1 caso contrário.
*/
int verifyDocument(char *document);

/**
 * @brief Verifica se origem e destino de voo são válidos e diferentes.
 *
 * @param origin Código de aeroporto de origem.
 * @param dest Código de aeroporto de destino.
 * @return 0 se válidos, 1 se inválidos ou iguais.
 */
int verifyOriginDest(char *origin, char *dest);

//int verifySeat(char *seat);

/**
 * @brief Verifica se o ano é válido e não é futuro.
 *
 * @param year String com o ano (YYYY).
 * @return 0 se válido, 1 se inválido.
 */
int verifyYear(char *year);

/**
 * @brief Verifica se o tipo de aeroporto é válido.
 *
 * @param type String com o tipo (small_airport, medium_airport, large_airport, heliport, seaplane_base).
 * @return 0 se válido, 1 se inválido.
 */
int verifyType(char *type); 

/**
 * @brief Verifica se o estado de voo é válido (On Time, Delayed, Cancelled).
 *
 * @param state String com o estado do voo.
 * @return 0 se On Time, 0 se Delayed, -1 se Cancelled, 1 se inválido.
 */
int verifyStateFlight(char *state);

/**
 * @brief Verifica a ordem cronológica entre duas datas.
 *
 * @param date1 Primeira data.
 * @param date2 Segunda data.
 * @return 0 se date1 <= date2, 1 caso contrário.
 */
int verifyAcs(char *date1, char *date2); 

/**
 * @brief Verifica consistência de datas de partida e chegada, incluindo actual (ac) datas.
 *
 * @param departure Data de partida.
 * @param arrival Data de chegada.
 * @param acDeparture Data de partida real.
 * @param acArrival Data de chegada real.
 * @return 0 se todas válidas e consistentes, 1 caso contrário.
 */
int verifyDates(char *departure, char *arrival, char *acDeparture, char *acArrival); 

/**
 * @brief Verifica se o género é válido.
 *
 * @param gender String com o género.
 * @return 0 se válido, 1 se inválido.
 */
int verifyGender(char *gender); 

/**
  @brief Verifica se o comando da query é válido.
  @param query Ponteiro para a string da query a verificar.

  @return 0 se a query for válida, 1 caso contrário.
*/
int verifyQueryCommand(char *query); 

#endif