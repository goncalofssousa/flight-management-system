#ifndef LOGICVERIFY_H
#define LOGICVERIFY_H

#include "managers/managerGlobal.h"

int verifyAircraft(char *id);

/**
 * @brief Verifica se o estado de um voo é consistente com as datas fornecidas.
 *
 * @param state Estado do voo: "On Time", "Delayed" ou "Cancelled".
 * @param date1 Data planeada de partida.
 * @param date2 Data real de partida.
 * @param date3 Data planeada de chegada.
 * @param date4 Data real de chegada.
 * @return 0 se as datas forem consistentes com o estado; 1 caso contrário.
 *
 */
int verifyStateDate(char *state, char *date1, char *date2,char *date3, char *date4); 

/**
 * @brief Converte uma string representando uma lista de IDs em um array de strings.
 *
 * @param str String com o formato esperado.
 * @param ids Array de ponteiros para armazenar os IDs extraídos.
 * @return Número de IDs encontrados (máx. 2) ou -1 em caso de erro.
 */
int verifyList(char *str, char *ids[2]);

/**
 * @brief Verifica a validade de um ou dois voos dados os seus IDs.
 *
 * @param ids Array de IDs dos voos (máx. 2).
 * @param flag Indica se deve verificar o segundo voo (1 se sim, 0 se não).
 * @param manager Ponteiro para o ManagerGlobal.
 * @return 0 se válido, 1 caso contrário.
 */
int verifyFlights(char *ids[2], int flag, ManagerGlobal *manager); 

/**
 * @brief Verifica se uma aeronave existe no sistema.
 *
 * @param aircrafts Ponteiro para o ManagerAircrafts.
 * @param code Código da aeronave.
 * @return 0 se existir, 1 caso contrário.
 */
int verifyAircraftExists(ManagerAircrafts *aircrafts, char *code); 

/**
 * @brief Verifica se uma reserva corresponde a voos existentes.
 *
 * @param manFlights Ponteiro para o manager de voos.
 * @param ids String com IDs dos voos na reserva.
 * @return Número de voos na reserva se válido, -1 caso contrário.
 */
int verifyReservationFlights(ManagerFlights *manFlights, char *ids); 

/**
 * @brief Verifica se um número de documento de passageiro existe e é válido.
 *
 * @param passengers Ponteiro para o manager de passageiros.
 * @param docNumber Número de documento.
 * @return 0 se válido e existente, 1 caso contrário.
 */
int verifyReservationDocNumber(ManagerPassengers *passengers, char *docNumber);
#endif