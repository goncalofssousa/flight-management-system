#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "managers/managerGlobal.h"
#include "output.h"
#include "query_parser.h"
#include "queries/queriesExecuter.h"

/**
 * @brief Interpreta e executa uma linha de query sobre o manager.
 *
 * @param line Linha de query a ser interpretada.
 * @param man Ponteiro para o ManagerGlobal onde a query será aplicada.
 * @param from_file 1 se a query veio de um ficheiro, 0 caso contrário.
 * @return 0 se a query foi processada com sucesso, 1 em caso de erro.
 */
int interpret_query(char *line,ManagerGlobal *man,int from_file); 

#endif
