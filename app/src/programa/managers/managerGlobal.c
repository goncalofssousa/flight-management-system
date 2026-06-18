#include "managers/managerGlobal.h"

struct manager {
  GHashTable *managersHash;
};

ManagerGlobal *allocateManagerGlobal() {
  ManagerGlobal *global = g_new0(ManagerGlobal, 1);
  return global;
}

void initManager(ManagerGlobal *manager) {
  manager->managersHash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
  insertManagerAirports(manager);
  insertManagerAircrafts(manager);
  insertManagerFlights(manager);
  insertManagerPassengers(manager);
  insertManagerReservations(manager);
}

void insertManagerAirports(ManagerGlobal *manager) {
  ManagerAirports *airports = initAirports();
  g_hash_table_insert(manager->managersHash, g_strdup("airports"), airports);
}

void insertManagerAircrafts(ManagerGlobal *manager) {
  ManagerAircrafts *aircrafts = initAircrafts();
  g_hash_table_insert(manager->managersHash, g_strdup("aircrafts"), aircrafts);
}

void insertManagerFlights(ManagerGlobal *manager) {
  ManagerFlights *flights = initFlights();
  g_hash_table_insert(manager->managersHash, g_strdup("flights"), flights);
}

void insertManagerPassengers(ManagerGlobal *manager) {
  ManagerPassengers *passengers = initPassengers();
  g_hash_table_insert(manager->managersHash, g_strdup("passengers"),
                      passengers);
}

void insertManagerReservations(ManagerGlobal *manager) {
  ManagerReservations *reservations = initReservations();
  g_hash_table_insert(manager->managersHash, g_strdup("reservations"),
                      reservations);
}

ManagerAirports *getAirportManager(ManagerGlobal *manager) {
  ManagerAirports *airportsMan =
      g_hash_table_lookup(manager->managersHash, "airports");
  return airportsMan;
}

ManagerAircrafts *getAircraftManager(ManagerGlobal *manager) {
  ManagerAircrafts *aircraftsMan =
      g_hash_table_lookup(manager->managersHash, "aircrafts");
  return aircraftsMan;
}

ManagerFlights *getFlightManager(ManagerGlobal *manager) {
  ManagerFlights *flightsMan =
      g_hash_table_lookup(manager->managersHash, "flights");
  return flightsMan;
}

ManagerPassengers *getPassengerManager(ManagerGlobal *manager) {
  ManagerPassengers *passengersMan =
      g_hash_table_lookup(manager->managersHash, "passengers");
  return passengersMan;
}

ManagerReservations *getReservationManager(ManagerGlobal *manager) {
  ManagerReservations *reservationsMan =
      g_hash_table_lookup(manager->managersHash, "reservations");
  return reservationsMan;
}

void freeAll(ManagerGlobal *manager) {
  if (!manager)
    return;
  ManagerAirports *airports = getAirportManager(manager);
  ManagerAircrafts *aircrafts = getAircraftManager(manager);
  ManagerFlights *flights = getFlightManager(manager);
  ManagerPassengers *passengers = getPassengerManager(manager);
  ManagerReservations *reservations = getReservationManager(manager);
  if (airports)
    freeAllAirports(airports);
  if (aircrafts)
    freeAllAircrafts(aircrafts);
  if (flights)
    freeAllFlights(flights);
  if (passengers)
    freeAllPassengers(passengers);
  if (reservations)
    freeAllReservations(reservations);
  g_hash_table_destroy(manager->managersHash);
  g_free(manager);
}
