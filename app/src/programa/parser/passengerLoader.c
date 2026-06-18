#include "parser/passengerLoader.h"

int addPassenger(char camps[][MAX_STRING], FILE *file, char *original, ManagerGlobal *global) {
  ManagerPassengers *manPassengers = getPassengerManager(global); 
  if (verifyDocument(camps[0]) || verifyDOB(camps[3]) || verifyGender(camps[5]) || verifyEmail(camps[6])) {
    fprintf(file, "%s", original);
  } else {
    Passenger *passenger = allocatePassenger(camps[0],camps[1],camps[2],  camps[3], camps[4]);
    insertPassenger(manPassengers, passenger, camps[0]);
  }
  return 0;
}