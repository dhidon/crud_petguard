#ifndef MODELOS_H
#define MODELOS_H

#define PATH_ANIMALS_IDS "./configs/animalIds.bin"
#define PATH_USERS_IDS "./configs/userIds.bin"
#define PATH_ANIMALS "./data/animais.bin"
#define PATH_USERS "./data/usuarios.bin"
#define PATH_TEMP "./data/temp.bin"

enum tipos {CACHORRO, GATO, OUTRO_TIPO};
enum petStatus {ADOTADO, SEM_CUIDADOR, COMUNITARIO, MORTO};
enum racas {SRD, PITBULL, PASTOR, POODLE, HUSKY, OUTRA_RACA};
enum cores {CARAMELO, RAJADO, PRETO, BRANCO, FRAJOLA, LARANJA, TRICOLOR};
enum tamanhos {PEQUENO, MEDIO, GRANDE};
enum idades {FILHOTE, JOVEM_ADULTO, ADULTO, IDOSO};
enum tipoUser {VISITANTE, VOLUNTARIO, PROTETOR, ONG};
enum sexoAnimal {MACHO, FEMEA};

typedef struct {
    float latitude;
    float longitude;
} coordenadas;

typedef struct {
    char nome[30];
    petStatus status;
    tipos tipo;
    racas raca;
    cores cor;
    tamanhos tamanho;
    idades idade;
    int cuidador;
    int animalID;
    coordenadas coords;
    char criado_em[20];
    sexoAnimal sexo;
} Animal;

typedef struct {
    char nome[50];
    tipoUser tipo;
    char telefone[15];
    char email[40];
    int userID;
    char criado_em[20];
} User;

const char* tipo_para_texto(tipos tipo);
const char* status_para_texto(petStatus status);
const char* raca_para_texto(racas raca);
const char* cor_para_texto(cores cor);
const char* tamanho_para_texto(tamanhos tamanho);
const char* idade_para_texto(idades idade);
const char* tipoUser_para_texto(tipoUser tipo);
const char* sexo_para_texto(sexoAnimal sexo);


#endif