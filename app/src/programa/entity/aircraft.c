#include "entity/aircraft.h"

struct aircraft {
  char *code;
  char *manufacter;
  char *model;
  int numFlights; 
  int id;
};

char *getIdAircraft(const Aircraft *a) { 
    if(a) return g_strdup(a->code); 
    return NULL; 
}

char *getManufacter(const Aircraft *a) { return g_strdup(a->manufacter); }

char *getModel(const Aircraft *a) { return g_strdup(a->model); }

int getNumFlights(const Aircraft *a){
  return a->numFlights;  
}

int getIndex (const Aircraft *a) { return a->id; }


void incFlightCount(Aircraft *a){
  a->numFlights++; 
}

Aircraft *allocateAircraft(char *code, char *manu, char *model, int id){
  Aircraft* aircraft = g_new(Aircraft, 1);
  aircraft->code = g_strdup(code);
  aircraft->manufacter = g_strdup(manu);
  aircraft->model = g_strdup(model);
  aircraft->id = id; 
  aircraft->numFlights = 0;
  return aircraft;
}

void freeAircraft(Aircraft *a) {
  if (!a)
    return;

  g_free(a->code);
  g_free(a->manufacter);
  g_free(a->model);
  g_free(a);
}
