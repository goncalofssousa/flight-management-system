#ifndef AIRCRAFTS_H
#define AIRCRAFTS_H

#include "glib.h"
#include "verification.h"

typedef struct aircraft Aircraft;

/**
 * @brief Retorna uma cópia do código de uma aeronave.
 * @param a Ponteiro para a aeronave.
 * @return Uma string que tem o código ou NULL se a aeronave não existir.
 */
char *getIdAircraft(const Aircraft *a); 

/**
 * @brief Retorna uma cópia do fabricante de uma aeronave.
 * @param a Ponteiro para a aeronave.
 * @return Uma string com o fabricante.
 */
char *getManufacter(const Aircraft *a);

/**
 * @brief Retorna uma cópia do modelo de uma aeronave.
 * @param a Ponteiro para a aeronave.
 * @return Uma string com o modelo.
 */
char *getModel(const Aircraft *a);

/**
 * @brief Retorna o número de voos realizados por uma aeronave.
 * @param a Ponteiro para a aeronave.
 * @return Número de voos.
 */
int getNumFlights(const Aircraft *a); 


/**
 * @brief Retorna o id da aeronave.
 * @param a Ponteiro para a aeronave.
 * @return id.
 */
int getIndex (const Aircraft *a);


/**
 * @brief Incrementa o contador de voos de uma aeronave.
 * @param a Ponteiro para a aeronave.
 */
void incFlightCount(Aircraft *a); 

/**
 * @brief Cria e inicializa uma nova aeronave.
 * @param code Código identificador.
 * @param manu Fabricante.
 * @param model Modelo.
 * @param id id.
 * @return Ponteiro para a nova aeronave alocada.
 */
Aircraft *allocateAircraft(char *code, char *manu, char *model, int id); 

/**
 * @brief Liberta a memória associada a uma aeronave.
 * @param a Ponteiro para a aeronave a libertar.
 */
void freeAircraft(Aircraft *a);
#endif