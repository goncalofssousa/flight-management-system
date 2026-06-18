#include"io/read_input_interactive.h"

int main(){
    ManagerGlobal *global = allocateManagerGlobal(); 
    initManager(global); 
    readDatasetPathIO(global);
    readQueryInteractive(global);
    freeAll(global); 
    return 0; 
}