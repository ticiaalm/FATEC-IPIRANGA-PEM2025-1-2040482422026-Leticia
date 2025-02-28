/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Criar um programa em C que       *
* processe e classifique candidatos à residência médica, *
* calculando a nota final e exibindo os 15 melhores.     *
* Data - 28/02/2025                                      *
* Autor: Letícia Almeida Silva                           *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define MAX_CAND 50 // número máximo de candidatos

char nomes[MAX_CAND][100]; // nomes dos candidatos
float PE[MAX_CAND][4]; // 4 notas por candidato
float AC[MAX_CAND][5]; // 5 notas por candidato
float PP[MAX_CAND][10]; // 10 notas por candidato
float EB[MAX_CAND][3]; // 3 notas por candidato
float nota_final[MAX_CAND]; // notas finais de cada candidato calculadas

int candidatos = 0;

float media (float notas[], int tamanho) {
    float maior = notas[0], menor = notas[0], soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        soma += notas[i];
    }
    soma -= maior + menor;
    return soma / (tamanho - 2);
}
int main () {
    char continuar;
    while (1) {
        if (candidatos >= MAX_CAND) {
            printf ("Número máximo de candidatos atingido.\n");
            break;
        }

        printf ("Digite o nome do candidato %d: ", candidatos + 1);
        scanf (" %[^\n]", nomes[candidatos]); 

        printf ("Digite as 4 notas da prova PE: ");
        for (int j = 0; j < 4; j++) {
            scanf("%f", &PE[candidatos][j]);
        }
        printf ("Digite as 5 notas da prova AC: ");
        for (int j = 0; j < 5; j++) {
            scanf ("%f", &AC[candidatos][j]);
        }
        printf ("Digite as 10 notas da prova PP: ");
        for (int j = 0; j < 10; j++) {
            scanf ("%f", &PP[candidatos][j]);
        }
        printf ("Digite as 3 notas da prova EB: ");
        for (int j = 0; j < 3; j++) {
            scanf ("%f", &EB[candidatos][j]);
        }

        candidatos++;
        getchar ();
        printf ("Deseja adicionar outro candidato? (s para sim / qualquer outra tecla para não): ");
        scanf ("%c", &continuar);
        if (continuar != 's' && continuar != 'S') {
            break;
        }
    }
    for (int i = 0; i < candidatos; i++) {
        float media_PE = media(PE[i], 4);
        float media_AC = media(AC[i], 5);
        float media_PP = media(PP[i], 10);
        float media_EB = media(EB[i], 3);
        nota_final[i] = (media_PE * 0.3) + (media_AC * 0.1) + (media_PP * 0.4) + (media_EB * 0.2);
    }
    
    printf ("\nClassificação dos 15 melhores candidatos:\n");
    for (int i = 0; i < candidatos && i < 15; i++) {
        printf ("%d. %s - Nota Final: %.2f\n", i + 1, nomes[i], nota_final[i]);
    }

    return 0;
}
