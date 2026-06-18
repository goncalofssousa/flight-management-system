#ifndef QUERIE3_H
#define QUERIE3_H

#include "managers/managerGlobal.h"
#include "io/output.h"

/**
 * @brief Query 3.
 *
 * @param dateIn Data inicial do intervalo.
 * @param dateFin Data final do intervalo.
 * @param manager Ponteiro para o ManagerGlobal.
 *
 * @return Estrutura Output com o aeroporto com mais partidas no intervalo.
 */
Output* query3(char *dateIn, char *dateFin, ManagerGlobal *manager);

#endif