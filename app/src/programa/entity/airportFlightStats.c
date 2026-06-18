#include "entity/airportFlightStats.h"

struct info {
  int numFlights;
  char *code;
};

AirportInfo *createAirportInfo(int numFlights, const char *code) {
  AirportInfo *info = malloc(sizeof(AirportInfo));
  info->numFlights = numFlights;
  info->code = code ? g_strdup(code) : NULL;
  return info;
}

char *getCodeFromAirportInfo(AirportInfo *airportInfo) {
  return g_strdup(airportInfo->code);
}

int getNumFlightFromAirportInfo(AirportInfo *airportInfo) {
  return airportInfo->numFlights;
}

void freeAirportInfo(AirportInfo *info) {
  if (!info) return;
  g_free(info->code);
  g_free(info);
}