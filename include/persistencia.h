#ifndef PERSISTENCIAUTILS_H
#define PERSISTENCIAUTILS_H

#include "modelos.h"
#include <stdio.h>
#include <string>

void salvarAnimal(Animal *animal);
void lerAnimal();
void lerUnicoAnimal(Animal *animal);
void alterarAnimal(Animal *animal);
void deletaAnimal(Animal *animal);
void salvarUser(User *usuario);
void lerUsuario();
void alterarUsuario(User *usuario);
void buscarNomeUser(int id);
void deletaUsuario(User *usuario);

#endif