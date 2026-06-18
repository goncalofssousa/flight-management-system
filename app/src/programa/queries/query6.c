#include "queries/query6.h"
#include "managers/managerGlobal.h"
#include <glib.h>

Output *query6(char *nacionality, ManagerGlobal *manager) {
   Output *out = createOutput();
   if (!nacionality || !manager) {
       return out;
   }

    ManagerPassengers *manPassengers = getPassengerManager(manager);
    char *code = getCodeNacionality(manPassengers, nacionality); 
    if(code != NULL){
        int max = getMaxNacionality(manPassengers, nacionality); 
        addToken(out, code);
        addIntToken(out, max);
        addToken(out,"\n"); 
        g_free(code); 
    }
   return out;
}
