#ifndef DATASET_READER_H
#define DATASET_READER_H

#include <stdio.h>
#include <string.h>
#include "managers/managerGlobal.h"
#include "parser/dataset_parser.h"
#include "io/output.h"

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
int readDatasetPath(char *path, ManagerGlobal *global); 

#endif