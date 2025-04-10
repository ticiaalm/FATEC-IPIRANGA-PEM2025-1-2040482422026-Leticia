/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programação Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Simular o processo de controle   *
* de estoque e logística de movimentação de produtos     *
* dentro de uma empresa atacadista na linguagem C.       *
* Data - 13/03/2025                                      *
* Autor: Letícia Almeida Silva                           *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define RUAS 3
#define GONDOLAS 10
#define PRODUTOS 1

typedef struct {
    char codigo[10];
    int quantidade;
} Produto;

Produto estoque[RUAS][GONDOLAS][PRODUTOS];

void armazenarProduto (int rua, int gondola, char codigo[], int quantidade) {
    if (estoque[rua][gondola][0].quantidade == 0) {
        strcpy (estoque[rua][gondola][0].codigo, codigo);
        estoque[rua][gondola][0].quantidade = quantidade;
        printf ("Produto %s armazenado na Rua %d, Gôndola %d.\n", codigo, rua+1, gondola+1);
    } else {
        printf ("Erro: Gôndola %d da Rua %d já está ocupada pelo produto %s.\n", gondola+1, rua+1, estoque[rua][gondola][0].codigo);
    }
}
void retirarProduto (int rua, int gondola, int quantidade) {
    if (estoque[rua][gondola][0].quantidade >= quantidade) {
        estoque[rua][gondola][0].quantidade -= quantidade;
        printf ("%d unidades do produto %s retiradas da Rua %d, Gôndola %d.\n", 
               quantidade, estoque[rua][gondola][0].codigo, rua+1, gondola+1);
        
        if (estoque[rua][gondola][0].quantidade == 0) {
            strcpy (estoque[rua][gondola][0].codigo, "");
        }
    } else {
        printf ("Erro: Quantidade insuficiente na Gôndola %d da Rua %d.\n", gondola+1, rua+1);
    }
}
void exibirEstoque () {
    printf ("\nEstado Atual do Estoque:\n");
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            if (estoque[i][j][0].quantidade > 0) {
                printf ("Rua %d - Gôndola %d: Produto %s - Quantidade %d\n", 
                       i+1, j+1, estoque[i][j][0].codigo, estoque[i][j][0].quantidade);
            }
        }
    }
}
int main () {
    armazenarProduto (0, 9, "S123", 50);
    armazenarProduto( 1, 4, "C456", 30);
    exibirEstoque ();
    retirarProduto (0, 9, 20);
    retirarProduto (1, 4, 10);
    exibirEstoque ();
    
    return 0;
}
