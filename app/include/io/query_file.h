#ifndef QUERY_FILE_H
#define QUERY_FILE_H
#include "interpreter.h"

/**
  @brief Lê um ficheiro de queries e executa cada linha.

  Lê o ficheiro especificado linha a linha. Cada linha não vazia
  é interpretada como uma query, analisada e executada com o gestor
  global fornecido.

  @param path    Caminho para o ficheiro de input das queries.
  @param manager Ponteiro para a estrutura ManagerGlobal que irá processar as queries.

  @return 0 se o ficheiro foi lido e processado com sucesso.
          1 se o caminho for inválido ou o ficheiro não puder ser aberto.
*/
int readQueryFileInput(char *path, ManagerGlobal *manager); 

#endif