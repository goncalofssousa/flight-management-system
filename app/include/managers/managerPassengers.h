#ifndef PASSENGERS_MAN_H
#define PASSENGERS_MAN_H

#include "entity/passenger.h"
#include "glib.h"

typedef struct manager ManagerPassengers; 
typedef struct destinfo DestInfo;
typedef struct arraydest ArrayDest;
typedef struct nacionalidade Nacionalidade;
extern Passenger **passengersArray;

/**
 * @brief Inicializa o gestor de passageiros.
 * @return Ponteiro para ManagerPassengers.
 */
ManagerPassengers *initPassengers(); 

/**
 * @brief Insere um passageiro no gestor.
 *
 * @param manPassengers Ponteiro para o ManagerPassengers.
 * @param passenger Ponteiro para a estrutura Passenger a inserir.
 * @param docNumber Documento do passageiro (chave na hash table).
 */
void insertPassenger(ManagerPassengers *manPassengers, Passenger *passenger, char *docNumber);

/**
 * @brief Obtém um passageiro pelo documento.
 *
 * @param manPassengers Ponteiro para o ManagerPassengers.
 * @param id Documento do passageiro.
 * @return Ponteiro para Passenger correspondente ou NULL se não existir.
 */
const Passenger *getPassengerById(ManagerPassengers *manPassengers, char *id); 

/**
 * @brief Retorna o código do aeroporto com mais passageiros para uma nacionalidade.
 *
 * @param manPassengers Ponteiro para o ManagerPassengers.
 * @param nacionality Nome da nacionalidade.
 * @return Código do aeroporto com mais passageiros ou NULL se não existir.
 */
char *getCodeNacionality(ManagerPassengers *manPassengers, char *nacionality); 

/**
 * @brief Retorna o número máximo de passageiros para uma nacionalidade.
 *
 * @param manPassengers Ponteiro para o ManagerPassengers.
 * @param nacionality Nome da nacionalidade.
 * @return Número máximo de passageiros.
 */
int getMaxNacionality(ManagerPassengers *manPassengers, char *nacionality); 

/**
 * @brief Verifica se um passageiro existe no gestor.
 *
 * @param manPassengers Ponteiro para o ManagerPassengers.
 * @param id Documento do passageiro.
 * @return 0 se existir, 1 caso contrário.
 */
int PassengerExists(ManagerPassengers *manPassengers, char *id); 

/**
 * @brief Liberta todos os passageiros e nacionalidades do gestor.
 *
 * @param manPassengers Ponteiro para o ManagerPassengers a ser liberado.
 */
void freeAllPassengers(ManagerPassengers *manPassengers); 

/**
 * @brief Atualiza a contagem de passageiros de uma nacionalidade por aeroporto.
 *
 * Caso a nacionalidade não exista, cria uma nova entrada e inicializa
 * os campos. Atualiza o número total de passageiros por aeroporto
 * e mantém o aeroporto com mais passageiros para essa nacionalidade.
 *
 * @param m Ponteiro para o ManagerPassengers.
 * @param nacionalidade Nome da nacionalidade.
 * @param codeAirport Código do aeroporto de destino.
 */
void addPassengerToDest(ManagerPassengers *m, char *nacionalidade,  char *codeAirport);

/**
 * @brief Liberta a memória de uma nacionalidade.
 *
 * @param nac Ponteiro para a estrutura Nacionalidade a ser liberada.
 */
void freeNacionality(Nacionalidade *nac); 

#endif
