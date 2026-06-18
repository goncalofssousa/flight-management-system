#ifndef QUERIE1_H
#define QUERIE1_H

#include "managers/managerGlobal.h"
#include "io/output.h"

/**
 * @brief Query 1.
 *
 * @param code Código do aeroporto.
 * @param manager Ponteiro para o ManagerGlobal.
 *
 * @return Estrutura Output com a informação do aeroporto, ou vazia se não existir.
 */
Output* query1(char *code, ManagerGlobal *manager);

#endif