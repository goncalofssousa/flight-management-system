#include "utils/geral.h"
#include <stdio.h>

const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void splitString(char *line, char columns[][MAX_STRING], int *N) {
  int found = 0;
  int i, j = 0;
  for (i = 0; line[i] != '\0'; i++) {
    if ((line[i] == ',' && !found) || (line[i] == '\"' && found)) {
      columns[(*N)++][j] = '\0';
      j = 0;
      found = 0;
      if (line[i] == '\"')
        i++;
    } else if (line[i] == '\"') {
      if (!found) {
        found = 1;
      }
    } else
      columns[(*N)][j++] = line[i];
  }
  if (j > 0) {
    columns[(*N)++][j] = '\0';
  }
}

void consoleMessage(char *message) {
    int ret = system("clear"); 
    if (ret == -1) perror("system");  
    printf("%s\n", message);
    getchar();
}

int getSundayDate(char *date) {
  int y, m, d;
  sscanf(date, "%d-%d-%d", &y, &m, &d);

  int Y = y;
  int M = m;
  if (M < 3) {
    M += 12;
    Y -= 1;
  }
  int K = Y % 100;
  int J = Y / 100;
  int w = (d + 13 * (M + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
  w = (w + 6) % 7;

  d -= w;

  while (d <= 0) {
    m -= 1;
    if (m == 0) {
      m = 12;
      y -= 1;
    }
    int dim = days_in_month[m - 1];
    if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
      dim++;
    d += dim;
  }

  return y * 10000 + m * 100 + d;
}

int getSundayDateInt(int dateInt) {
    int y = dateInt / 10000;
    int m = (dateInt / 100) % 100;
    int d = dateInt % 100;

    int Y = y;
    int M = m;
    if (M < 3) {
        M += 12;
        Y -= 1;
    }
    int K = Y % 100;
    int J = Y / 100;

    int w = (d + 13 * (M + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    w = (w + 6) % 7; 

    d -= w; 

    while (d <= 0) {
        m -= 1;
        if (m == 0) {
            m = 12;
            y -= 1;
        }
        int dim = days_in_month[m - 1];
        if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))) {
            dim++; 
        }
        d += dim;
    }

    return y * 10000 + m * 100 + d;
}

int getIntDate(char *date){
  int y, m,d; 
  sscanf(date, "%d-%d-%d", &y,&m,&d); 
  int dateTime = y * 10000 + m *100 + d; 
  return dateTime; 
}


void hashTableToSorterArray(GHashTable *table, GArray *arr) {
  GHashTableIter iter;
  gpointer key, value;
  g_hash_table_iter_init(&iter, table);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    g_array_append_val(arr, key);
  }
}

double calculateDelay(char *predicted, char *real) {
  int p_m, p_d, p_h, p_min, r_m, r_d, r_h, r_min;
  sscanf(predicted, "%*d-%d-%d %d:%d", &p_m, &p_d, &p_h, &p_min);
  sscanf(real, "%*d-%d-%d %d:%d", &r_m, &r_d, &r_h, &r_min);
  int days = r_d - p_d;
  days = days ? days - 1 : 0;
  int hours = r_h - p_h;
  int minutes = r_min - p_min;

  if (p_m != r_m) {
    days = days_in_month[p_m - 1] - p_d + r_d;
    days--;
  }
  if (p_m != r_m || p_d != r_d) {
    hours = (24 - p_h - 1) + r_h;
    minutes = 60 - p_min + r_min;
  }
  return days * 24 * 60 + hours * 60 + minutes;
}

