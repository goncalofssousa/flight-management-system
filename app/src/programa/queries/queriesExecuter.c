#include "queries/queriesExecuter.h"
#include "io/query_parser.h"

Output *execute_query(Query *query, ManagerGlobal *manager) {
  Output *out = NULL;
  switch (getCommand(query)) {
  case 1:{
    char *arg = getArg(query, 0); 
    out = query1(arg, manager);
    g_free(arg); 
    break;
  }
  case 2:{
    char *arg1 = getArg(query,0); 
    char *arg2 = getArg(query,1); 
    out = query2(atoi(arg1),  getNargs(query) == 1 ? NULL : arg2, manager);
    g_free(arg1); 
    g_free(arg2); 
    break;
  }
  case 3:{
    char *arg1 = getArg(query, 0); 
    char *arg2 = getArg(query, 1); 
    out = query3(arg1, arg2, manager);
    g_free(arg1); 
    g_free(arg2); 
    break;
  }
  case 4:{
    char *arg1 = getArg(query,0); 
    char *arg2 = getArg(query,1); 
    out = query4(arg1, arg2, manager);
    g_free(arg1); 
    g_free(arg2); 
    break;
  }
  case 5:{
    char *arg1 = getArg(query,0); 
    out = query5(atoi(arg1), manager);
    g_free(arg1); 
    break;
  }
  case 6:{
    char *arg1 = getArg(query,0); 
    out = query6(arg1, manager);
    g_free(arg1); 
    break;
  }
  default:
    return NULL;
  }
  return out; 
}
