#ifndef QUERIE6_H
#define QUERIE6_H

#include "managers/managerGlobal.h"
#include "io/output.h"

/**
 * @brief Query 6.
 *
 * @param nacionality Nacionalidade a considerar.
 * @param manager Ponteiro para o ManagerGlobal.
 *
 * @return Estrutura Output com o aeroporto de destino mais comum
 * para passageiros de uma determinada nacionalidade. 
 */
Output *query6(char *nacionality, ManagerGlobal *manager);

#endif
