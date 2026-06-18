#include "parser/dataset_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile(char *path, int (*processLine)(char[][MAX_STRING], FILE *, char *,ManagerGlobal *global),
             FILE *errorFile, ManagerGlobal *global) {
  if (path == NULL || processLine == NULL) {
    return 1;
  }
  FILE *f = fopen(path, "r");
  char linha[1024];
  char columns[100][MAX_STRING];
  int N = 0;
  while (fgets(linha, sizeof(linha), f)) {
    N = 0;
    splitString(linha, columns, &N); 
    processLine(columns, errorFile, linha,global);
  }
  fclose(f);
  return 0;
}
