#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/modelos.h"
#include "../include/persistencia.h"

int main(int argc, char *argv[]){

    if (argc < 2){
        printf("\"erro\": \"Nenhum argumento fornecido. User --listar-tudo, --animais, etc.\"}");
        return 1;
    }

    if (strcmp(argv[1], "--animais") == 0 && argc >= 2){
        lerAnimal();
        return 0;
    }

    if (strcmp(argv[1], "--usuarios") == 0 && argc >= 2){
        lerUsuario();
        return 0;
    }

    if (strcmp(argv[1], "--listar-tudo") == 0){
        printf("{\n");

        printf("\"animais\": ");
        lerAnimal();
        printf(",\n");
        printf("\"usuarios\": ");
        lerUsuario();
        printf("\n}");

        return 0;
    }

    if (strcmp(argv[1], "--salvar-animal") == 0 && argc > 11){
        Animal novoPet;
        memset(&novoPet, 0, sizeof(Animal));

        strncpy(novoPet.nome, argv[2], sizeof(novoPet.nome) -1);
        novoPet.status = (petStatus)atoi(argv[3]);
        novoPet.tipo = (tipos)atoi(argv[4]);
        novoPet.raca = (racas)atoi(argv[5]);
        novoPet.cor = (cores)atoi(argv[6]);
        novoPet.tamanho = (tamanhos)atoi(argv[7]);
        novoPet.idade = (idades)atoi(argv[8]);
        novoPet.cuidador = atoi(argv[9]);
        novoPet.coords.latitude = atof(argv[10]);
        novoPet.coords.longitude = atof(argv[11]);
        strncpy(novoPet.criado_em, argv[12], sizeof(novoPet.criado_em) -1);
        novoPet.sexo = (sexoAnimal)atoi(argv[13]);

        salvarAnimal(&novoPet);
        printf("{\"sucesso\": true}");
        return 0;
    }

    if (strcmp(argv[1], "--listar-animal") == 0 && argc >= 2){
        Animal animal;

        animal.animalID = atoi(argv[2]);
        lerUnicoAnimal(&animal);
        printf("{\"sucesso\": true}");

        return 0;
    }

    if (strcmp(argv[1], "--editar-animal") == 0 && argc > 12){
        Animal toEdit;

        toEdit.animalID = atoi(argv[2]);
        strncpy(toEdit.nome, argv[3], sizeof(toEdit.nome) - 1);
        toEdit.status = (petStatus)atoi(argv[4]);
        toEdit.tipo = (tipos)atoi(argv[5]);
        toEdit.raca = (racas)atoi(argv[6]);
        toEdit.cor = (cores)atoi(argv[7]);
        toEdit.tamanho = (tamanhos)atoi(argv[8]);
        toEdit.idade = (idades)atoi(argv[9]);
        toEdit.cuidador = atoi(argv[10]);
        toEdit.coords.latitude = atof(argv[11]);
        toEdit.coords.longitude = atof(argv[12]);
        strncpy(toEdit.criado_em, argv[13], sizeof(toEdit.criado_em) - 1);
        toEdit.sexo = (sexoAnimal)atoi(argv[13]);
       
        alterarAnimal(&toEdit);
        printf("\"sucesso\": true");

        return 0;
    }

    if (strcmp(argv[1], "--deletar-animal") == 0 && argc >= 3){
        Animal toDelete;
        toDelete.animalID = atoi(argv[2]);

        deletaAnimal(&toDelete);
        printf("{\"sucesso\": true}");
        return 0;
    }

    if (strcmp(argv[1], "--salvar-user") == 0 && argc > 6){
        User novoUser;
        memset(&novoUser, 0, sizeof(User));

        strncpy(novoUser.nome, argv[2], sizeof(novoUser.nome) - 1);
        novoUser.tipo = (tipoUser)atoi(argv[3]);
        strncpy(novoUser.telefone, argv[4], sizeof(novoUser.telefone) - 1);
        strncpy(novoUser.email, argv[5], sizeof(novoUser.email) - 1);
        strncpy(novoUser.criado_em, argv[6], sizeof(novoUser.criado_em) - 1);
        
        salvarUser(&novoUser);
        
        printf("{\"sucesso\": true}");

        return 0;
    }

    if (strcmp(argv[1], "--editar-user") == 0 && argc > 7){
        User toEdit;

        toEdit.userID = atoi(argv[2]);
        strncpy(toEdit.nome, argv[3], sizeof(toEdit.nome) - 1);
        toEdit.tipo = (tipoUser)atoi(argv[4]);
        strncpy(toEdit.telefone, argv[5], sizeof(toEdit.telefone) - 1);
        strcpy(toEdit.email, argv[6]);
        strncpy(toEdit.criado_em, argv[7], sizeof(toEdit.criado_em) - 1);

        alterarUsuario(&toEdit);
        printf("\"sucesso\": true");

        return 0;
    }

    if (strcmp(argv[1], "--deletar-user") == 0 && argc >= 3){
        User toDelete;

        toDelete.userID = atoi(argv[2]);
        deletaUsuario(&toDelete);
        printf("\"sucesso\": true");

        return 0;
    }

    printf("\n");
    printf("    \"sucesso\": false,\n");
    printf("    \"erro\": Comando ou flag não recebida. Verifique a sintaxe.\n");
    printf("}\n");

    return 1;
}