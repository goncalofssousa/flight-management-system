#include "managers/managerAircrafts.h"

struct manager{
  GHashTable *aircrafts;
  GHashTable *aircraftsByManufacturer; 
  GArray *allAircrafts; 
}; 

ManagerAircrafts *initAircrafts(){
  ManagerAircrafts *aircraftsMan = malloc(sizeof(ManagerAircrafts)); 
  aircraftsMan->aircrafts = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                    (GDestroyNotify)freeAircraft);
  aircraftsMan->allAircrafts = g_array_new(FALSE, FALSE, sizeof(Aircraft *));
  aircraftsMan->aircraftsByManufacturer = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                    (GDestroyNotify)freeArrayAircrafts);
  return  aircraftsMan;                            
}

void insertAircraft(Aircraft *aircraft, ManagerAircrafts *managerAircraft, char *aircraftId, char *manufacter) { 
    g_hash_table_insert(managerAircraft->aircrafts, g_strdup(aircraftId), aircraft);

    g_array_append_val(managerAircraft->allAircrafts, aircraft);

    GArray *aircraftMan = g_hash_table_lookup(managerAircraft->aircraftsByManufacturer, manufacter);
    if (!aircraftMan) {
        aircraftMan = g_array_new(FALSE, FALSE, sizeof(Aircraft*));
        g_hash_table_insert(managerAircraft->aircraftsByManufacturer, g_strdup(manufacter), aircraftMan);
    }
    g_array_append_val(aircraftMan, aircraft);
}

int numAircrafts(ManagerAircrafts *managerAircraft){
  return managerAircraft->allAircrafts->len;
}

void arraysAircraftSort(ManagerAircrafts *managerAircraft){
  g_array_sort(managerAircraft->allAircrafts, compareNumFlights); 
  GHashTableIter iter;
  gpointer key, value;

  g_hash_table_iter_init(&iter, managerAircraft->aircraftsByManufacturer);

  while (g_hash_table_iter_next(&iter, &key, &value)) {
      GArray *arr = value;
      g_array_sort(arr,  compareNumFlights);
  }
}


void addFlightToAircraft(ManagerAircrafts *managerAircraft, char *code) {
    Aircraft *a = g_hash_table_lookup(managerAircraft->aircrafts, code);
    int id = getIndex(a); 
    Aircraft *atual = g_array_index(managerAircraft->allAircrafts, Aircraft*, id);
    incFlightCount(atual);
}

gint compareNumFlights(gconstpointer a, gconstpointer b) {
    Aircraft *const *pa = a;
    Aircraft *const *pb = b;
    Aircraft *ia = *pa;
    Aircraft *ib = *pb;

    int numFlightsA = getNumFlights(ia); 
    int numFlightsB = getNumFlights(ib); 
    char *codeA = getIdAircraft(ia);
    char *codeB = getIdAircraft(ib); 

    gint result;

    if (numFlightsA < numFlightsB)
        result = 1;
    else if (numFlightsA > numFlightsB)
        result = -1;
    else {
        int cmp = strcmp(codeA, codeB);
        if (cmp < 0) result = -1;
        else if (cmp > 0) result = 1;
        else result = 0;
    }

    g_free(codeA);
    g_free(codeB);

    return result;
}


const Aircraft *processArrayResult(ManagerAircrafts *manager, const char *manu, int i){
  GArray *result = NULL; 
  if(!manu) result = manager->allAircrafts; 
  else {
    result = g_hash_table_lookup(manager->aircraftsByManufacturer, manu); 
  }
  if(result){  
      if (i < 0 || i >= (int) result->len) return NULL;
      const Aircraft *info = g_array_index(result, Aircraft*, i);
      return info; 
  }
  return NULL;
}

int AircraftExists(ManagerAircrafts *managerAircraft, char *code){
    int i = g_hash_table_contains(managerAircraft->aircrafts, code);
    return i; 
}

void freeAllAircrafts(ManagerAircrafts *managerAircraft) {
  g_hash_table_destroy(managerAircraft->aircrafts);
  g_hash_table_destroy(managerAircraft->aircraftsByManufacturer); 
  g_array_free(managerAircraft->allAircrafts, TRUE);
  free(managerAircraft);
}

void freeArrayAircrafts(GArray *a){
  g_array_free(a, TRUE);
}