#ifndef MODELOSTOTEXT_UTILS
#define MODELOSTOTEXT_UTILS

#include "../include/modelos.h"

const char* tipo_para_texto(tipos tipo){
    switch(tipo){
        case CACHORRO: return "cachorro";
        case GATO: return "gato";
        case OUTRO_TIPO: return "outro";
    }

    return "desconhecido";
}

const char* status_para_texto(petStatus status){
    switch(status){
        case ADOTADO: return "adotado";
        case SEM_CUIDADOR: return "sem cuidador";
        case COMUNITARIO: return "comunitário";
        case MORTO: return "morto";
    }

    return "desconhecido";
}

const char* raca_para_texto(racas raca){
    switch(raca){
        case SRD: return "srd";
        case PITBULL: return "pit bull";
        case PASTOR: return "pastor";
        case POODLE: return "poodle";
        case HUSKY: return "husky siberiano";
        case OUTRA_RACA: return "outro";
    }

    return "desconhecido";
}

const char* cor_para_texto(cores cor){
    switch(cor){
        case CARAMELO: return "caramelo";
        case RAJADO: return "rajado";
        case PRETO: return "preto";
        case BRANCO: return "branco";
        case FRAJOLA: return "frajola";
        case LARANJA: return "laranja";
        case TRICOLOR: return "tricolor";
    }

    return "desconhecido";
}

const char* tamanho_para_texto(tamanhos tamanho){
    switch(tamanho){
        case PEQUENO: return "pequeno";
        case MEDIO: return "medio";
        case GRANDE: return "grande";
    }

    return "desconhecido";
}

const char* idade_para_texto(idades idade){
    switch(idade){
        case FILHOTE: return "filhote";
        case JOVEM_ADULTO: return "jovem adulto";
        case ADULTO: return "adulto";
        case IDOSO: return "idoso";
    }
    return "desconhecido";
}

const char* tipoUser_para_texto(tipoUser tipo){
    switch(tipo){
        case VISITANTE: return "visitante";
        case VOLUNTARIO: return "voluntário";
        case PROTETOR: return "protetor";
        case ONG: return "ONG";
    }
    return "desconhecido";
}

const char* sexo_para_texto(sexoAnimal sexo){
    switch(sexo){
        case MACHO: return "macho";
        case FEMEA: return "femea";
    }

    return "desconhecido";
}

#endif