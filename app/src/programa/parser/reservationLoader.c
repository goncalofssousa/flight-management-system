#include "parser/reservationLoader.h"
#include "flight.h"
#include "managers/managerReservations.h"

int parseFlights(char *str, char *ids[2]) {
  if (str[0] != '[')
    return -1;

  str++;
  char *start = str;
  int i = 0;
  int flag = 0;
  int closeIt = 0;

  while (start && *start && i < 2) {
    if (*start == '\'' && flag) {
      flag = 0;
      *start = '\0';
      ids[i++] = str;
      if (*(start + 1) == ',') {
        start++;
      } else if (*(start + 1) == ']') {
        closeIt = 1;
        break;
      }
    } else if (*start == '\'') {
      str = start + 1;
      flag = 1;
    }
    start++;
  }
  return closeIt ? i : -1;
}

int addReservation(char camps[][MAX_STRING], FILE *file, char *original,ManagerGlobal *global) {
  ManagerPassengers *manPassengers = getPassengerManager(global);
  ManagerReservations *manReservations = getReservationManager(global);
  ManagerFlights *manFlights = getFlightManager(global);
  ManagerAirports *manAirports = getAirportManager(global);
  int flag = 0, i = 0;
  char *origin = NULL;
  char *destiny = NULL;
  while (i < 3 && !flag) {
    switch (i) {
    case 0: {
      flag += verifyReservation(camps[0]);
      break;
    }
    case 1: {
      char *idsAux[2];
      int N = parseFlights(camps[1], idsAux);
      if (N < 1 || verifyFlights(idsAux, N - 1, manFlights))
        flag++;
      else {
        origin = g_strdup(idsAux[0]);
        if (N > 1) {
          destiny = g_strdup(idsAux[1]);
        }
      }
      break;
    }
    case 2: {
      flag += verifyReservationDocNumber(manPassengers, camps[2]);
      break;
    }
    }
    i++;
  }
  if (flag > 0) {
    fprintf(file, "%s", original);
  } else {
    const Flight *flight1 = getFlightById(manFlights, origin);
    const Flight *flight2 = destiny ? getFlightById(manFlights, destiny) : NULL;
    const Passenger *passenger = getPassengerById(manPassengers, camps[2]);
    char *nacionalidade = getPassengerNacionality(passenger);
    char *departure = getDeparture(flight1);
    int date = getSundayDate(departure);
    insertReservationByWeek(manReservations, date, camps[2], atof(camps[4]));

    free(departure);
    
    if (getFlightState(flight1) != 2) {
      char *codeAirportOrigin = getOrigin(flight1);
      char *codeAirportDestination = getDestination(flight1);
      incPassengerDepartureAirport(manAirports, codeAirportOrigin);
      incPassengerArrivalAirport(manAirports, codeAirportDestination);
      addPassengerToDest(manPassengers, nacionalidade, codeAirportDestination);
      g_free(codeAirportDestination);
      g_free(codeAirportOrigin);
    }
    if (flight2 && getFlightState(flight2) != 2) {
      char *codeAirportOrigin = getOrigin(flight2);
      char *codeAirportDestination = getDestination(flight2);
      incPassengerDepartureAirport(manAirports, codeAirportOrigin);
      incPassengerArrivalAirport(manAirports, codeAirportDestination);
      addPassengerToDest(manPassengers, nacionalidade, codeAirportDestination);
      g_free(codeAirportDestination);
      g_free(codeAirportOrigin);
    }
    g_free(nacionalidade);
  }
  if (origin)
    g_free(origin);
  if (destiny)
    g_free(destiny);
  return flag;
}