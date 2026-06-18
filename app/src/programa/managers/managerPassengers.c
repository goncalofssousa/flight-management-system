#include "managers/managerPassengers.h"


struct manager{
  GHashTable *passengers;
  GHashTable *nacionality; 
}; 


struct nacionalidade{
  GHashTable *airportsCount;
  char *code_max;
  int max_passenger;
}; 


ManagerPassengers *initPassengers() {
  ManagerPassengers *manPassengers = malloc(sizeof(ManagerPassengers)); 
  manPassengers->passengers = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                     (GDestroyNotify)freePassenger);       
  manPassengers->nacionality = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                     (GDestroyNotify)freeNacionality);      
                                                      
  return manPassengers; 
}

void insertPassenger(ManagerPassengers *manPassengers, Passenger *passenger, char *docNumber) {
  g_hash_table_insert(manPassengers->passengers, g_strdup(docNumber), passenger);
}

void addPassengerToDest(ManagerPassengers *m, char *nacionalidade, char *codeAirport) {
    Nacionalidade *nac = g_hash_table_lookup(m->nacionality, nacionalidade);

    if (!nac) {
        nac = g_new0(Nacionalidade, 1);
        nac->airportsCount = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
        nac->code_max = NULL;
        nac->max_passenger = 0;
        g_hash_table_insert(m->nacionality, g_strdup(nacionalidade), nac);
    }

    gpointer val = g_hash_table_lookup(nac->airportsCount, codeAirport);
    int passageiros = val ? GPOINTER_TO_INT(val) : 0;
    passageiros++;

    g_hash_table_insert(nac->airportsCount, g_strdup(codeAirport), GINT_TO_POINTER(passageiros));

    if (passageiros > nac->max_passenger) {
        nac->max_passenger = passageiros;
        g_free(nac->code_max);
        nac->code_max = g_strdup(codeAirport);
    } else if (passageiros == nac->max_passenger) {
        if (!nac->code_max || strcmp(codeAirport, nac->code_max) < 0) {
            g_free(nac->code_max);
            nac->code_max = g_strdup(codeAirport);
        }
    }
}


char *getCodeNacionality(ManagerPassengers *manPassengers, char *nacionality){
  Nacionalidade *nac = g_hash_table_lookup(manPassengers->nacionality,nacionality);
  if(nac) return g_strdup(nac->code_max); 
  return NULL; 
} 

int getMaxNacionality(ManagerPassengers *manPassengers, char *nacionality){
  Nacionalidade *nac = g_hash_table_lookup(manPassengers->nacionality,nacionality);
  return nac->max_passenger;
} 

const Passenger *getPassengerById(ManagerPassengers *manPassengers, char *id) {
  return (const Passenger *)g_hash_table_lookup(manPassengers->passengers, id);
}

int PassengerExists(ManagerPassengers *manPassengers, char *id) { return !g_hash_table_contains(manPassengers->passengers, id); }

void freeAllPassengers(ManagerPassengers *manPassengers) { 
  g_hash_table_destroy(manPassengers->passengers);
  g_hash_table_destroy(manPassengers->nacionality); 
  free(manPassengers);
}

void freeNacionality(Nacionalidade *nac) {
    if (!nac) return;

    g_hash_table_destroy(nac->airportsCount);
    g_free(nac->code_max);
    g_free(nac);
}