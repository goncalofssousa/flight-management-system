#include "queries/query1.h"
#include "airport.h"
#include "managers/managerGlobal.h"
#include <glib.h>

Output *query1(char *code, ManagerGlobal *manager) {
  ManagerAirports *airportsMan = getAirportManager(manager);
  const Airport *airport = getAirportById(airportsMan, code);
  Output *out = createOutput();

  if (airport) {
    addToken(out, code);

    char *name = getName(airport);
    addToken(out, name);

    char *city = getCity(airport);
    addToken(out, city);

    char *country = getCountry(airport);
    addToken(out, country);

    char *type = getType(airport);
    addToken(out, type);

    int passengerArrival = getArrivalCount(airport);
    addIntToken(out, passengerArrival);

    int passengerDeparture = getDepartureCount(airport);
    addIntToken(out, passengerDeparture);
    addToken(out, "\n");
    g_free(name);
    g_free(city);
    g_free(country);
    g_free(type);
  }

  return out;
}
