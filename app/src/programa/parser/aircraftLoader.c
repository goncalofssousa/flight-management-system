#include "parser/aircraftLoader.h"

int addAircraft(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global) {
  if (verifyYear(camps[3])) {
    fprintf(file, "%s", original);
  } else {
    ManagerAircrafts *aircraftMan = getAircraftManager(global);
    int id = numAircrafts(aircraftMan);
    Aircraft *aircraft = allocateAircraft(camps[0], camps[1], camps[2], id);
    insertAircraft(aircraft,aircraftMan, camps[0], camps[1]);
  }
  return 0;
}