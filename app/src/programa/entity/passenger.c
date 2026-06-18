#include "entity/passenger.h"


struct passenger {
  char *documentnumber;
  char *firstName;
  char *lastName;
  char *dob;
  char *nacionality;
};

char *getPassengerFirstName(const Passenger *p) { return g_strdup(p->firstName); }
char *getPassengerLastName(const Passenger *p) { return g_strdup(p->lastName); }
char *getPassengerDOB(const Passenger *p) { return g_strdup(p->dob); }
char *getPassengerNacionality(const Passenger *p) { return g_strdup(p->nacionality); }

Passenger *allocatePassenger(char *documentNumber, char *firstName, char *lastName, char *dob, char *nacionality) {
  Passenger *passenger = g_new(Passenger, 1);
  passenger->documentnumber = g_strdup(documentNumber);
  passenger->firstName = g_strdup(firstName);
  passenger->lastName = g_strdup(lastName);
  passenger->dob = g_strdup(dob);
  passenger->nacionality = g_strdup(nacionality);
  return passenger;
}

void freePassenger(Passenger *p) {
  if (!p)
    return;

  g_free(p->documentnumber);
  g_free(p->firstName);
  g_free(p->lastName);
  g_free(p->dob);
  g_free(p->nacionality);

  g_free(p);
}