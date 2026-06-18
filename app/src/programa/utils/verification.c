#include "verification.h"
#include <glib.h>

int verifyDate(char *date) {
  if (!date)
    return 1;

  if(strcmp(date, "N/A") == 0) return 0; 

  if (!isdigit(date[0]))
    return 1;
  if (!isdigit(date[1]))
    return 1;
  if (!isdigit(date[2]))
    return 1;
  if (!isdigit(date[3]))
    return 1;
  if (date[4] != '-')
    return 1;

  if (!isdigit(date[5]) || !isdigit(date[6]))
    return 1;
  if (date[7] != '-')
    return 1;

  if (!isdigit(date[8]) || !isdigit(date[9]))
    return 1;
  if (date[10] != ' ')
    return 1;

  if (!isdigit(date[11]) || !isdigit(date[12]))
    return 1;
  if (date[13] != ':')
    return 1;

  if (!isdigit(date[14]) || !isdigit(date[15]))
    return 1;
  if (date[16] != '\0')
    return 1;

  int month = (date[5] - '0') * 10 + (date[6] - '0');
  if (month < 1 || month > 12)
    return 1;

  int day = (date[8] - '0') * 10 + (date[9] - '0');
  if (day < 1 || day > 31)
    return 1;

  int hour = (date[11] - '0') * 10 + (date[12] - '0');
  if (hour < 0 || hour > 23)
    return 1;

  int minute = (date[14] - '0') * 10 + (date[15] - '0');
  if (minute < 0 || minute > 59)
    return 1;

  return 0;
}

int verifyDOB(char *date) {
  if (!date)
    return 1;
  if (!isdigit(date[0]))
    return 1;
  if (!isdigit(date[1]))
    return 1;
  if (!isdigit(date[2]))
    return 1;
  if (!isdigit(date[3]))
    return 1;
  if (date[4] != '-')
    return 1;
  if (!isdigit(date[5]) || !isdigit(date[6]))
    return 1;
  if (date[7] != '-')
    return 1;
  if (!isdigit(date[8]) || !isdigit(date[9]))
    return 1;
  if (date[10] != '\0')
    return 1;
  int month = (date[5] - '0') * 10 + (date[6] - '0');
  if (month < 1 || month > 12)
    return 1;

  int day = (date[8] - '0') * 10 + (date[9] - '0');
  if (day < 1 || day > 31)
    return 1;
  return 0;
}


int verifyLatitude(char *coord) {
    int i = 0;
    int dot_count = 0;
    int digits_after_dot = 0;

    if (coord[i] == '-') i++;  
    
    if (!isdigit(coord[i])) return 1;

    while (coord[i] != '\0') {
        if (isdigit(coord[i])) {
            if (dot_count) digits_after_dot++;
        } else if (coord[i] == '.') {
            dot_count++;
            if (dot_count > 1) return 1; 
        } else {
            return 1; 
        }
        i++;
    }

    if (digits_after_dot > 8) return 1; 

    double latitude = atof(coord);
    if (latitude < -90.0 || latitude > 90.0) return 1; 

    return 0; 
}

int verifyLongitude(char *coord) {
    int i = 0;
    int dot_count = 0;
    int digits_after_dot = 0;

    if (coord[i] == '-') i++;  
    
    if (!isdigit(coord[i])) return 1;

    while (coord[i] != '\0') {
        if (isdigit(coord[i])) {
            if (dot_count) digits_after_dot++;
        } else if (coord[i] == '.') {
            dot_count++;
            if (dot_count > 1) return 1; 
        } else {
            return 1; 
        }
        i++;
    }

    if (digits_after_dot > 8) return 1; 

    double latitude = atof(coord);
    if (latitude < -180.0 || latitude > 180.0) return 1; 

    return 0; 
}


int verifyAirport(char *code) {
  if (code[0] < 'A' && code[0] > 'Z')
    return 1;
  if (code[1] < 'A' && code[1] > 'Z')
    return 1;
  if (code[2] < 'A' && code[2] > 'Z')
    return 1;
  if (code[3] != '\0')
    return 1;
  return 0;
}

int verifyFlightId(char *code) {
  if (code[0] < 'A' && code[0] > 'Z')
    return 1;
  if (code[1] < 'A' && code[1] > 'Z')
    return 1;
  if (!isdigit(code[2]))
    return 1;
  if (!isdigit(code[3]))
    return 1;
  if (!isdigit(code[4]))
    return 1;
  if (!isdigit(code[5]))
    return 1;
  if (!isdigit(code[6]))
    return 1;
  if (!isdigit(code[7])) {
    if (code[7] == '\0')
      return 0;
    return 1;
  }
  if (code[8] != '\0') {
    return 1;
  }
  return 0;
}

int verifyReservation(char *reservation) {
  if (reservation[0] != 'R')
    return 1;
  if (!isdigit(reservation[1]))
    return 1;
  if (!isdigit(reservation[2]))
    return 1;
  if (!isdigit(reservation[3]))
    return 1;
  if (!isdigit(reservation[4]))
    return 1;
  if (!isdigit(reservation[5]))
    return 1;
  if (!isdigit(reservation[6]))
    return 1;
  if (!isdigit(reservation[7]))
    return 1;
  if (!isdigit(reservation[8]))
    return 1;
  if (!isdigit(reservation[9]))
    return 1;
  if (reservation[10] != '\0')
    return 1;
  return 0;
}


int verifyEmail(char *email){
  int arroba = 0; 
  int dot = 0; 
  int numBeforeArroba = 0; 
  int numAfterArrobaBeforeDot = 0; 
  int numAfterArrobaAfterDot = 0; 
  int i = 0; 
  while(email[i] != '\0'){
    if(((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= '0' && email[i] <= '9') || email[i] == '.') && !arroba) numBeforeArroba++; 

    else if(email[i] == '@' && !arroba) arroba = 1; 
    else if(email[i] >= 'a' && email[i] <= 'z' && arroba && !dot) numAfterArrobaBeforeDot++;

    else if(arroba && email[i] == '.' && !dot) dot = 1; 
    else if(email[i] >= 'a' && email[i] <= 'z' && arroba && dot) numAfterArrobaAfterDot++; 
    else return 1; 
    i++; 
  }
  if(!arroba || !dot || !numBeforeArroba || numAfterArrobaBeforeDot == 0 || numAfterArrobaAfterDot < 2 || numAfterArrobaAfterDot > 3) return 1;
  return 0; 
}

int verifyDocument(char *document) {
  if (!isdigit(document[0]))
    return 1;
  if (!isdigit(document[1]))
    return 1;
  if (!isdigit(document[2]))
    return 1;
  if (!isdigit(document[3]))
    return 1;
  if (!isdigit(document[4]))
    return 1;
  if (!isdigit(document[5]))
    return 1;
  if (!isdigit(document[6]))
    return 1;
  if (!isdigit(document[7]))
    return 1;
  if (!isdigit(document[8]))
    return 1;
  if (document[9] != '\0')
    return 1;
  return 0;
}

int verifyOriginDest(char *origin, char *dest) {
  if (verifyAirport(origin) || verifyAirport(dest) ||
      g_strcmp0(origin, dest) == 0) {
    return 1;
  }
  return 0;
}

int verifyYear(char *year) {
  if (!isdigit(year[0]))
    return 1;
  if (!isdigit(year[1]))
    return 1;
  if (!isdigit(year[2]))
    return 1;
  if (!isdigit(year[3]))
    return 1;
  if (year[4] != '\0')
    return 1;
  int y = atoi(year);
  GDateTime *actual = g_date_time_new_now_local();
  int currentYear = g_date_time_get_year(actual);
  g_date_time_unref(actual);
  if (y > currentYear)
    return 1;

  return 0;
}

int verifyType(char *type) {
  if (g_strcmp0(type, "small_airport") == 0) {
    return 0;
  } else if (g_strcmp0(type, "medium_airport") == 0) {
    return 0;
  } else if (g_strcmp0(type, "large_airport") == 0) {
    return 0;
  } else if (g_strcmp0(type, "heliport") == 0) {
    return 0;
  } else if (g_strcmp0(type, "seaplane_base") == 0) {
    return 0;
  }
  return 1;
}

int verifyStateFlight(char *state) {
  if (g_strcmp0(state, "On Time") == 0) {
    return 0;
  } else if (g_strcmp0(state, "Delayed") == 0) {
    return 0;
  } else if (g_strcmp0(state, "Cancelled") == 0) {
    return 0;
  }
  return 1;
}

int verifyAcs(char *date1, char *date2) {
  if (strcmp(date1, date2) > 0)
    return 1;
  return 0;
}

int verifyGender(char *gender) {
  if (g_strcmp0(gender, "M") == 0)
    return 0;
  else if (g_strcmp0(gender, "F") == 0)
    return 0;
  else if (g_strcmp0(gender, "O") == 0)
    return 0;
  else
    return 1;
}

int verifyQueryCommand(char *query) {
  if (query[0] != 'q' && (query[0] < '1' || query[0] > '6'))
    return 1;

  if (query[1] == '\0')
    return 0;

  if (query[1] == 'S' && query[2] == '\0')
    return 0;

  return 1;
}
