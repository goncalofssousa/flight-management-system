#ifndef QUERIE2_H
#define QUERIE2_H

#include "managers/managerGlobal.h"
#include "io/output.h"

/**
 * @brief Query 2.
 *
 * @param numAircrafts Número máximo de aeronaves a listar.
 * @param manufacturer Fabricante das aeronaves, ou NULL para todas.
 * @param manager Ponteiro para o ManagerGlobal.
 *
 * @return Estrutura Output com a lista de aeronaves com mais voos realizados.
 */
Output* query2(int numAircrafts, const char *manufacturer, ManagerGlobal *manager);

#endif