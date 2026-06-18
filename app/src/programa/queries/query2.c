#include "queries/query2.h"
#include "managers/managerGlobal.h"
#include <glib.h>


Output *query2(int numAircrafts, const char *manufacturer, ManagerGlobal *manager) { 
    ManagerAircrafts *manAircrafts = getAircraftManager(manager); 
    Output *out = createOutput();   
    int flag = 0;

    for (int i = 0; i < numAircrafts; i++) {
        const Aircraft *aircraft = processArrayResult(manAircrafts, manufacturer, i); 

        if (aircraft) {
            char *id = getIdAircraft(aircraft); 
            char *manuf = getManufacter(aircraft);   
            char *model = getModel(aircraft);       
            int numFlights = getNumFlights(aircraft);

            addToken(out, id);
            addToken(out, manuf);
            addToken(out, model);
            addIntToken(out, numFlights);
            addToken(out, "\n");
            
            g_free(id);
            g_free(manuf);
            g_free(model);
        } else {
            flag = 1;
        }
    }
    
    if (!numAircrafts || flag) {
        addToken(out, "\n");  
    }

    return out;
}