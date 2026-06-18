#ifndef GLOBAL_MAN_H
#define GLOBAL_MAN_H

#include "glib.h"
#include "managers/managerAircrafts.h"
#include "managers/managerAirports.h"
#include "managers/managerFlights.h"
#include "managers/managerPassengers.h"
#include "managers/managerReservations.h"

typedef struct manager ManagerGlobal;

/**
 * @brief Cria e inicializa um gestor global.
 *
 * @return Ponteiro para o ManagerGlobal.
 */
ManagerGlobal *allocateManagerGlobal();

/**
 * @brief Inicializa todos os gestores dentro do gestor global.
 * @param manager Ponteiro para o ManagerGlobal a inicializar.
 */
void initManager(ManagerGlobal *manager);

/**
 * @brief Cria e adiciona o gestor de aeroportos ao gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 */
void insertManagerAirports(ManagerGlobal *manager);

/**
 * @brief Cria e adiciona o gestor de aeronaves ao gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 */
void insertManagerAircrafts(ManagerGlobal *manager);

/**
 * @brief Cria e adiciona o gestor de voos ao gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 */
void insertManagerFlights(ManagerGlobal *manager);

/**
 * @brief Cria e adiciona o gestor de passageiros ao gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 */
void insertManagerPassengers(ManagerGlobal *manager);

/**
 * @brief Cria e adiciona o gestor de reservas ao gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 */
void insertManagerReservations(ManagerGlobal *manager);

/**
 * @brief Retorna o gestor de aeroportos do gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 * @return Ponteiro para ManagerAirports.
 */
ManagerAirports *getAirportManager(ManagerGlobal *manager);

/**
 * @brief Retorna o gestor de aeronaves do gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 * @return Ponteiro para ManagerAircrafts.
 */
ManagerAircrafts *getAircraftManager(ManagerGlobal *manager);

/**
 * @brief Retorna o gestor de voos do gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 * @return Ponteiro para ManagerFlights.
 */
ManagerAirports *getFlightManager(ManagerGlobal *manager);

/**
 * @brief Retorna o gestor de passageiros do gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 * @return Ponteiro para ManagerPassengers.
 */
ManagerPassengers *getPassengerManager(ManagerGlobal *manager);

/**
 * @brief Retorna o gestor de reservas do gestor global.
 *
 * @param manager Ponteiro para o ManagerGlobal.
 * @return Ponteiro para ManagerReservations.
 */
ManagerReservations *getReservationManager(ManagerGlobal *manager);

/**
 * @brief Liberta todos os gestores individuais e o gestor global.
 *
 * Chama a função de free de cada gestor individual, destrói a hash table do ManagerGlobal
 * e liberta o ponteiro do ManagerGlobal.
 *
 * @param manager Ponteiro para o ManagerGlobal a ser liberado.
 */
void freeAll(ManagerGlobal *manager);
#endif