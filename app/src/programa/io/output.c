#include "io/output.h"

struct output{
    char **tokens;
    int count;
    int capacity;
} ;

int NFiles = 1; 

int closeFile(FILE *f) {
  if (f == NULL)
    return 1;
  fclose(f);
  return 0;
}

FILE *createErrorFile(char *header) {
  char *outputPath = g_strdup_printf("./resultados/%s_errors.csv", header);
  FILE *f = fopen(outputPath, "w");
  free(outputPath);
  return f;
}

FILE *createOutputFile() {
  char *outputPath = g_strdup_printf("./resultados/command%d_output.txt", NFiles);
  FILE *f = fopen(outputPath, "w");
  free(outputPath);
  return f;
}

Output *createOutput() {
    Output *out = malloc(sizeof(Output));
    out->count = 0;
    out->capacity = 8;
    out->tokens = malloc(sizeof(char*) *out->capacity);
    return out;
}

void addToken(Output *out, char *token) {
    if (out->count == out->capacity) {
        out->capacity *= 2;
        out->tokens = realloc(out->tokens, sizeof(char*) * out->capacity);
    }
    out->tokens[out->count++] = g_strdup(token);
}

void addIntToken(Output *out, int value) {
    char *v = g_strdup_printf("%d", value);
    addToken(out, v);
    g_free(v);
}

void writeOutput(Output *out, char separador, int flag){
    if(flag){
        FILE *f = createOutputFile();
        NFiles++; 
        if (out->count == 0) {
            fprintf(f, "\n");
            closeFile(f);
            return;
        }
        for (int i = 0; i < out->count; i++) {
            fprintf(f, "%s", out->tokens[i]);
            if (i+1 < out->count) {
                if(strcmp(out->tokens[i], "\n") != 0 && strcmp(out->tokens[i+1],"\n") != 0) {
                    char sepStr[2] = { separador, '\0' };
                    fprintf(f, "%s", sepStr);  
                }
            }
        }
        closeFile(f);
    }
    else{
        printf("Output: "); 
        if(out->count == 0){
            printf("Nenhum encontrado\n"); 
            return; 
        }
        for (int i = 0; i < out->count; i++) {
            printf("%s", out->tokens[i]);
            if (i+1 < out->count) {
                if(strcmp(out->tokens[i], "\n") != 0 && strcmp(out->tokens[i+1],"\n") != 0) {
                    char sepStr[2] = { separador, '\0' };
                    printf("%s", sepStr);  
                }
            }
        }
        
    }
}

void freeOutput(Output *out) {
    for (int i = 0; i < out->count; i++)
        g_free(out->tokens[i]);

    free(out->tokens);
    free(out);
}