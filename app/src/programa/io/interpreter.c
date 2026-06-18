#include "io/interpreter.h"
#include "io/output.h"
#include "io/query_parser.h"

int interpret_query(char *line,ManagerGlobal *man,int from_file){
    Query *q = query_new();
    parse_query_line(line, q);
    Output *out = execute_query(q, man);
    if(out){
        writeOutput(out, getSeparador(q), from_file); 
        freeOutput(out); 
    }
    query_free(q);
    return 1;
}

