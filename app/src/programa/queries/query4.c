#include "queries/query4.h"
#include "geral.h"
#include "io/output.h"

Output *query4Output(char *id, ManagerPassengers *manPassengers, int count) {
  Output *out = createOutput();
  const Passenger *p = getPassengerById(manPassengers, id);
  char *firstName = getPassengerFirstName(p);
  char *lastName = getPassengerLastName(p);
  char *dob = getPassengerDOB(p);
  char *nacionality = getPassengerNacionality(p);
  addToken(out, id);
  addToken(out, firstName);
  addToken(out, lastName);
  addToken(out, dob);
  addToken(out, nacionality);
  addIntToken(out, count);
  addToken(out, "\n");
  free(firstName);
  free(lastName);
  free(dob);
  free(nacionality);
  return out;
}

Output *query4(char *start, char *end, ManagerGlobal *manager) {
  ManagerReservations *manReservations = getReservationManager(manager);
  ManagerPassengers *manPassengers = getPassengerManager(manager);
  
  if (start) {
    Output *out;
    int startSunday = getSundayDate(start);
    int endSunday = getSundayDate(end);
    GHashTable *order = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    setArrayDate(manReservations, startSunday);
    int flag = 1;
    while (flag) {
      GArray *top10 = getArrayTop10(manReservations);
      if (top10)
        for (int i = 0; i < (int)top10->len; i++) {
          char *passengerId = getIdFromArrayIndex(top10, i);
          void *value = g_hash_table_lookup(order, passengerId);
          if (!value) {
            g_hash_table_insert(order, g_strdup(passengerId),
                                GINT_TO_POINTER(1));
          } else {
            int count = GPOINTER_TO_INT(value);
            g_hash_table_replace(order, g_strdup(passengerId),GINT_TO_POINTER(count + 1));
          }
        }
      flag = getNextDate(manReservations, endSunday);
    }
    GArray *allTop = g_array_new(FALSE, FALSE, sizeof(char *));
    hashTableToSorterArray(order, allTop);
    g_array_sort_with_data(allTop, compareAllTop, order);

    if (allTop->len > 0) {
      char *topId = g_array_index(allTop, char *, 0);
      int manCount = GPOINTER_TO_INT(g_hash_table_lookup(order, topId));
      out = query4Output(topId, manPassengers, manCount);
    } else {
      out = createOutput();
    }

    g_array_free(allTop, TRUE);
    g_hash_table_destroy(order);

    return out;
  } else {
    char *passengerId = getIdFromAllTime(manReservations);
    if (!passengerId)        
        return createOutput(); 
    return query4Output(passengerId, manPassengers, getCountFromAllTime(manReservations));
  }
}
