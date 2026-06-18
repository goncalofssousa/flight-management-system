#ifndef RESERVATION_LOADER_H
#define RESERVATION_LOADER_H
#include "managers/managerGlobal.h"
#include "verification.h"
#include "logicVerify.h"
#include <stdio.h>

/**
 * @brief Adiciona uma reserva.
 *
 * Preenche os campos correspondentes com os dados da reserva, incluindo
 * voos associados, passageiro, origem e destino.
 * Valida o número da reserva, a existência dos voos associados e
 * o número de documento do passageiro.
 * Em caso de sucesso, atualiza os contadores de passageiros nos aeroportos
 * de origem e destino dos voos.
 * Se algum dado for inválido, escreve a linha original no ficheiro de erro.
 *
 * @param camps        Matriz de strings contendo os campos da reserva já processados.
 * @param file         Ficheiro onde será escrita a linha original caso a reserva seja inválida.
 * @param original     String com a linha original do ficheiro de entrada.
 * @param global       Estrutura global de gestão onde a reserva será inserida.
 *
 * @return 0 se a inserção foi bem-sucedida, valor > 0 caso contrário.
 */
int addReservation(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global); 
#endif