#include "managers/managerFlights.h"
#include "glib.h"
#include <math.h>
#include "entity/aircraftFlightDelay.h"



struct manager {
  GHashTable *flightsHash;
  GHashTable *airlineDelays;
  GArray *sortedDelays;
};


ManagerFlights *initFlights() {
  ManagerFlights *flights = malloc(sizeof(ManagerFlights));
  flights->flightsHash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                               (GDestroyNotify)freeFlight);
  flights->airlineDelays = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free); 
  flights->sortedDelays = g_array_new(FALSE, FALSE, sizeof(char *));
  return flights;
}

void insertFlight(ManagerFlights *manFlights, Flight *flight, char *code) {
  g_hash_table_insert(manFlights->flightsHash, g_strdup(code), flight);
}

void insertAirlineDelay(ManagerFlights *manFlights, char *airlineCode,
                        char *predicted, char *real) {
  double delay = calculateDelay(predicted, real);
  FlighDelay *currentDelay = g_hash_table_lookup(manFlights->airlineDelays, airlineCode);
  if (currentDelay) {
    addFlightDelay(currentDelay, delay); 
    incFlightCountToDelay(currentDelay); 
  } else {
    FlighDelay *newDelay = createFlightDelay(delay,1); 
    g_hash_table_insert(manFlights->airlineDelays, g_strdup(airlineCode),
                        newDelay);
  }
}

void sortAirlineDelays(ManagerFlights *manFlights) {
  if (manFlights->sortedDelays->len > 0)
    return;
  GHashTableIter iter;
  gpointer key;
  FlighDelay *value;
  g_hash_table_iter_init(&iter, manFlights->airlineDelays);
  while (g_hash_table_iter_next(&iter, &key, (gpointer)(&value))) {
    addAvgDelay(value); 
    g_array_append_val(manFlights->sortedDelays, key);
  }
  g_array_sort_with_data(manFlights->sortedDelays, compareAirlineDelays,
                         manFlights->airlineDelays);
}

FlighDelay *getAirlineDelay(ManagerFlights *manFlights, char *airlineCode) {
  return g_hash_table_lookup(manFlights->airlineDelays, airlineCode);
}

char *getAirlineByIndex(ManagerFlights *manFlights, int index) {
  if (index < 0 || index >= (int)manFlights->sortedDelays->len)
    return NULL;
  return g_array_index(manFlights->sortedDelays, char *, index);
}

int compareAirlineDelays(const void *a, const void *b, gpointer ht) {
  char *pa = *(char **)a;
  char *pb = *(char **)b;

  FlighDelay *va = g_hash_table_lookup(ht, pa);
  FlighDelay *vb = g_hash_table_lookup(ht, pb);
  int delay1 = getAvgDelay(va);
  int delay2 = getAvgDelay(vb);
  if (delay1 > delay2) {
    return -1;
  } else if (delay1 < delay2) {
    return 1;
  } else
    return g_strcmp0(pa, pb);
}

const Flight *getFlightById(ManagerFlights *manFlights, char *id) {
  return (const Flight *)g_hash_table_lookup(manFlights->flightsHash, id);
}

void freeAllFlights(ManagerFlights *manFlights) {
  g_hash_table_destroy(manFlights->flightsHash);
  g_hash_table_destroy(manFlights->airlineDelays);
  g_array_free(manFlights->sortedDelays, TRUE);
  free(manFlights);
}
