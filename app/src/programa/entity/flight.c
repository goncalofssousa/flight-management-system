#include "entity/flight.h"

enum state { ON_TIME = 0, DELAYED = 1, CANCELLED = 2 };

struct flight {
  char *id;
  char *departure;
  State state;
  char *origin;
  char *destination;
};


void setState(Flight *flight, char *state) {
  if (g_strcmp0(state, "On Time") == 0) {
    flight->state = 0;
  } else if (g_strcmp0(state, "Delayed") == 0) {
    flight->state = 1;
  } else if (g_strcmp0(state, "Cancelled") == 0) {
    flight->state = 2;
  }
}


char *getDestination(const Flight *flight) { return g_strdup(flight->destination); }

char *getOrigin(const Flight *flight) { return g_strdup(flight->origin); }

int getFlightState(const Flight *flight) { return (flight->state); }

char *getDeparture(const Flight *flight) { return g_strdup(flight->departure); }

char* getFlightDestination(Flight *f) {
    if (!f || !f->destination) return NULL;
    return f->destination; 
}

Flight *allocateFlight(char *code, char *departure, char *status,char *origin, char *dest){
  Flight *flight = g_new0(Flight, 1);
  flight->id = g_strdup(code); 
  flight->departure = g_strdup(departure); 
  flight->origin = g_strdup(origin); 
  flight->destination = g_strdup(dest); 
  setState(flight, status);
  return flight;
}

void freeFlight(Flight *f) {
  if (!f)
    return;
  g_free(f->id);
  g_free(f->origin);
  g_free(f->departure); 
  g_free(f->destination);
  g_free(f);
}