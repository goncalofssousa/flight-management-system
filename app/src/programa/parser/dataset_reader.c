#include "parser/dataset_reader.h"

int readDatasetPath(char *path, ManagerGlobal *global) {
    char filepath[512];
    FILE *f = NULL, *ferror = NULL;                       
    snprintf(filepath, sizeof(filepath), "%s/airports.csv", path);
    f = fopen(filepath, "r");
    if (!f){return 1;}
    ferror = createErrorFile("airports");
    readFile(filepath, addAirport, ferror, global);
    closeFile(ferror);
    fclose(f); 

    snprintf(filepath, sizeof(filepath), "%s/aircrafts.csv", path);
    f = fopen(filepath, "r");
    if (!f) return 1;
    ferror = createErrorFile("aircrafts");
    readFile(filepath, addAircraft, ferror, global);
    closeFile(ferror);
    fclose(f);

    snprintf(filepath, sizeof(filepath), "%s/flights.csv", path);
    f = fopen(filepath, "r");
    if (!f) return 1;
    ferror = createErrorFile("flights");
    readFile(filepath, addFlight, ferror, global);
    ManagerAircrafts *aircrafts = getAircraftManager(global); 
    ManagerFlights *flights = getFlightManager(global); 
    ManagerAirports *airports = getAirportManager(global); 
    arraysAircraftSort(aircrafts); 
    sortAirlineDelays(flights);
    sortAllHashTables(airports); 
    closeFile(ferror);
    fclose(f);

    snprintf(filepath, sizeof(filepath), "%s/passengers.csv", path);
    f = fopen(filepath, "r");
    if (!f) return 1;
    ferror = createErrorFile("passengers");
    readFile(filepath, addPassenger, ferror, global);
    closeFile(ferror);
    fclose(f);
    snprintf(filepath, sizeof(filepath), "%s/reservations.csv", path);
    f = fopen(filepath, "r");
    if (!f) return 1;
    ferror = createErrorFile("reservations");
    readFile(filepath, addReservation, ferror, global);
    closeFile(ferror);
    fclose(f);
    return 0;
}
