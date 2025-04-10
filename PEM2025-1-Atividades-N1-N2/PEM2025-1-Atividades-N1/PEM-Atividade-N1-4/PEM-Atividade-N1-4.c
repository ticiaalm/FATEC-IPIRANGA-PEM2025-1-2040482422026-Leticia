/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programação Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: listar recursivamente todos os   *
* diretórios e subdiretórios a partir de um diretório    *
* inicial.                                               *
* Data - 04/04/2025                                      *
* Autor: Letícia Almeida Silva                           *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void listar_diretorios (const char *caminho, int nivel) {
    struct dirent *entrada;
    DIR *dir = opendir(caminho);
    if (dir == NULL) {
        perror("Erro ao abrir diretorio");
        return;
    }
    while ((entrada = readdir(dir)) != NULL) {
        if (strcmp (entrada->d_name, ".") == 0 || strcmp (entrada->d_name, "..") == 0) {
            continue;
        }
        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("-> %s\n", entrada->d_name);
        char caminho_completo[1024];
        snprintf (caminho_completo, sizeof(caminho_completo), "%s/%s", caminho, entrada->d_name);
        struct stat info;
        if (stat(caminho_completo, &info) == 0 && S_ISDIR(info.st_mode)) {
            listar_diretorios(caminho_completo, nivel + 1);
        }
    }
    closedir (dir);
}
int main () {
    const char *caminho_inicial = ".";
    printf ("Estrutura do diretorio:\n");
    listar_diretorios(caminho_inicial, 0);
    return 0;
}
