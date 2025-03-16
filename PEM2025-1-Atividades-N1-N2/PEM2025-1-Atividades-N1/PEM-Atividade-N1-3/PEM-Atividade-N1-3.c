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

void armazenarProduto (Produto (*estoque)[GONDOLAS][PRODUTOS], int rua, int gondola, const char codigo[], int quantidade) {
    Produto *produto = &estoque[rua][gondola][0];
    
    if (produto->quantidade == 0) {
        strcpy (produto->codigo, codigo);
        produto->quantidade = quantidade;
        printf ("Produto %s armazenado na Rua %d, Gôndola %d.\n", codigo, rua + 1, gondola + 1);
    } else {
        printf ("Erro: Gôndola %d da Rua %d já está ocupada pelo produto %s.\n", gondola + 1, rua + 1, produto->codigo);
    }
}
void retirarProduto (Produto (*estoque)[GONDOLAS][PRODUTOS], int rua, int gondola, int quantidade) {
    Produto *produto = &estoque[rua][gondola][0];

    if (produto->quantidade >= quantidade) {
        produto->quantidade -= quantidade;
        printf ("%d unidades do produto %s retiradas da Rua %d, Gôndola %d.\n", quantidade, produto->codigo, rua + 1, gondola + 1);
        
        if (produto->quantidade == 0) {
            strcpy (produto->codigo, "");
        }
    } else {
        printf ("Erro: Quantidade insuficiente na Gôndola %d da Rua %d.\n", gondola + 1, rua + 1);
    }
}
void exibirEstoque(Produto (*estoque)[GONDOLAS][PRODUTOS]) {
    printf ("\nEstado Atual do Estoque:\n");
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            Produto *produto = &estoque[i][j][0];
            if (produto->quantidade > 0) {
                printf ("Rua %d - Gôndola %d: Produto %s - Quantidade %d\n", i + 1, j + 1, produto->codigo, produto->quantidade);
            }
        }
    }
}
int main () {
    armazenarProduto (estoque, 0, 9, "S123", 50);
    armazenarProduto (estoque, 1, 4, "C456", 30);
    exibirEstoque (estoque);
    retirarProduto (estoque, 0, 9, 20);
    retirarProduto (estoque, 1, 4, 10);
    exibirEstoque (estoque);
    
    return 0;
}