#ifndef PASSENGER_LOADER_H
#define PASSENGER_LOADER_H
#include "entity/passenger.h"
#include "managers/managerGlobal.h"
#include "verification.h"
#include "logicVerify.h"
#include <stdio.h>

/**
 * @brief Adiciona um passageiro.
 *
 * Preenche os campos correspondentes com os dados do passageiro.
 * Valida o número de documento, data de nascimento, género e email.
 * Se algum dado for inválido, escreve a linha original no ficheiro de erro.
 * Em caso de sucesso, insere o passageiro na estrutura global.
 *
 * @param camps        Matriz de strings contendo os campos do passageiro já separados
 *                     (documento, nome, apelido, data de nascimento, nacionalidade,
 *                     género, email, etc.).
 * @param file         Ficheiro onde será escrita a linha original caso o passageiro seja inválido.
 * @param original     String com a linha original do ficheiro de entrada.
 * @param global       Estrutura global de gestão onde o passageiro será inserido.
 *
 * @return 0 se a inserção foi bem-sucedida, valor > 0 caso contrário.
 */
int addPassenger(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global); 
#endif