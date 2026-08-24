#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura_arquivo.h"
#include "escrita_resultado_arquivo.h"

void escrever_discente(FILE* arquivo, Discente d){
    fprintf(
    arquivo,
    "_______________________________________________________________________________________________________________________"
    "\n\nMatricula           : %s"
    "\nNome                : %s"
    "\nAno de Ingresso     : %s"
    "\nPeriodo de Ingresso : %s"
    "\nTipo                : %s"
    "\nStatus              : %s"
    "\nCurso               : %s"
    "\nModalidade          : %s"
    "\nUnidade             : %s"
    "\nUnidade Gestora     : %s"
    "\n_______________________________________________________________________________________________________________________\n",
    d.matricula,
    d.nome_discente,
    d.ano_ingresso,
    d.periodo_ingresso,
    d.tipo_discente,
    d.status_discente,
    d.nome_curso,
    d.modalidade_educacao,
    d.nome_unidade,
    d.nome_unidade_gestora
    );

}

void escrever_discentes_txt(const char nomeArquivo[], Discente * d, int tamanho){
    printf("========================================================================================================================\n");
    
    FILE *arquivoSaida = fopen(nomeArquivo, "w");
    if (!arquivoSaida) {
        printf("Não foi possível criar o arquivo de saída. Terminando...\n");
        return;
    }

    printf("Gerando arquivo de texto...\n");
    for(int i = 0; i < tamanho; i++){
        escrever_discente(arquivoSaida, d[i]);
    }
    printf("Pronto\n");

    fclose(arquivoSaida);
}