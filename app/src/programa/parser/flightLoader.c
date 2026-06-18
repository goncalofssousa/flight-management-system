#include "parser/flightLoader.h"
#include "logicVerify.h"
#include "managers/managerFlights.h"
#include "verification.h"

int addFlight(char camps[][MAX_STRING], FILE *file, char *original,ManagerGlobal *global) {
  ManagerFlights *manFlights = getFlightManager(global);
  ManagerAircrafts *manAircrafts = getAircraftManager(global);
  ManagerAirports *manAirports = getAirportManager(global);
  
  if (verifyFlightId(camps[0])  || verifyDate(camps[1]) || verifyDate(camps[2]) || verifyDate(camps[3]) || verifyDate(camps[4]) || verifyAcs(camps[1], camps[3]) || verifyAcs(camps[2], camps[4]) || 
      verifyStateFlight(camps[6]) || verifyStateDate(camps[6], camps[1], camps[2], camps[3], camps[4]) || verifyOriginDest(camps[7], camps[8]) || verifyAircraftExists(manAircrafts, camps[9])
    ){
    fprintf(file, "%s", original);
  } else {
    Flight *flight = allocateFlight(camps[0], camps[1], camps[6], camps[7], camps[8]);
    insertFlight(manFlights, flight, camps[0]);
    int state = getFlightState(flight);

    if (state != 2) {
      if (state == 1) insertAirlineDelay(manFlights, camps[10], camps[1], camps[2]);
      int date = getIntDate(camps[3]); 
      addFlightToAircraft(manAircrafts, camps[9]);
      insertInAirporDateHash(date, camps[7], manAirports);
    }
  }
  return 0;
}
