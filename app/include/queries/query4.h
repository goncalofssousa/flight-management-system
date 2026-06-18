#ifndef QUERIE4_H
#define QUERIE4_H

#include "io/output.h"
#include "managers/managerGlobal.h"
#include <glib.h>

/**
 * @brief Query 4 (output auxiliar).
 *
 * @param id Identificador do passageiro.
 * @param manPassengers Ponteiro para o ManagerPassengers.
 * @param count Número de ocorrências associadas ao passageiro.
 *
 * @return Estrutura Output com a informação do passageiro.
 */
Output *query4Output(char *id, ManagerPassengers *manPassengers, int count);

/**
 * @brief Query 4.
 *
 * @param start Data inicial do intervalo, ou NULL para considerar todo o período.
 * @param end Data final do intervalo.
 * @param manager Ponteiro para o ManagerGlobal.
 *
 * @return Estrutura Output com o passageiro que esteve mais tempo no top 10
 *         de passageiros que mais gastaram em viagens durante um período.
 */
Output *query4(char *start, char *end, ManagerGlobal *manager);

#endif
