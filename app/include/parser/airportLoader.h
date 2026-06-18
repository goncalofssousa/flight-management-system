#ifndef AIRPORT_LOADER_H
#define AIRPORT_LOADER_H
#include "entity/airport.h"
#include "managers/managerGlobal.h"
#include "verification.h"
#include "logicVerify.h"
#include <stdio.h>

/**
 * @brief Adiciona um aeroporto.
 *
 * Preenche os campos correspondentes com os dados do aeroporto.
 * Valida latitude, longitude, código do aeroporto e tipo.
 * Se algum dado for inválido, escreve a linha original no ficheiro fornecido.
 *
 * @param camps        Matriz de strings contendo os campos do aeroporto (código, nome, cidade,
 *                     país, latitude, longitude, altitude, tipo).
 * @param file         Ficheiro onde será escrita a linha original caso os dados sejam inválidos.
 * @param original     String com a linha original do ficheiro de entrada.
 * @param global       Estrutura global de gestão onde o aeroporto será inserido.
 *
 * @return 0 se a inserção foi bem-sucedida, valor > 0 caso contrário.
 */
int addAirport(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global); 
#endif