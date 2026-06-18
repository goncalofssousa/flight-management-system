#include "managers/managerAirports.h"
#include <stdio.h>

struct manager {
  GHashTable *airportsHash;
};

ManagerAirports *initAirports() {
    ManagerAirports *airports = malloc(sizeof(ManagerAirports));

    airports->airportsHash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)freeAirport);
    return airports;
}

const Airport *getAirportById(ManagerAirports *manager, char *id) {
  return (const Airport *)g_hash_table_lookup(manager->airportsHash, id);
}

void insertAirport(ManagerAirports *manager, Airport *airport, char *code) {
  g_hash_table_insert(manager->airportsHash, g_strdup(code), airport);
}

void insertInAirporDateHash(int date, char *origin, ManagerAirports *airportsManager) {
  Airport *a = g_hash_table_lookup(airportsManager->airportsHash, origin); 
  incFlightDateCount(a,date); 
}

void sortAllHashTables(ManagerAirports *manager){
  GHashTableIter iter;
  gpointer key, value;
  g_hash_table_iter_init(&iter, manager->airportsHash);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    Airport *a = value; 
    hashTableToSortArrayAirports(a); 
  }
}

AirportInfo *getMaxFromDateInterval(ManagerAirports *manager, int dateIn, int dateFin){
  GHashTableIter iter;
  gpointer key, value;
  int max = 0; 
  char *codeMax = NULL; 
  g_hash_table_iter_init(&iter, manager->airportsHash);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
      Airport *a = value; 
      int count = getCountFromDateInterval(dateIn, dateFin, a); 
      if(count > max){
        char *code = getCode(a); 
        max = count; 
        if(codeMax) g_free(codeMax); 
        codeMax = g_strdup(code);
        g_free(code);  
      }
      else if(count != 0 && count == max){
        char *code = getCode(a); 
        if(max == -1){
          max = count;
          codeMax = g_strdup(code); 
        }
        else{
          if(strcmp(code, codeMax) < 0){
            g_free(codeMax); 
            codeMax = g_strdup(code);
          }
        }
        g_free(code); 
      }
  }
  if(max == 0) return NULL; 
  AirportInfo *a = createAirportInfo(max, codeMax); 
  return a; 
}


void incPassengerDepartureAirport(ManagerAirports *manAirports,
                                  char *codeAirportOrigin) {
  Airport *a = g_hash_table_lookup(manAirports->airportsHash, codeAirportOrigin);
  incPassengerDeparture(a);
}
void incPassengerArrivalAirport(ManagerAirports *manAirports,
                                char *codeAirportDestination) {
  Airport *a = g_hash_table_lookup(manAirports->airportsHash, codeAirportDestination);
  incPassengerArrival(a);
}


void freeAllAirports(ManagerAirports *airports) {
  g_hash_table_destroy(airports->airportsHash);
  free(airports);
}
