#ifndef LEITURA_ARQUIVO_H
#define LEITURA_ARQUIVO_H


typedef struct {
    char matricula[50];
    char nome_discente[256];      
    char ano_ingresso[15];
    char periodo_ingresso[15];
    char tipo_discente[50];
    char status_discente[50];
    char nivel_ensino[50];
    char nome_curso[256];        
    char modalidade_educacao[100];
    char nome_unidade[256];       
    char nome_unidade_gestora[256];
} Discente;

Discente *lerCSV(char *arquivo, int *quantidade);
void exibir(Discente d);
void exibir_discentes(Discente * d, int tamanho);

#endif