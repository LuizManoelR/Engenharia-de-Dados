#include <stdio.h>
#include "leitura_arquivo.h"
#include "escrita_resultado_arquivo.h"

char arquivo[256]; // Nome do arquivo de entrada
char nomeArquivo[] = "terminalOutput.txt"; // Nome do arquivo de saída

Discente * discentes; // Ponteiro para o array
int quantidade = -1; // Armazena a quantidade de discentes

void start(){
    char opcao;

    
    do
    {
        
        printf(
            "========================================================================================================================\n"
            "                                           Processador de Dados de Discentes                                            \n"
            "========================================================================================================================\n"
            "\n"
            "1 - Ler arquivo CSV\n"
            "2 - Exibir discentes\n"
            "3 - Gerar arquivo de texto\n"
            "0 - Sair\n"
            "> "
        );

        opcao = getchar();
        char c;
        while ((c = getchar()) != '\n' && c != EOF); // Caso o input seja quebra linha ou vazio, entra em loop, 

        if(opcao == '1'){
            printf("Insira o nome do arquivo CSV: ");
            scanf("%s", arquivo);
            while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer do teclado
            discentes = lerCSV(arquivo, &quantidade);
        } else if(opcao == '2'){
            // Caso a quantidade de discentes não tenha sido alterado, o arquivo não foi lido.
            if (quantidade == -1) {
                printf("========================================================================================================================\n");
                printf("AVISO: Arquivo não foi carregado\n");
                continue;
            }

            exibir_discentes(discentes ,quantidade);
        } else if(opcao == '3'){
            // Caso a quantidade de discentes não tenha sido alterado, o arquivo não foi lido.
            if (quantidade == -1) {
                printf("========================================================================================================================\n");
                printf("AVISO: Arquivo não foi carregado\n");
                continue;
            }
            
            escrever_discentes_txt(nomeArquivo, discentes, quantidade);
        } else if(opcao == '0'){
            printf("Saindo...\n");
            return;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != '0');
}