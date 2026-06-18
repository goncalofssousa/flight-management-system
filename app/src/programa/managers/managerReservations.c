#include "managers/managerReservations.h"
#include "geral.h"
#include "glib.h"
#include <string.h>

struct manager {
  GTree *weeks;
  char *all;
  int count;
  int lastWeek;
  GTreeNode *lastWeekNode;
};

struct weekData {
  GHashTable *passengerTotals;
  GArray *top10;
  gboolean dirty;
};

int compareAllTop(const void *a, const void *b, gpointer user_data) {
  GHashTable *order = (GHashTable *)user_data;
  char *pa = *(char **)a;
  char *pb = *(char **)b;

  void *va = g_hash_table_lookup(order, pa);
  void *vb = g_hash_table_lookup(order, pb);

  int ca = GPOINTER_TO_INT(va);
  int cb = GPOINTER_TO_INT(vb);

  if (ca < cb)
    return 1;
  if (ca > cb)
    return -1;
  return atoi(pa) - atoi(pb);
}

int compareTop(const void *a, const void *b, gpointer user_data) {
  WeekData *week = (WeekData *)user_data;
  char *pa = *(char **)a;
  char *pb = *(char **)b;

  double *va = g_hash_table_lookup(week->passengerTotals, pa);
  double *vb = g_hash_table_lookup(week->passengerTotals, pb);

  if (*va < *vb)
    return 1;
  if (*va > *vb)
    return -1;

  int idA = atoi(pa);
  int idB = atoi(pb);
  return idA - idB;
}

int compareInt(gconstpointer a, gconstpointer b, gpointer user_data) {
  (void)user_data;
  int wa = GPOINTER_TO_INT(a);
  int wb = GPOINTER_TO_INT(b);
  return (wa > wb) - (wa < wb);
}

ManagerReservations *initReservations() {
    ManagerReservations *manReservations = malloc(sizeof(ManagerReservations));
    manReservations->weeks = g_tree_new_full(compareInt, NULL,
                                             NULL, (GDestroyNotify)freeWeekData);
    manReservations->all = NULL;
    return manReservations;
}

WeekData *initWeekData() {
  WeekData *wd = malloc(sizeof(WeekData));
  wd->passengerTotals =
      g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free);
  wd->top10 = g_array_new(FALSE, FALSE, sizeof(char *));
  wd->dirty = FALSE;
  return wd;
}

gboolean foreach_tree(int a, WeekData *value, GHashTable *order) { 
  a = FALSE; 
  updateTop10(value, order);
  return a;
}

GArray *getArrayTop10(ManagerReservations *manReservations) {
  if (!manReservations->lastWeekNode)
    return NULL;

  WeekData *week = g_tree_node_value(manReservations->lastWeekNode);

  if (!week)
    return NULL;

  updateTop10(week, NULL);

  return week->top10;
}

void setArrayDate(ManagerReservations *manReservations, int intDate) {
  gpointer date = GINT_TO_POINTER(intDate);
  GTreeNode *n = g_tree_lookup_node(manReservations->weeks, date);
  manReservations->lastWeek = intDate;
  manReservations->lastWeekNode = n;
}

int getNextDate(ManagerReservations *manReservations, int endDate) {
  if (!manReservations->lastWeekNode)
    return 0;
  manReservations->lastWeekNode =
      g_tree_node_next(manReservations->lastWeekNode);
  if (manReservations->lastWeekNode)
    manReservations->lastWeek =
        GPOINTER_TO_INT(g_tree_node_key(manReservations->lastWeekNode));
  if (manReservations->lastWeek > endDate)
    return 0;
  return 1;
}

char *getIdFromArrayIndex(GArray *arr, int index) {
  return g_array_index(arr, char *, index);
}

gboolean foreachTreeWrapper(gpointer key, gpointer value, gpointer user_data) {
    int week = GPOINTER_TO_INT(key);
    WeekData *data = (WeekData *)value;
    GHashTable *order = (GHashTable *)user_data;
    return foreach_tree(week, data, order);
}

char *getIdFromAllTime(ManagerReservations *manReservations) {
  if (!manReservations->all) {
    GHashTable *order =
        g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    GArray *arr = g_array_new(FALSE, FALSE, sizeof(char *));
    g_tree_foreach(manReservations->weeks, foreachTreeWrapper, order);

    hashTableToSorterArray(order, arr);
    g_array_sort_with_data(arr, compareAllTop, order);

      if (arr->len > 0) {          
      char *topId = g_array_index(arr, char *, 0);
      manReservations->all = malloc(strlen(topId) + 1);
      strcpy(manReservations->all, topId);
      manReservations->count =
          GPOINTER_TO_INT(g_hash_table_lookup(order, topId));
    }

    g_array_free(arr, TRUE);
    g_hash_table_destroy(order);
  }
  return manReservations->all;
}

int getCountFromAllTime(ManagerReservations *manReservations) {
  if (manReservations->all)
    return manReservations->count;
  return -1;
}

void insertReservationByWeek(ManagerReservations *manReservations, int intDate,
                             char *passengerId, double value) {
  gpointer *date = GINT_TO_POINTER(intDate);

  WeekData *week = g_tree_lookup(manReservations->weeks, date);
  if (!week) {
    week = initWeekData();
    g_tree_insert(manReservations->weeks, date, week);
  }

  double *curr = g_hash_table_lookup(week->passengerTotals, passengerId);
  if (!curr) {
    double *v = malloc(sizeof(double));
    *v = value;
    g_hash_table_insert(week->passengerTotals, g_strdup(passengerId), v);
  } else {
    *curr += value;
  }
}

void updateTop10(WeekData *week, GHashTable *order) {
  if (!week || week->dirty)
    return;

  GArray *arr = g_array_new(FALSE, FALSE, sizeof(char *));

  hashTableToSorterArray(week->passengerTotals, arr);
  g_array_sort_with_data(arr, compareTop, week);
  g_array_set_size(week->top10, 0);

  int n = arr->len < 10 ? arr->len : 10;
  for (int i = 0; i < n; i++) {
    char *pid = g_array_index(arr, char *, i);
    g_array_append_val(week->top10, pid);
    if (order) {
      void *value = g_hash_table_lookup(order, pid);
      if (!value) {
        g_hash_table_insert(order, g_strdup(pid), GINT_TO_POINTER(1));
      } else {
        int count = GPOINTER_TO_INT(value);
        g_hash_table_replace(order, g_strdup(pid), GINT_TO_POINTER(count + 1));
      }
    }
  }

  g_array_free(arr, TRUE);

  week->dirty = TRUE;
}

void freeWeekData(WeekData *week) {
  if (!week)
    return;
  g_hash_table_destroy(week->passengerTotals);
  g_array_free(week->top10, TRUE);
  free(week);
}

void freeAllReservations(ManagerReservations *manReservations) {
  if (!manReservations)
    return;
  g_tree_destroy(manReservations->weeks);
  if (manReservations->all)
    free(manReservations->all);
  free(manReservations);
}