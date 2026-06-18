#define _POSIX_C_SOURCE 200809
#define MAX_LINE 1024

#include "parser/dataset_reader.h"
#include "io/interpreter.h"
#include "io/query_file.h"
#include "managers/managerGlobal.h"
#include <glib.h>
#include <stdio.h>
#include <sys/resource.h>
#include <time.h>

gboolean comparar_ficheiros(const gchar *ficheiro1, const gchar *ficheiro2,
                            int query_num, int *linha_erro) {

  *linha_erro = 0;
  FILE *f1 = fopen(ficheiro1, "r");
  FILE *f2 = fopen(ficheiro2, "r");

  if (!f1 || !f2) {
    if (f1)
      fclose(f1);
    if (f2)
      fclose(f2);
    g_printerr("Erro ao abrir ficheiros da Q%d: %s / %s\n", query_num,
               ficheiro1, ficheiro2);
    return FALSE;
  }

  char l1[MAX_LINE], l2[MAX_LINE];
  int linha = 1;

  while (TRUE) {
    gchar *r1 = fgets(l1, sizeof(l1), f1);
    gchar *r2 = fgets(l2, sizeof(l2), f2);

    if (r1)
      l1[strcspn(l1, "\r\n")] = 0;
    if (r2)
      l2[strcspn(l2, "\r\n")] = 0;

    if (!r1 && !r2)
      break;

    if (!r1 || !r2 || g_strcmp0(l1, l2) != 0) {
      *linha_erro = linha;
      fclose(f1);
      fclose(f2);
      return FALSE;
    }
    linha++;
  }

  fclose(f1);
  fclose(f2);
  return TRUE;
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        g_printerr("Uso: %s <pasta_CSVs> <pasta_comandos> <pasta_output_esperado>\n", argv[0]);
        return 1;
    }

    gchar *dataset_path = argv[1];
    gchar *commands_path = argv[2];
    gchar *expected_path = argv[3];

    struct timespec start_total, end_total;
    clock_gettime(CLOCK_REALTIME, &start_total);

    ManagerGlobal *global = allocateManagerGlobal();
    initManager(global);
    readDatasetPath(dataset_path, global);

    FILE *inputs = fopen(commands_path, "r");
    if (!inputs) {
        g_printerr("Erro ao abrir ficheiro de comandos: %s\n", commands_path);
        freeAll(global);
        return 1;
    }

    char lInput[MAX_LINE];
    int linha = 1;

    int total_testes[6] = {0};
    int testes_ok[6] = {0};
    double query_time[6] = {0};

    while (fgets(lInput, sizeof(lInput), inputs)) {
        lInput[strcspn(lInput, "\r\n")] = 0;

        int q = atoi(lInput);
        if (q < 1 || q > 6) {
            g_printerr("Query inválida na linha %d: %s\n", linha, lInput);
            linha++;
            continue;
        }

        struct timespec start_query, end_query;
        clock_gettime(CLOCK_REALTIME, &start_query);
        interpret_query(lInput, global, 1);
        clock_gettime(CLOCK_REALTIME, &end_query);

        double tempo = (end_query.tv_sec - start_query.tv_sec) * 1000.0 +
                       (end_query.tv_nsec - start_query.tv_nsec) / 1e6;
        query_time[q - 1] += tempo;
        total_testes[q - 1]++;

        gchar ficheiro_nome[300];
        snprintf(ficheiro_nome, sizeof(ficheiro_nome), "command%d_output.txt", linha);

        gchar *esperado = g_build_filename(expected_path, ficheiro_nome, NULL);
        gchar *obtido   = g_build_filename("resultados", ficheiro_nome, NULL);

        int linha_erro = -1;
        gboolean igual = comparar_ficheiros(esperado, obtido, q, &linha_erro);

        if (igual) testes_ok[q - 1]++;
        else g_printerr("Discrepancia na query %d: linha %d de \"%s\"\n", q, linha_erro, obtido);

        g_free(esperado);
        g_free(obtido);

        linha++;
    }

    fclose(inputs);
    freeAll(global);
    printf("\nTestes: \n"); 
    for (int a = 0; a < 6; a++)
        g_print("Q%d: %d de %d testes ok\n",
                a + 1, testes_ok[a], total_testes[a]);

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double mem_mb = usage.ru_maxrss / 1024.0;

    clock_gettime(CLOCK_REALTIME, &end_total);
    double tempo_total = (end_total.tv_sec - start_total.tv_sec) +
                         (end_total.tv_nsec - start_total.tv_nsec) / 1e9;

    g_print("Memoria utilizada: %.0fMB\n", mem_mb);
    g_print("Tempo de execucao das queries: \n"); 
    for(int a = 0; a < 6; a++){
      g_print("    Q%d: %3f ms\n", a + 1, total_testes[a] > 0 ? query_time[a] / total_testes[a] : 0); 
    }
    g_print("Tempo total: %.3fs\n", tempo_total);

    return 0;
}
