#include <stdio.h>
#include "leitura_arquivo.h"

char arquivo[256];
Discente * discentes;
int quantidade;

void start(){

    char opcao;

    
    do
    {
        
        printf(
            "========================================================================================================================"
            "                                           Processador de Dados de Discentes                                            \n"
            "========================================================================================================================"
            "\n\n"
            "1 - Ler arquivo CSV\n"
            "2 - Exibir discentes\n"
            "3 - Gerar arquivo de texto\n"
            "0 - Sair\n"
            "> "
        );

        opcao = getchar();
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

        if(opcao == '1'){
            printf("Insira o nome do arquivo CSV: ");
            scanf("%s", arquivo);
            while ((c = getchar()) != '\n' && c != EOF);
            discentes = lerCSV(arquivo, &quantidade);
        } else if(opcao == '2'){
            exibir_discentes(discentes ,quantidade);
            
        } else if(opcao == '3'){
            printf("Gerando arquivo de texto...\n");
            // Chamar função para gerar arquivo de texto
        } else if(opcao == '0'){
            printf("Saindo...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != '0');
}