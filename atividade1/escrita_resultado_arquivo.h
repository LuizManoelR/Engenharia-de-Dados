#ifndef ESCRITA_RESULTADO_ARQUIVO_H
#define ESCRITA_RESULTADO_ARQUIVO_H

void escrever_discente(FILE* arquivo, Discente d);
void escrever_discentes_txt(const char nomeBase[], Discente * d, int tamanho);

#endif