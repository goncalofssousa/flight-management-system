#ifndef QUERIE5_H
#define QUERIE5_H

#include "io/output.h"
#include "managers/managerGlobal.h"
#include <glib.h>

/**
 * @brief Query 5.
 *
 * @param N Número máximo de companhias aéreas a listar.
 * @param global Ponteiro para o ManagerGlobal.
 *
 * @return Estrutura Output com as companhias aéreas com maior atraso médio.
 */
Output *query5(int N, ManagerGlobal *global);

#endif
