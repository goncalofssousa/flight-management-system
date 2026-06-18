#ifndef AIRCRAFT_LOADER_H
#define AIRCRAFT_LOADER_H
#include "entity/aircraft.h"
#include "managers/managerGlobal.h"
#include "verification.h"
#include "logicVerify.h"
#include <stdio.h>

/**
 * @brief Adiciona uma aeronave.
 *
 * Adiciona os dados da aeronave nos campos corretos.
 * Se os dados forem inválidos, escreve a linha original no ficheiro fornecido.
 *
 * @param camps        Matriz de strings contendo os campos da aeronave já separados/parsing feito.
 * @param file         Ficheiro onde será escrita a linha original caso os dados sejam inválidos.
 * @param original     String com a linha original do ficheiro de entrada.
 * @param global       Estrutura global de gestão onde a aeronave será adicionada.
 *
 * @return 0 se a aeronave foi adicionada com sucesso, valor > 0 caso contrário.
 */
int addAircraft(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global); 
#endif