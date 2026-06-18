#include "io/query_file.h"

int readQueryFileInput(char *path, ManagerGlobal *manager) {
    if (!path) return 1;

    FILE *f = fopen(path, "r");
    if (!f) return 1;

    char linha[1024];    

    while (fgets(linha, sizeof(linha), f)) { 
        linha[strcspn(linha, "\n")] = '\0';
        if (linha[0] == '\0') continue;
        interpret_query(linha,manager, 1);
    }
    fclose(f);
    return 0;
}