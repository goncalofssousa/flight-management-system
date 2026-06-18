#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "glib.h"

typedef struct manager ManagerReservations;
typedef struct weekData WeekData;

/**
 * @brief Compara dois identificadores com base numa ordenação armazenada na hash table.
 *
 * @param a Ponteiro para o primeiro elemento a comparar.
 * @param b Ponteiro para o segundo elemento a comparar.
 * @param user_data Ponteiro para a GHashTable que define a ordem (chave → valor inteiro).
 *
 * @return Valor negativo, zero ou positivo conforme a ordem relativa dos elementos.
 */
int compareAllTop(const void *a, const void *b, gpointer user_data);

/**
 * @brief Compara dois identificadores de passageiros com base no total semanal.
 *
 * @param a Ponteiro para o primeiro elemento a comparar.
 * @param b Ponteiro para o segundo elemento a comparar.
 * @param user_data Ponteiro para a estrutura WeekData com os totais por passageiro.
 *
 * @return Valor negativo, zero ou positivo conforme a ordem relativa dos elementos.
 */
int compareTop(const void *a, const void *b, gpointer user_data);

/**
 * @brief Compara dois inteiros armazenados como gpointer.
 *
 * @param a Primeiro inteiro a comparar.
 * @param b Segundo inteiro a comparar.
 * @param user_data Ponteiro adicional passado pelo GTree.
 *
 * @return Valor negativo, zero ou positivo conforme a comparação entre os inteiros.
 */
int compareInt(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Inicializa o gestor de reservas.
 * @return Ponteiro para ManagerReservations recém-alocado.
 */
ManagerReservations *initReservations();

/**
 * @brief Inicializa a estrutura de dados de uma semana.
 * @return Ponteiro para WeekData recém-alocado.
 */
WeekData *initWeekData();

/**
 * @brief Callback para percorrer a árvore de semanas e atualizar top10 de cada semana.
 *
 * @param _ Ignorado (chave da árvore).
 * @param value Ponteiro para WeekData.
 * @param order Hash table para ranking global.
 * @return FALSE sempre (continua a iteração na árvore).
 */
gboolean foreach_tree(int _, WeekData *value, GHashTable *order);

/**
 * @brief Retorna o array top10 da última semana processada.
 *
 * @param manReservations Ponteiro para ManagerReservations.
 * @return GArray* com os IDs dos top10 passageiros ou NULL se não existir.
 */
GArray *getArrayTop10(ManagerReservations *manReservations);

/**
 * @brief Define a semana atual para processamento.
 *
 * @param manReservations Ponteiro para ManagerReservations.
 * @param intDate Data da semana.
 */
void setArrayDate(ManagerReservations *manReservations, int intDate);

/**
 * @brief Avança para a próxima semana e atualiza lastWeek e lastWeekNode.
 *
 * @param manReservations Ponteiro para ManagerReservations.
 * @param endDate Data final para limite.
 * @return 1 se houver próxima semana, 0 se ultrapassou endDate.
 */
int getNextDate(ManagerReservations *manReservations, int endDate);

/**
 * @brief Retorna o ID de um passageiro a partir de um índice num array.
 *
 * @param arr GArray* contendo IDs de passageiros (char*).
 * @param index Índice do elemento no array.
 * @return ID do passageiro na posição `index`.
 */
char *getIdFromArrayIndex(GArray *arr, int index);

/**
 * @brief Retorna o passageiro com mais reservas de todos os tempos.
 * @param manReservations Ponteiro para ManagerReservations.
 * @return ID do passageiro com mais reservas.
 */
char *getIdFromAllTime(ManagerReservations *manReservations);

/**
 * @brief Retorna o número de reservas do passageiro "all".
 *
 * @param manReservations Ponteiro para ManagerReservations.
 * @return Contagem de reservas ou -1 se ainda não calculada.
 */
int getCountFromAllTime(ManagerReservations *manReservations);

/**
 * @brief Insere uma reserva na semana correspondente.
 *
 * @param manReservations Ponteiro para ManagerReservations.
 * @param intDate Data da semana (YYYYMMDD).
 * @param passengerId Id do passageiro.
 * @param value Valor da reserva ou contagem a adicionar.
 */
void insertReservationByWeek(ManagerReservations *manReservations, int intDate,
                             char *passengerId, double value);

/**
 * @brief Atualiza o top10 da semana.
 *
 * @param week Ponteiro para WeekData a atualizar.
 * @param order Hash table para ranking global (opcional, pode ser NULL).
 */
void updateTop10(WeekData *week, GHashTable *order);

/**
 * @brief Liberta a memória de uma semana.
 *
 * @param week Ponteiro para WeekData.
 */
void freeWeekData(WeekData *week);

/**
 * @brief Liberta todas as reservas e o gestor de reservas.
 *
 * @param manReservations Ponteiro para ManagerReservations.
 */
void freeAllReservations(ManagerReservations *manReservations);

/**
 * @brief Percorre a árvore de semanas processando cada semana.
 *
 * @param key Ponteiro para a chave da árvore
 * @param value Ponteiro para o valor da árvore
 * @param user_data Ponteiro adicional
 *
 * @return gboolean TRUE para parar a travessia, FALSE para continuar.
 */
gboolean foreachTreeWrapper(gpointer key, gpointer value, gpointer user_data);

#endif