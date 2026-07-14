#include <stdio.h>
#include "../include/ids.h"

int gerarId(const char *caminho){
    FILE *ids = fopen(caminho, "rb");
    int id = 0;

    if (ids != NULL){
        fread(&id, sizeof(int), 1, ids);
        if (id >= 1){
            id++;
        } else {
            id = 1;
        }
        fclose(ids);
    }
    ids = fopen(caminho, "wb");
    if (ids == NULL){
        printf("Erro grave! Não foi possível criar ou abrir o arquivo o arquivo de configurações em: %s", caminho);
        return -1;
    }
    size_t written = fwrite(&id, sizeof(int), 1, ids);
    if (written != 1) printf("Erro ao escrever o novo ID no arquivo.\n");    
    fclose(ids);
    return id;
}