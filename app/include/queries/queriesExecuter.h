#ifndef QUERIESEXECUTER_H
#define QUERIESEXECUTER_H

#include "io/output.h"
#include "io/query_parser.h"
#include "managers/managerGlobal.h"
#include "query1.h"
#include "query2.h"
#include "query3.h"
#include "query4.h"
#include "query5.h"
#include "query6.h"

/**
 *@brief Executa uma query específica com base no comando fornecido.

 *@param query Ponteiro para a estrutura Query a ser executada.
 *@param manager Ponteiro para o gestor global (`ManagerGlobal`) que contém
                 aeroportos, aeronaves, voos, passageiros e reservas.

  @return void Não retorna valor.
*/
Output *execute_query(Query *query, ManagerGlobal *manager); 

#endif