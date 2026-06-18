#ifndef QUERY_INTERACTIVE_H
#define QUERY_INTERACTIVE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "managers/managerGlobal.h"
#include "queries/queriesExecuter.h"
#include "utils/geral.h"
#include "parser/dataset_reader.h"
#include "io/query_parser.h"
#include "utils/verification.h"
#include "io/interpreter.h"
#define MAX_QUERY 256

/**
  @brief Lê interativamente o caminho do dataset e carrega os ficheiros.

  A função solicita ao utilizador o caminho para os ficheiros do dataset.
  Se o utilizador não introduzir nenhum caminho, utiliza "./dataset" por defeito.
  Tenta carregar o dataset com a função readDatasetPath até ser bem-sucedido.
  Exibe mensagens de erro se o caminho for inválido.

  @param man Ponteiro para a estrutura ManagerGlobal onde os dados serão carregados.

  @return 0 se o dataset for carregado com sucesso.
*/
int readDatasetPathIO(ManagerGlobal *man);

/**
  @brief Executa queries de forma interativa no gestor global.

  Permite ao utilizador introduzir queries manualmente pelo terminal.
  Valida os argumentos necessários para cada tipo de query e executa
  as queries através da função interpret_query. Aceita códigos de query
  de '1' a '6' e 'q' para sair do modo interativo.

  @param man Ponteiro para a estrutura ManagerGlobal onde as queries serão executadas.
*/
void readQueryInteractive(ManagerGlobal *man); 

#endif