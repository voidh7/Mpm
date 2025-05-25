#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nomes[5][50];
    char links[5][100];
} Bibliotecas;

int main() {
    system("clear");

    printf(" \n \t  MPM1 \n  ");
    Bibliotecas libs = {
        .nomes = {
            "GLib",
            "libcurl",
            "OpenSSL",
            "SQLite",
            "zlib"
        },
        .links = {
            "https://download.gnome.org/sources/glib/2.74/glib-2.74.0.tar.xz",
            "https://curl.se/download/curl-8.0.1.tar.gz",
            "https://www.openssl.org/source/openssl-3.1.2.tar.gz",
            "https://www.sqlite.org/2023/sqlite-autoconf-3420000.tar.gz",
            "https://zlib.net/zlib-1.2.13.tar.gz"
        }
    };

    char input[50];
    printf("\nDigite o nome da biblioteca para baixar  : \n  ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "/list") == 0) {
        printf("\nLista das bibliotecas disponíveis:\n");
        for (int i = 0; i < 5; i++) {
            printf(" - %s\n", libs.nomes[i]);
        }
        return 0;
    }
  if(strcmp(input,"/help") ==0){
        printf(" \n mpm 2025 \n vertion: 1.1.2 \n by void \n github:https://github.com/voidh7/Mpm \n ");

        printf(" \n \t CMDS \n /list \n ");
        return 0;
        }

    int encontrado = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(input, libs.nomes[i]) == 0) {
            encontrado = 1;
            char cmd[200];

            snprintf(cmd, sizeof(cmd), "curl -O %s", libs.links[i]);
            printf("Baixando %s...\n", libs.nomes[i]);
            int ret = system(cmd);
            if (ret == -1) {
                printf("Erro ao executar o comando de download.\n");
            } else {
                printf("Download finalizado.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("\nBiblioteca não encontrada.\n");
    }

    return 0;
}
