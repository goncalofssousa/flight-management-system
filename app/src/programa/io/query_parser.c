#include "io/query_parser.h"

// a query é um objeto de dados produzido pelo parser, faz sentido estar aqui
struct query {
    int q;
    int n_args;
    char args[3][100];
    char separador; 
};


int getCommand(Query *q) {
    return q->q;
}

int getNargs(Query *q) {
    return q->n_args;
}

char *getArg(Query *q, int index) {
    if (index < 0 || index >= q->n_args) {
        return NULL;
    }
    return g_strdup(q->args[index]); 
}

char getSeparador(Query *q) {
    return q->separador;
}

void parse_query_line(char *linha, Query *query) {
    char *ptr = linha;
    char *token = strsep(&ptr, " ");

    query->q = atoi(token);
    if(strchr(token, 'S') != NULL){
        query->separador = '=';
    }
    else query->separador = ';'; 
    query->n_args = 0;

    if (query->q == 6) {
        if (ptr) {
            g_strlcpy(query->args[0], ptr, 100);
            query->n_args = 1;
        }
    } else {
        while ((token = strsep(&ptr, " ")) != NULL && query->n_args < 3) {
            if (*token != '\0') {
                g_strlcpy(query->args[query->n_args++], token, 100);
            }
        }
    }
}

Query *query_new() {
    Query *q = malloc(sizeof(struct query));
    return q;
}

void query_free(Query *q) {
    free(q);
}
