#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char matricula[30];
    char nome_discente[150];
    char ano_ingresso[10];
    char periodo_ingresso[10];
    char tipo_discente[30];
    char status_discente[30];
    char nivel_ensino[30];
    char nome_curso[200];
    char modalidade_educacao[50];
    char nome_unidade[200];
    char nome_unidade_gestora[200];
} Discente;

Discente *lerCSV(char *arquivo, int *quantidade) {
    FILE *fp = fopen(arquivo, "r");
    char linha[2000];
    Discente *discentes = NULL;
    int total = 0;

    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp)) {
        discentes = realloc(discentes, (total + 1) * sizeof(Discente));

        char *campo = strtok(linha, ",");

        strcpy(discentes[total].matricula, campo);
        strcpy(discentes[total].nome_discente, strtok(NULL, ","));
        strcpy(discentes[total].ano_ingresso, strtok(NULL, ","));
        strcpy(discentes[total].periodo_ingresso, strtok(NULL, ","));
        strcpy(discentes[total].tipo_discente, strtok(NULL, ","));
        strcpy(discentes[total].status_discente, strtok(NULL, ","));
        strcpy(discentes[total].nivel_ensino, strtok(NULL, ","));
        strcpy(discentes[total].nome_curso, strtok(NULL, ","));
        strcpy(discentes[total].modalidade_educacao, strtok(NULL, ","));
        strcpy(discentes[total].nome_unidade, strtok(NULL, ","));
        strcpy(discentes[total].nome_unidade_gestora, strtok(NULL, ","));

        total++;
    }
    fclose(fp);

    *quantidade = total;
    return discentes;
}
