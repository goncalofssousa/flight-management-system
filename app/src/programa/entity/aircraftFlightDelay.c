#include "entity/aircraftFlightDelay.h"
#include "managers/managerFlights.h"
#include <math.h>

struct flighDelay {
  int avgDelay;
  double totalDelay;
  int flightCount;
};

FlightDelay *createFlightDelay(int delay, int flights){
    FlighDelay *newDelay =malloc(sizeof(FlighDelay));
    newDelay->totalDelay = delay;
    newDelay->flightCount = flights;
    return newDelay; 
}; 

double getAirlineAvgDelay(FlighDelay *delay) {
  return (double)delay->avgDelay / 1000;
}

int getAirlineFlightCount(FlighDelay *delay) { return delay->flightCount; }

void addFlightDelay(FlightDelay *currentDelay, double delay){
    currentDelay->totalDelay += delay;
} 
void incFlightCountToDelay(FlightDelay *currentDelay){
    currentDelay->flightCount++; 
}

void addAvgDelay(FlightDelay *value){
    value->avgDelay = round(value->totalDelay / value->flightCount * 1000);
}

int getAvgDelay(FlighDelay *value){
    return value->avgDelay; 
}