#include "parser/airportLoader.h"
#include "verification.h"

int addAirport(char camps[][MAX_STRING], FILE *file, char *original,  ManagerGlobal *global) {
  if (verifyAirport(camps[0]) || verifyLatitude(camps[4]) || verifyLongitude(camps[5]) || verifyType(camps[7])) {
    fprintf(file, "%s", original);
  } else {
    ManagerAirports *airportMan = getAirportManager(global); 
    Airport *airport = allocateAirport(camps[0], camps[1], camps[2],camps[3],camps[7]); 
    insertAirport(airportMan, airport, camps[0]); 
 }
  return 0;
}