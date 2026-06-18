#include "parser/dataset_reader.h"
#include "io/interpreter.h"
#include "io/query_file.h"
#include "managers/managerGlobal.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Ficheiros Insuficientes");
    return 1;
  }
  ManagerGlobal *global = allocateManagerGlobal();
  initManager(global);
  readDatasetPath(argv[1], global);
  readQueryFileInput(argv[2], global);
  freeAll(global);
  return 0;
}
