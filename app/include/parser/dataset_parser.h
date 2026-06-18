#ifndef DATASET_PARSER_H
#define DATASET_PARSER_H

#include "parser/aircraftLoader.h"
#include "parser/airportLoader.h"
#include "parser/flightLoader.h"
#include "parser/passengerLoader.h"
#include "parser/reservationLoader.h"
#include "managers/managerGlobal.h"
#include "utils/geral.h"
#include <glib.h>
#include <stdio.h>

/**
 * @brief Lê todos os ficheiros do dataset e popula o gestor global.
 *
 * Processa os ficheiros airports.csv, aircrafts.csv, flights.csv,
 * passengers.csv e reservations.csv presentes no diretório indicado,
 * criando e inserindo os respetivos objetos nas estruturas de dados globais.
 * As linhas inválidas são escritas nos ficheiros de erro correspondentes.
 *
 * @param path    Caminho para o diretório que contém os ficheiros do dataset.
 * @param global  Estrutura global de gestão onde todos os dados serão armazenados.
 *
 * @return 0 se todos os ficheiros foram processados com sucesso,
 *         valor > 0 se ocorreu algum erro ao abrir ou processar os ficheiros.
 */
int readDatasetPath(char *path,  ManagerGlobal *global);

/**
 * @brief Lê um ficheiro linha a linha e processa cada linha.
 *
 * Cada linha é dividida em colunas e passada para a função de processamento
 * fornecida.
 *
 * @param path         Caminho para o ficheiro a ser lido.
 * @param processLine  Ponteiro para a função responsável por processar cada linha.
 *                     A função recebe as colunas já separadas, o ficheiro de erros,
 *                     a linha original e a estrutura global de gestão.
 * @param errorFile    Ficheiro onde serão escritas as linhas inválidas.
 * @param global       Estrutura global de gestão passada para a função de processamento.
 *
 * @return 0 se o ficheiro foi lido com sucesso, 1 se o caminho ou a função forem inválidos.
 */
int readFile(char *path, int (*processLine)(char[][MAX_STRING], FILE *, char *,ManagerGlobal *global), FILE *errorFile,ManagerGlobal *global);

/**
  @brief Fecha um ficheiro.
  @param f Ponteiro para o ficheiro a fechar.
  @return 0 em caso de sucesso, 1 se o ficheiro for NULL.
*/
int closeFile(FILE *f);

#endif