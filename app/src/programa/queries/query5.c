#include "queries/query5.h"
#include "io/output.h"
#include "entity/aircraftFlightDelay.h"

Output *query5(int N, ManagerGlobal *global) {
  Output *out = createOutput();
  ManagerFlights *manFlights = getFlightManager(global);
  for (int i = 0; i < N; i++) {
    char *airlineCode = getAirlineByIndex(manFlights, i);
    if (airlineCode == NULL) break;
    FlighDelay *delay = getAirlineDelay(manFlights, airlineCode);
    double avgDelay = getAirlineAvgDelay(delay);
    int flightCount = getAirlineFlightCount(delay);
    char buf2[12];
    snprintf(buf2, sizeof(buf2), "%.3f", avgDelay);
    addToken(out, airlineCode);
    addIntToken(out, flightCount);
    addToken(out, buf2);
    addToken(out, "\n");
  }
  return out;
}
