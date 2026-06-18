#include "logicVerify.h"


int verifyStateDate(char *state, char *date1, char *date2,char *date3, char *date4){
  int estado;
    if (g_strcmp0(state, "On Time") == 0)
        estado = 0;
    else if (g_strcmp0(state, "Delayed") == 0)
        estado = 1;
    else if (g_strcmp0(state, "Cancelled") == 0)
        estado = 2;
    else {
        return 1;
    }

    switch (estado) {
      case 2:  
          if (strcmp(date2, "N/A") != 0 || strcmp(date4, "N/A") != 0) {
              return 1;
          }
          break;

      case 1:  
          if (strcmp(date1, date2) > 0 || strcmp(date3, date4) > 0) {
              return 1;
          }
          break;

      case 0: 
          if (strcmp(date1, date2) != 0 || strcmp(date3, date4) != 0) {
              return 1;
          }
          break;
    }
    return 0;
}

int verifyList(char *str, char *ids[2]) {
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

int verifyFlights(char *ids[2], int flag, ManagerFlights *manFlights) {
  int returnV = 0;
  if (!ids || !ids[0] || (flag && !ids[1]))
    return 1;
  const Flight *flight = getFlightById(manFlights,ids[0]);
  if (!flight) {
    return 1;
  }

  if (flag) {
    const Flight *flight2 = getFlightById(manFlights,ids[1]);
    if (!flight2) {
      return 1;
    }
    char *destination = getDestination(flight);
    char *origin = getOrigin(flight2);
     if (!destination || !origin || strcmp(destination, origin) != 0){
        returnV = 1;
    }
    g_free(destination);
    g_free(origin);
  }

  return returnV;
}

int verifyReservationFlights(ManagerFlights *manFlights, char *ids) {
  char *idsAux[2];
  int N = verifyList(ids, idsAux);
  if (verifyFlights(idsAux, N - 1,manFlights))
    return -1;
  return N;
}

int verifyAircraftExists(ManagerAircrafts *manAircrafts, char *code){
  if(!AircraftExists(manAircrafts, code)) return 1;
  return 0; 
}

int verifyReservationDocNumber(ManagerPassengers *passengers, char *docNumber) {
  if (!verifyDocument(docNumber) && !PassengerExists(passengers,docNumber)) {
    return 0;
  }
  return 1;
}