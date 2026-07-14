#include <stdio.h>
#include "../include/persistencia.h"
#include "../include/modelos.h"
#include "../include/ids.h"
#include <string.h>

void salvarAnimal(Animal *animal){
    animal->animalID = gerarId(PATH_ANIMALS_IDS);
    if (animal->animalID == -1) return;

    FILE *f = fopen(PATH_ANIMALS, "ab");
    if (f == NULL) return;

    fwrite(animal, sizeof(Animal), 1, f);
    fclose(f);
}

void buscarNomeUser(int id, char* nome){
    FILE *users = fopen(PATH_USERS, "rb");
    User tempUser;

    if(users == NULL){
        strcpy(nome, "Erro ao abrir o arquivo");
    }
    while (fread(&tempUser, sizeof(User), 1, users)){
        if(tempUser.userID == id){
            strncpy(tempUser.nome, nome, sizeof(tempUser.nome) - 1);
        }
    }

}

void lerAnimal(){
    FILE *f = fopen(PATH_ANIMALS, "rb");
    if (f == NULL) {
        printf("[]");
        return;
    }

    Animal temp;
    int primeiro = 1;

    printf("[\n");

    while(fread(&temp, sizeof(Animal), 1, f)){
        if(!primeiro) printf(",\n");
        primeiro = 0;
        
        char nome[50];
        buscarNomeUser(temp.cuidador, nome);

        printf("{\n");
        printf("    \"animalID\": %d,\n", temp.animalID);
        printf("    \"nome\": \"%s\",\n", temp.nome);
        printf("    \"status_codigo\": %d,\n", temp.status);
        printf("    \"status\": \"%s\",\n",status_para_texto(temp.status));
        printf("    \"tipo\": \"%s\",\n", tipo_para_texto(temp.tipo));
        printf("    \"raca\": \"%s\",\n", raca_para_texto(temp.raca));
        printf("    \"cor\": \"%s\",\n", cor_para_texto(temp.cor));
        printf("    \"tamanho\": \"%s\",\n", tamanho_para_texto(temp.tamanho));
        printf("    \"idade_codigo\": %d,\n", temp.idade);
        printf("    \"idade\": \"%s\",\n", idade_para_texto(temp.idade));
        printf("    \"cuidador\": %s,\n", nome);
        printf("    \"local\":\n");
        printf("        {\n");
        printf("        \"latitude\": %f,\n", temp.coords.latitude);
        printf("        \"longitude\": %f\n", temp.coords.longitude);
        printf("        },\n");
        printf("    \"criado_em\": \"%s\"\n", temp.criado_em);
        printf("    \"sexo_codigo\": %d,\n", temp.sexo);
        printf("    \"sexo\": \"%s\"\n", sexo_para_texto(temp.sexo));
        printf("}");
    }

    printf("\n]\n");
    fclose(f);
}

void alterarAnimal(Animal *animal){
    Animal temp;
    
    FILE *f = fopen(PATH_ANIMALS, "rb+");

    while(fread(&temp, sizeof(Animal), 1, f)){
        if(temp.animalID == animal->animalID){
            fseek(f, -sizeof(Animal), SEEK_CUR);
            fwrite(animal, sizeof(Animal), 1, f);
            fclose(f);
            return;
        }
    }

    fclose(f);
}

void lerUnicoAnimal(Animal *animal){
    FILE *f = fopen(PATH_ANIMALS, "rb");
    Animal temp;

    while(fread(&temp, sizeof(Animal), 1, f)){
        if(temp.animalID == animal->animalID){
            printf("{\n");
            printf("    \"animalID\": %d,\n", temp.animalID);
            printf("    \"nome\": \"%s\",\n", temp.nome);
            printf("    \"status_codigo\": %d,\n", temp.status);
            printf("    \"status\": \"%s\",\n",status_para_texto(temp.status));
            printf("    \"tipo\": \"%s\",\n", tipo_para_texto(temp.tipo));
            printf("    \"raca\": \"%s\",\n", raca_para_texto(temp.raca));
            printf("    \"cor\": \"%s\",\n", cor_para_texto(temp.cor));
            printf("    \"tamanho\": \"%s\",\n", tamanho_para_texto(temp.tamanho));
            printf("    \"idade_codigo\": %d,\n", temp.idade);
            printf("    \"idade\": \"%s\",\n", idade_para_texto(temp.idade));
            printf("    \"cuidador\": %i,\n", temp.cuidador);
            printf("    \"local\":\n");
            printf("        {\n");
            printf("        \"latitude\": %f,\n", temp.coords.latitude);
            printf("        \"longitude\": %f\n", temp.coords.longitude);
            printf("        },\n");
            printf("    \"criado_em\": \"%s\"\n", temp.criado_em);
            printf("\"sexo_codigo\": %d,\n", temp.sexo);
            printf("    \"sexo\": \"%s\"\n", sexo_para_texto(temp.sexo));
            printf("}");
        }
    }
}

void deletaAnimal(Animal *animal){
    FILE *f = fopen(PATH_ANIMALS, "rb");
    FILE *novo = fopen(PATH_TEMP, "wb");
    Animal temp;

    if (f == NULL) return;

    while (fread(&temp, sizeof(Animal), 1, f)){
        if(animal->animalID != temp.animalID){
            fwrite(&temp, sizeof(Animal), 1, novo);
        }
    }

    fclose(f);
    fclose(novo);

    remove(PATH_ANIMALS);
    rename(PATH_TEMP, PATH_ANIMALS);
}

void salvarUser(User *usuario){
    usuario->userID = gerarId(PATH_USERS_IDS);
    if (usuario->userID == -1) return;

    FILE *f = fopen(PATH_USERS, "ab");
    if (f == NULL) printf("Não foi possível abrir o arquivo");

    size_t gravados = fwrite(usuario, sizeof(User), 1, f);
    if (!gravados) printf("Não foi possível gravar");

    fclose(f);
}

void lerUsuario(){
    FILE *f = fopen(PATH_USERS, "rb");
    if (f == NULL){
        printf("[]");
        return;
    }

    User temp;
    int primeiro = 1;

    printf("[\n");

    while(fread(&temp, sizeof(User), 1, f)){
        if(!primeiro) printf(",\n");
        primeiro = 0;

        printf("{\n");
        printf("    \"nome\": \"%s\",\n", temp.nome);
        printf("    \"tipo_codigo:\": %d,\n", temp.tipo);
        printf("    \"tipo\": \"%s\",\n", tipoUser_para_texto(temp.tipo));
        printf("    \"telefone\": \"%s\",\n", temp.telefone);
        printf("    \"email\":\"%s\",\n", temp.email);
        printf("    \"id\": \"%d\",\n", temp.userID);
        printf("    \"criado_em\": \"%s\"\n", temp.criado_em);
        printf("}");
    }

    printf("\n]\n");
    fclose(f);
}

void alterarUsuario(User *usuario){
    User temp;
    FILE *f = fopen(PATH_USERS, "rb+");

    while(fread(&temp, sizeof(User), 1, f)){
        if(usuario->userID == temp.userID){
            fseek(f, -sizeof(User), SEEK_CUR);
            fwrite(usuario, sizeof(User), 1, f);
            fclose(f);
            return;
        }
    }

    fclose(f);
}

void deletaUsuario(User *usuario){
    FILE *f = fopen(PATH_USERS, "rb");
    FILE *novo = fopen(PATH_TEMP, "wb");
    User temp;

    while (fread(&temp, sizeof(User), 1, f)){
        if(usuario->userID != temp.userID){
            fwrite(&temp, sizeof(User), 1, novo);
        }
    }

    fclose(f);
    fclose(novo);

    remove(PATH_USERS);
    rename(PATH_TEMP,PATH_USERS);
}