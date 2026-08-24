#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura_arquivo.h"

Discente *lerCSV(char *arquivo, int *quantidade) {
    // Função para ler o arquivo CSV, exportando o número de quantidades diretamente pelo ponteiro.

    // Tenta ler o arquivo
    FILE *fp = fopen(arquivo, "r");
    if(fp == NULL){
        printf("Erro carregar arquivo\n");
        return NULL;
    }

    char linha[2000];
    Discente *discentes = NULL;
    int total = 0;

    // Lê e descarta a 1° linha do CSV (nomes das colunas)
    fgets(linha, sizeof(linha), fp);

    // Lê todas as linhas seguintes até o final do arquivo
    while (fgets(linha, sizeof(linha), fp)) {

        // Aumente o vetor do array discentes em +1 espaço
        Discente * temp = realloc(discentes, (total + 1) * sizeof(Discente));
        
        if (temp != NULL){

            discentes = temp;
            
            // Preenche todos os bytes do final do array com 0, evitando lixo de memória
            memset(&discentes[total], 0, sizeof(Discente));

            // Divide a linha em campos individuais utilizando os delimitadores configurados
            char *campo;
            const char *delimitadores = "\",\r\n";

            campo = strtok(linha, delimitadores);
            if (campo != NULL) strcpy(discentes[total].matricula, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].nome_discente, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].ano_ingresso, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].periodo_ingresso, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].tipo_discente, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].status_discente, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].nivel_ensino, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].nome_curso, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].modalidade_educacao, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].nome_unidade, campo);

            campo = strtok(NULL, delimitadores);
            if (campo != NULL) strcpy(discentes[total].nome_unidade_gestora, campo);
                
            total++;
            }
    }
    fclose(fp);

    // Retorna a quantidade via ponteiro
    *quantidade = total;
    return discentes;
}

void exibir(Discente d){
    // Função para exibir as informações sobre o discente utilizando o formato específico.

    printf(
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

void exibir_discentes(Discente * d, int tamanho){
    // Função para criar uma interface de exibição de discentes
    // Atualmente só mostra dois discentes na entrada e a cada ENTER

    int atual = 0;
    char opcao;

    for(int i = 0; i < tamanho; i++){

        exibir(d[atual]);
        atual++;
        if(atual%2 == 0){
            printf("\n\n> Pressione ENTER para continuar ou digite 0 para sair\n> ");
            opcao = getchar();
            char c;
            // Limpa o buffer do teclado caso o usuário queira sair do loop
            if(opcao == '0'){while ((c = getchar()) != '\n' && c != EOF);break;}

        }

    }


}