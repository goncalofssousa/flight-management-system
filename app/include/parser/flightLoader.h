#ifndef FLIGHT_LOADER_H
#define FLIGHT_LOADER_H
#include "entity/flight.h"
#include "managers/managerGlobal.h"
#include "verification.h"
#include "logicVerify.h"
#include <stdio.h>

/**
 * @brief Adiciona um voo.
 *
 * Preenche os campos correspondentes com os dados do voo.
 * Valida o ID do voo, datas, estado, aeroportos de origem e destino
 * e a existência da aeronave associada.
 * Em caso de sucesso, insere o voo, associa-o à aeronave e atualiza
 * a estrutura de aeroportos.
 * Se algum dado for inválido, escreve a linha original no ficheiro de erro.
 *
 * @param camps        Matriz de strings contendo os campos do voo já processados
 *                     (ID, datas, estado, aeroportos, aeronave, etc.).
 * @param file         Ficheiro onde será escrita a linha original caso o voo seja inválido.
 * @param original     String com a linha original do ficheiro de entrada.
 * @param global       Estrutura global de gestão onde o voo será inserido.
 *
 * @return 0 se a inserção foi bem-sucedida,
 *         valor > 0 se ocorrer erro de validação,
 *         valor -1 se o voo for válido mas não confirmado (ex.: cancelado).
 */
int addFlight(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global); 
#endif