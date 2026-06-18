#ifndef AIRCRAFTS_MAN_H
#define AIRCRAFTS_MAN_H

#include "entity/aircraft.h"
#include "glib.h"
#include "glibconfig.h"

typedef struct manager ManagerAircrafts; 

/**
 * @brief Inicializa o gestor de aeronaves.
 * @return Ponteiro para ManagerAircrafts recém-criado.
 */
ManagerAircrafts *initAircrafts(); 

/**
 * @brief Adiciona uma aeronave ao gestor.
 *
 * @param aircraft Ponteiro para a aeronave.
 * @param managerAircraft Ponteiro para o gestor de aeronaves.
 * @param aircraftId Código da aeronave.
 * @param manufacter Fabricante da aeronave.
 */
void insertAircraft(Aircraft *aircraft, ManagerAircrafts *managerAircraft, char *aircraftId, char *manufacter); 

/**
  @brief Função de comparação usada para ordenar aeronaves pelo número de voos.

  @param a Ponteiro para a primeira aeronave.
  @param b Ponteiro para a segunda aeronave.

  @return Valor do tipo gint:
          -1 se a < b,
           1 se a > b,
           0 se forem iguais.
*/
gint compareNumFlights(gconstpointer a, gconstpointer b);

//GArray *AircraftArraySort(const char *manufacter);  

/**
 * @brief Obtém a aeronave na posição i do array.
 *
 * Faz verificação dos limites e retorna NULL se o índice for inválido
 * ou se o array for NULL senão aessa o elemento na posição i do GArray e 
 * retorna o ponteiro para a aeronave já existente no array.
 *
 * @param result Ponteiro para o GArray de aeronaves.
 * @param i Índice da aeronave desejada.
 * @return Ponteiro para a aeronave no índice i ou NULL se inválido.
 */
const Aircraft *processArrayResult(ManagerAircrafts *manager, const char *manu, int i); 

/**
 * @brief Obtém um array de aeronaves, opcionalmente filtrado por fabricante.
 *
 * @param managerAircraft Estrutura que gere todas as aeronaves.
 * @param manufacter Nome do fabricante para filtrar as aeronaves, ou NULL para obter todas.
 *
 * @return Um ponteiro para um GArray contendo as aeronaves correspondentes.
 */
GArray *getArrayAircraft(ManagerAircrafts *managerAircraft, const char *manufacter); 

/**
  @brief Ordena os arrays de aeronaves pelo número de voos.

  @param managerAircraft Ponteiro para a estrutura ManagerAircrafts.
*/
void arraysAircraftSort(ManagerAircrafts *managerAircraft); 

/**
 * @brief Incrementa o número de voos de uma aeronave.
 *
 * Procura a aeronave pelo código, obtém o índice no array global e
 * incrementa o contador de voos.
 *
 * @param managerAircraft Ponteiro para a estrutura ManagerAircrafts.
 * @param code Código da aeronave.
 */
void addFlightToAircraft(ManagerAircrafts *managerAircraft, char *code); 

/**
  @brief Retorna o número total de aeronaves no gestor.

  @param managerAircraft Ponteiro para a estrutura ManagerAircrafts.

  @return Número total de aeronaves armazenadas.
*/
int numAircrafts(ManagerAircrafts *managerAircraft); 

/**
  @brief Verifica se uma aeronave existe no gestor pelo código.

  @param managerAircraft Ponteiro para a estrutura ManagerAircrafts.
  @param code             Código da aeronave a verificar.

  @return 1 se a aeronave existir, 0 caso contrário.
*/
int AircraftExists(ManagerAircrafts *managerAircraft, char *code); 

/**
  @brief Liberta toda a memória do gestor de aeronaves.
  @param managerAircraft Ponteiro para a estrutura ManagerAircrafts a libertar.
*/
void freeAllAircrafts(ManagerAircrafts *managerAircraft);

/**
  @brief Liberta a memória de um array de aeronaves.
  @param a Ponteiro para o GArray de aeronaves a libertar.
*/
void freeArrayAircrafts(GArray *a); 

#endif