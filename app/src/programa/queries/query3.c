#include "queries/query3.h"
#include "managers/managerAirports.h"
#include "managers/managerGlobal.h"
#include <glib.h>


Output *query3(char *dateIn, char *dateFin, ManagerGlobal *manager) {
    ManagerAirports *manAirports = getAirportManager(manager); 
    Output *out = createOutput();  
    if (!dateIn || !dateFin) {
        return out;
    }
    int date1Int = getIntDate(dateIn); 
    int date2Int = getIntDate(dateFin);
    AirportInfo *info = getMaxFromDateInterval(manAirports, date1Int, date2Int); 
    if (info) {
        char *code = getCodeFromAirportInfo(info); 
        int numFlights = getNumFlightFromAirportInfo(info); 

        if (code != NULL) {
            const Airport *ap = getAirportById(manAirports, code);

            char *name = getName(ap);
            char *city = getCity(ap);
            char *country = getCountry(ap);

            addToken(out, code);
            addToken(out, name);
            addToken(out, city);
            addToken(out, country);
            addIntToken(out, numFlights);
            addToken(out,"\n"); 

            g_free(code);
            g_free(name);
            g_free(city);
            g_free(country);
        } 
        freeAirportInfo(info);
    } 
    return out;
}
