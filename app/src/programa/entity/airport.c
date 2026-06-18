#include "entity/airport.h"

typedef enum {
  SMALL_AIRPORT,
  MEDIUM_AIRPORT,
  LARGE_AIRPORT,
  HELIPORT,
  SEAPLANE_BASE
} AirportType;

struct airport {
  char *code;
  char *name;
  char *city;
  char *country;
  int passengerDeparture;
  int passengerArrival;
  AirportType type;
  GHashTable *datas; 
  GArray *datasOrd; 
};

struct dateCount{
  int date; 
  int count; 
}; 

char *getCode(const Airport *airport) { 
  if(airport) return g_strdup(airport->code); 
  return NULL; 
}

char *getType(const Airport *airport) {
  switch (airport->type) {
  case SMALL_AIRPORT:
    return g_strdup("small_airport");
  case MEDIUM_AIRPORT:
    return g_strdup("medium_airport");
  case LARGE_AIRPORT:
    return g_strdup("large_airport");
  case HELIPORT:
    return g_strdup("heliport");
  case SEAPLANE_BASE:
    return g_strdup("seaplane_base");
  default:
    return g_strdup("unknown");
  }
}

char *getName(const Airport *airport) { return g_strdup(airport->name); }

char *getCity(const Airport *airport) { return g_strdup(airport->city); }

char *getCountry(const Airport *airport) { return g_strdup(airport->country); }


int getArrivalCount(const Airport *airport){return airport->passengerArrival;}

int getDepartureCount(const Airport *airport){return airport->passengerDeparture;}


void incPassengerDeparture(Airport *a){
  a->passengerDeparture++; 
};

void incPassengerArrival(Airport *a){
  a->passengerArrival++; 
};

void setType(Airport *airport, char *type) {
  if (g_strcmp0(type, "small_airport") == 0)
    airport->type = SMALL_AIRPORT;
  else if (g_strcmp0(type, "medium_airport") == 0)
    airport->type = MEDIUM_AIRPORT;
  else if (g_strcmp0(type, "large_airport") == 0)
    airport->type = LARGE_AIRPORT;
  else if (g_strcmp0(type, "heliport") == 0)
    airport->type = HELIPORT;
  else if (g_strcmp0(type, "seaplane_base") == 0)
    airport->type = SEAPLANE_BASE;
}

void incFlightDateCount(Airport *a, int date){
  gpointer val = g_hash_table_lookup(a->datas, GINT_TO_POINTER(date)); 
  int valor = val ? GPOINTER_TO_INT(val) : 0; 
  valor++; 
  g_hash_table_insert(a->datas, GINT_TO_POINTER(date), GINT_TO_POINTER(valor)); 
}

gint compareDate(gconstpointer a, gconstpointer b){
  const struct dateCount *dc1 = a; 
  const struct dateCount *dc2 = b;
  if(dc1->date > dc2->date) return 1; 
  else if(dc1->date < dc2->date) return -1;
  else return 0;  
}

void hashTableToSortArrayAirports(Airport *a){
  GHashTableIter iter;
  gpointer key, value;
  g_hash_table_iter_init(&iter, a->datas);
  g_array_set_size(a->datasOrd, 0);
  while (g_hash_table_iter_next(&iter, &key, &value)){
    struct dateCount dc; 
    dc.date = GPOINTER_TO_INT(key); 
    dc.count = GPOINTER_TO_INT(value); 
    g_array_append_val(a->datasOrd, dc); 
  }
  g_array_sort(a->datasOrd, compareDate); 
  int len = a->datasOrd->len; 
  for(int i = 1; i < len; i++){
    struct dateCount *atual = &g_array_index(a->datasOrd, struct dateCount, i);
    struct dateCount *ant = &g_array_index(a->datasOrd, struct dateCount, i - 1);
    atual->count += ant->count; 
  }
}

int upper_bound_date(GArray *arr, int date) {
    int left = 0;
    int right = arr->len;  

    while (left < right) {
        int mid = (left + right) / 2;
        struct dateCount *dc = &g_array_index(arr, struct dateCount, mid);

        if (dc->date <= date)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int getCountFromDateInterval(int date1, int date2, Airport *a) {
    if (a->datasOrd->len == 0) return 0;

    int i2 = upper_bound_date(a->datasOrd, date2);
    int i1 = upper_bound_date(a->datasOrd, date1 - 1);

    int prefixEnd = (i2 > 0) ? g_array_index(a->datasOrd, struct dateCount, i2 - 1).count : 0;
    int prefixStart = (i1 > 0) ? g_array_index(a->datasOrd, struct dateCount, i1 - 1).count: 0;

    return prefixEnd - prefixStart;
}

Airport *allocateAirport(char *code, char *name, char *city, char *country, char *type){
  Airport *airport = g_new(Airport, 1);
  airport->code = g_strdup(code);
  airport->name = g_strdup(name);
  airport->city = g_strdup(city);
  airport->country = g_strdup(country);
  airport->passengerDeparture = 0; 
  airport->passengerArrival = 0;  
  setType(airport, type); 
  airport->datas = g_hash_table_new(g_direct_hash, g_direct_equal); 
  airport->datasOrd = g_array_new(FALSE, FALSE, sizeof(struct dateCount));
  return airport; 
}


void freeAirport(Airport *a) {
  if (!a)
    return;

  g_free(a->code);
  g_free(a->name);
  g_free(a->city);
  g_free(a->country);
  g_hash_table_destroy(a->datas); 
  g_array_free(a->datasOrd, TRUE); 
  g_free(a);
}