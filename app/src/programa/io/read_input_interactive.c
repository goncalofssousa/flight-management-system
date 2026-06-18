#include "io/read_input_interactive.h"

int readDatasetPathIO(ManagerGlobal *man){ 
    int flag = 0; 
    char path[512];   
    while(!flag){
        int ret = system("clear");  
        if (ret == -1) perror("system");

        printf("Introduza o caminho dos ficheiros de dados (default: ./dataset): "); 
        if (!fgets(path, sizeof(path), stdin)) {
            perror("fgets");
            continue;
        }
        path[strcspn(path, "\n")] = '\0';  
        if(path[0] == '\0') {
            strcpy(path, "./dataset"); 
        }
        printf("A carregar dataset: %s\n", path);

        int result = readDatasetPath(path, man);  
        if(result) {
            consoleMessage("Caminho invalido, tente novamente"); 
        } else {
            flag = 1; 
        }
    }
    printf("Dataset carregado (enter para continuar)..."); 
    getchar(); 
    return 0; 
}


void readQueryInteractive(ManagerGlobal *man) {
    char query[MAX_QUERY];
    char arg1[MAX_QUERY];
    char arg2[MAX_QUERY];
    int flag1 = 0;

    while (!flag1) {
        int ret = system("clear");
        if (ret == -1) perror("system");

        printf("Que query deseja executar? ");
        if (!fgets(query, MAX_QUERY, stdin)) {
            perror("fgets");
            continue;
        }
        query[strcspn(query, "\n")] = '\0';

        if (!verifyQueryCommand(query)) {
            switch (query[0]) {

                case '1': {
                    while (1) {
                        printf("\nCódigo do aeroporto: ");
                        if (!fgets(arg1, MAX_QUERY, stdin)) {
                            perror("fgets");
                            continue;
                        }
                        arg1[strcspn(arg1, "\n")] = '\0';

                        if (!verifyAirport(arg1)) {
                            strcat(query, " ");
                            strcat(query, arg1);
                            interpret_query(query, man, 0);
                            getchar();
                            break;
                        }
                        consoleMessage("Código Inválido, tente novamente");
                    }
                    break;
                }

                case '2': {
                    while (1) {
                        printf("\nTop N aeronaves: ");
                        if (!fgets(arg1, MAX_QUERY, stdin)) {
                            perror("fgets");
                            continue;
                        }
                        arg1[strcspn(arg1, "\n")] = '\0';

                        int ok = 1;
                        for (int i = 0; arg1[i]; i++) {
                            if (!isdigit(arg1[i])) {
                                ok = 0;
                                break;
                            }
                        }

                        if (ok) {
                            printf("\nManufacter (opcional): ");
                            if (!fgets(arg2, MAX_QUERY, stdin)) {
                                perror("fgets");
                                continue;
                            }
                            arg2[strcspn(arg2, "\n")] = '\0';

                            strcat(query, " ");
                            strcat(query, arg1);
                            if (arg2[0]) {
                                strcat(query, " ");
                                strcat(query, arg2);
                            }

                            interpret_query(query, man, 0);
                            getchar();
                            break;
                        }

                        consoleMessage("Digite um número para o Top N Aeronaves");
                    }
                    break;
                }

                case '3':
                case '4': {
                    while (1) {
                        printf("\nData1: ");
                        if (!fgets(arg1, MAX_QUERY, stdin)) {
                            perror("fgets");
                            continue;
                        }
                        arg1[strcspn(arg1, "\n")] = '\0';

                        if (!verifyDOB(arg1)) {
                            printf("\nData2: ");
                            if (!fgets(arg2, MAX_QUERY, stdin)) {
                                perror("fgets");
                                continue;
                            }
                            arg2[strcspn(arg2, "\n")] = '\0';

                            if (!verifyDOB(arg2)) {
                                strcat(query, " ");
                                strcat(query, arg1);
                                strcat(query, " ");
                                strcat(query, arg2);

                                interpret_query(query, man, 0);
                                getchar(); 
                                break;
                            }
                        }
                        consoleMessage("Data inválida");
                    }
                    break;
                }

                case '5': {
                    printf("\nTop N companhias: ");
                    if (!fgets(arg1, MAX_QUERY, stdin)) {
                        perror("fgets");
                        continue;
                    }
                    arg1[strcspn(arg1, "\n")] = '\0';

                    strcat(query, " ");
                    strcat(query, arg1);
                    interpret_query(query, man, 0);
                    getchar(); 
                    break;
                }

                case '6': {
                    printf("\nNacionalidade: ");
                    if (!fgets(arg1, MAX_QUERY, stdin)) {
                        perror("fgets");
                        continue;
                    }
                    arg1[strcspn(arg1, "\n")] = '\0';

                    strcat(query, " ");
                    strcat(query, arg1);
                    interpret_query(query, man, 0);
                    getchar();
                    break;
                }

                case 'q':
                    flag1 = 1;
                    break;
            }
        } else {
            consoleMessage("Query inválida");
        }
    }
}
