/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programação Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Percursão de um vetor em         *
* BubbleSort, onde se compara elementos e os troca por   *
* se estiverem fora de ordem.                            *
* Data - 16/05/2025                                      *
* Autor: Letícia Almeida Silva                           *
*--------------------------------------------------------*/

#include <stdio.h>
void bubbleSort (int *vetor, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(vetor + j) > *(vetor + j + 1)) {
                temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
            }
        }
    }
}
void imprimirVetor (int *vetor, int n) {
    printf ("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf ("%d ", *(vetor + i));
    }
    printf ("\n");
}
int main () {
    int n;
    printf ("Digite a quantidade de elementos: ");
    scanf ("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++) {
        printf ("Digite o elemento %d: ", i + 1);
        scanf ("%d", &vetor[i]);
    }
    bubbleSort (vetor, n);
    imprimirVetor (vetor, n);
    return 0;
}