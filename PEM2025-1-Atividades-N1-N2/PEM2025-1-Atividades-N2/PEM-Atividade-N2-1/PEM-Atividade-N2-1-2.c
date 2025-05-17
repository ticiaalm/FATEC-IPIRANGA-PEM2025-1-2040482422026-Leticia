/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programação Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Construção de um vetor em        *
* InsertionSort, onde insere novos elementos no lugar    *
* correto.                                               *
* Data - 16/05/2025                                      *
* Autor: Letícia Almeida Silva                           *
*--------------------------------------------------------*/

#include <stdio.h>
void insertionSort (int *vetor, int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = *(vetor + i);
        j = i - 1;

        while (j >= 0 && *(vetor + j) > chave) {
            *(vetor + j + 1) = *(vetor + j);
            j--;
        }
        *(vetor + j + 1) = chave;
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
    insertionSort (vetor, n);
    imprimirVetor (vetor, n);
    return 0;
}